#define SDL_MAIN_USE_CALLBACKS 1 /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_Image/SDL_image.h>
#include <iostream>
#include "status/ElementOrientation.h"
#include "character/Character.h"

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

#define SPRITE_WIDTH 14
#define SPRITE_HEIGHT 16
#define NEXT_SPRITE_X 34
#define NEXT_SPRITE_Y 32
#define BASE_POSITION_IDLE 17
#define BASE_PLAYER_SPEED 80.0f

static float spriteYPosition(int playerOrientation);
static float spriteIndexIdleOrMovement();

bool idle = true;
float positionX = 100.0f;
float positionY = 100.0f;

SDL_Texture *characterSpriteSheet;
character::Character *player;

static bool keys[SDL_SCANCODE_COUNT] = {false};

/* Init */
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    SDL_SetAppMetadata("Example Renderer Points", "1.0", "com.example.renderer-points");

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("examples/renderer/points", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer))
    {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    player = new character::Character("assets/Sprout Lands - Sprites - premium pack/Characters/Basic Charakter Spritesheet.png", renderer, positionX, positionY);
    characterSpriteSheet = player->renderTexture();
    if (!characterSpriteSheet)
    {
        SDL_Log("Failed to load texture: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

/* Events */
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT)
    {
        return SDL_APP_SUCCESS;
    }

    if (event->type == SDL_EVENT_KEY_DOWN)
    {
        keys[event->key.scancode] = true;
        idle = false;
    }
    if (event->type == SDL_EVENT_KEY_UP)
    {
        keys[event->key.scancode] = false;
        idle = !(keys[SDL_SCANCODE_W] || keys[SDL_SCANCODE_A] ||
                 keys[SDL_SCANCODE_S] || keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_LSHIFT]);
    }

    return SDL_APP_CONTINUE;
}

/* Main loop */
SDL_AppResult SDL_AppIterate(void *appstate)
{
    static Uint64 last = 0;
    Uint64 now = SDL_GetTicks();

    SDL_RenderClear(renderer);

    SDL_SetTextureScaleMode(characterSpriteSheet, SDL_ScaleMode::SDL_SCALEMODE_NEAREST);

    SDL_FRect srcrect = {
        spriteIndexIdleOrMovement(),
        spriteYPosition(player->getOrientation()),
        SPRITE_WIDTH,
        SPRITE_HEIGHT};

    player->getPosition(positionX, positionY);

    SDL_FRect dstrect = {positionX, positionY, srcrect.w, srcrect.h};

    SDL_RenderTexture(renderer, characterSpriteSheet, &srcrect, &dstrect);
    SDL_FRect srcRect2 = {17.0f, 16.0f, SPRITE_WIDTH, SPRITE_HEIGHT};
    SDL_FRect dstRect2 = {300.0f, 200.0f, srcrect.w * 4, srcrect.h * 4};
    SDL_RenderTexture(renderer, characterSpriteSheet, &srcRect2, &dstRect2);

    float deltaTime = (last > 0) ? (now - last) / 1000.0f : 0.0f;
    last = now;
    if (deltaTime > 0.05f)
        deltaTime = 0.05f; // evitar warping

    float dx = 0.0f;
    float dy = 0.0f;

    if (keys[SDL_SCANCODE_W])
    {
        dy -= 1.0f;
        player->setOrientation(status::ElementOrientation::UP);
    }
    if (keys[SDL_SCANCODE_S])
    {
        dy += 1.0f;
        player->setOrientation(status::ElementOrientation::DOWN);
    }
    if (keys[SDL_SCANCODE_A])
    {
        dx -= 1.0f;
        player->setOrientation(status::ElementOrientation::LEFT);
    }
    if (keys[SDL_SCANCODE_D])
    {
        dx += 1.0f;
        player->setOrientation(status::ElementOrientation::RIGHT);
    }

    // normalizar para diagonales
    float length = SDL_sqrtf(dx * dx + dy * dy);
    if (length > 0.0f)
    {
        dx /= length;
        dy /= length;
    }

    SDL_FRect nextRectX = dstrect;
    nextRectX.x += dx * BASE_PLAYER_SPEED * deltaTime;

    if (!SDL_HasRectIntersectionFloat(&nextRectX, &dstRect2))
    {
        if (keys[SDL_SCANCODE_LSHIFT])
            player->run(dx * BASE_PLAYER_SPEED * deltaTime, 0.0f);
        else
            player->move(dx * BASE_PLAYER_SPEED * deltaTime, 0.0f);
    }

    SDL_FRect nextRectY = dstrect;
    nextRectY.y += dy * BASE_PLAYER_SPEED * deltaTime;

    if (!SDL_HasRectIntersectionFloat(&nextRectY, &dstRect2))
    {
        if (keys[SDL_SCANCODE_LSHIFT])
            player->run(0.0f, dy * BASE_PLAYER_SPEED * deltaTime);
        else
            player->move(0.0f, dy * BASE_PLAYER_SPEED * deltaTime);
    }

    SDL_RenderPresent(renderer);
    return SDL_APP_CONTINUE;
}

/* Animación */
static float spriteIndexIdleOrMovement()
{
    if (idle)
    {
        return ((SDL_GetTicks() / 1000) % 2) * (SPRITE_WIDTH + NEXT_SPRITE_X) + BASE_POSITION_IDLE;
    }
    else
    {
        int rawIndex = (SDL_GetTicks() / 200) % 4;
        int spriteIndex = (rawIndex < 2) ? rawIndex + 2 : rawIndex;
        return spriteIndex * (SPRITE_WIDTH + NEXT_SPRITE_X) + BASE_POSITION_IDLE;
    }
}

static float spriteYPosition(int playerOrientation)
{
    return 16.0f + ((NEXT_SPRITE_Y + SPRITE_HEIGHT) * playerOrientation);
}

/* Quit */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    if (characterSpriteSheet)
        SDL_DestroyTexture(characterSpriteSheet);
    if (player)
        delete player;
}
