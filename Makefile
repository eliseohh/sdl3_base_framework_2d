CXX = g++
CXXFLAGS = -std=c++17 -Wall -Isrc
CXXFLAGS += -Isrc/include/SDL3-3.2.22/x86_64-w64-mingw32/include
CXXFLAGS += -Isrc/include/SDL3_image-3.2.4/x86_64-w64-mingw32/include
CXXFLAGS += -Isrc/include/SDL3_ttf-3.2.2/x86_64-w64-mingw32/include
CXXFLAGS += -Isrc/include/SDL3_mixer-3.2.2/x86_64-w64-mingw32/include

LDFLAGS = -mconsole
LDFLAGS += -Lsrc/include/SDL3-3.2.22/x86_64-w64-mingw32/lib
LDFLAGS += -Lsrc/include/SDL3_image-3.2.4/x86_64-w64-mingw32/lib
LDFLAGS += -Lsrc/include/SDL3_ttf-3.2.2/x86_64-w64-mingw32/lib
LDFLAGS += -Lsrc/include/SDL3_mixer-3.2.2/x86_64-w64-mingw32/lib

LDLIBS = -lSDL3 -lSDL3_image -lSDL3_ttf

# 🔹 Incluye main.cpp también
SRC = main.cpp $(wildcard src/*.cpp src/*/*.cpp)
OBJ = $(SRC:.cpp=.o)

TARGET = main.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS) $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
