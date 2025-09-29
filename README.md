# 🎮 Top-Down 2D Framework with SDL3

This project is a **2D game framework in C++** built on **SDL3**.  
It is designed to serve as a starting point for **top-down view games** such as RPGs, action-adventures, or exploration games.

---

## ✨ Features

- **SDL3 Core**: Uses SDL3 callbacks (`SDL_AppInit`, `SDL_AppEvent`, `SDL_AppIterate`, `SDL_AppQuit`) instead of a traditional `main()`.
- **Rendering System**:
  - Generic `Renderable` class for managing textures.
  - Separation of rendering logic from gameplay logic.
- **Character System**:
  - `Character` class that extends `Renderable`.
  - Movement (walk/run) and basic actions (attack).
  - Supports animations (idle, movement).
- **Orientation Management**:
  - `ElementOrientation` enum (`UP`, `DOWN`, `LEFT`, `RIGHT`) for character direction.
- **Input Handling**:
  - Keyboard support (`WASD`) with diagonal movement normalization.
  - Idle state detection when no movement keys are pressed.
- **Collisions**:
  - Basic rectangle intersection check with `SDL_HasRectIntersectionFloat`.
- **Build System**:
  - Cross-platform build with `Makefile` (tested with **w64devkit** on Windows).
  - Integrated with **VSCode** (`tasks.json`, `launch.json`) for easy build/debug.


---

## 📂 Project Structure


```
.
├───.vscode
├───assets
│   └─── _whatever asset do you want_
└───src
    ├───character
    ├───include
    │   ├───SDL3-3.2.22
    │   │   ├───cmake
    │   │   ├───i686-w64-mingw32
    │   │   │   ├───bin
    │   │   │   ├───include
    │   │   │   │   └───SDL3
    │   │   │   ├───lib
    │   │   │   │   ├───cmake
    │   │   │   │   │   └───SDL3
    │   │   │   │   └───pkgconfig
    │   │   │   └───share
    │   │   │       └───licenses
    │   │   │           └───SDL3
    │   │   └───x86_64-w64-mingw32
    │   │       ├───bin
    │   │       ├───include
    │   │       │   └───SDL3
    │   │       ├───lib
    │   │       │   ├───cmake
    │   │       │   │   └───SDL3
    │   │       │   └───pkgconfig
    │   │       └───share
    │   │           └───licenses
    │   │               └───SDL3
    │   ├───SDL3_image-3.2.4
    │   │   ├───cmake
    │   │   ├───i686-w64-mingw32
    │   │   │   ├───bin
    │   │   │   ├───include
    │   │   │   │   └───SDL3_image
    │   │   │   ├───lib
    │   │   │   │   ├───cmake
    │   │   │   │   │   └───SDL3_image
    │   │   │   │   └───pkgconfig
    │   │   │   └───share
    │   │   │       └───licenses
    │   │   │           └───SDL3_image
    │   │   └───x86_64-w64-mingw32
    │   │       ├───bin
    │   │       ├───include
    │   │       │   └───SDL3_image
    │   │       ├───lib
    │   │       │   ├───cmake
    │   │       │   │   └───SDL3_image
    │   │       │   └───pkgconfig
    │   │       └───share
    │   │           └───licenses
    │   │               └───SDL3_image
    │   └───SDL3_ttf-3.2.2
    │       ├───cmake
    │       ├───i686-w64-mingw32
    │       │   ├───bin
    │       │   ├───include
    │       │   │   └───SDL3_ttf
    │       │   ├───lib
    │       │   │   ├───cmake
    │       │   │   │   └───SDL3_ttf
    │       │   │   └───pkgconfig
    │       │   └───share
    │       │       └───licenses
    │       │           └───SDL3_ttf
    │       └───x86_64-w64-mingw32
    │           ├───bin
    │           ├───include
    │           │   └───SDL3_ttf
    │           ├───lib
    │           │   ├───cmake
    │           │   │   └───SDL3_ttf
    │           │   └───pkgconfig
    │           └───share
    │               └───licenses
    │                   └───SDL3_ttf
    ├───renderable
    ├───status
    └───world
```

---

## 🕹️ Controls

- **W** → Move Up  
- **A** → Move Left  
- **S** → Move Down  
- **D** → Move Right  

✔ Smooth diagonal movement is supported.  
✔ The character switches between **idle** and **movement animations** depending on input.  
✔ Collision detection logs `"Colisión!"` when intersecting with another rectangle.

---

## ⚙️ Build & Run

### Requirements
- [SDL3](https://github.com/libsdl-org/SDL)
- [SDL3_image](https://github.com/libsdl-org/SDL_image)
- [SDL3_ttf](https://github.com/libsdl-org/SDL_ttf)
- [SDL3_mixer](https://github.com/libsdl-org/SDL_mixer)
- g++ (tested with **w64devkit** on Windows)

### Build with Makefile

```sh
make        # build the project
make clean  # clean binaries
````

### Run

```sh
./main.exe
```

---

## 🚀 Roadmap

* [ ] Add sprite-based attack animations.
* [ ] Implement multiple characters (NPCs, enemies).
* [ ] Tilemap rendering for levels.
* [ ] More advanced collision system (tile-based or physics).
* [ ] Audio with SDL3_mixer.

---

## 📜 License

This project is released under the **MIT License**.
You are free to use, modify, and distribute it.

---

