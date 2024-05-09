CC := clang++

SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_IMAGE_CFLAGS := $(shell pkg-config --cflags SDL2_image)
SDL_TTF_CFLAGS := $(shell pkg-config --cflags SDL2_ttf)
CFLAGS ?= -Wall -Wextra -g -std=c++20 $(SDL_CFLAGS) $(SDL_IMAGE_CFLAGS) $(SDL_TTF_CFLAGS)

SDL_LDLIBS := $(shell sdl2-config --libs)
SDL_IMAGE_LDLIBS := $(shell pkg-config --libs SDL2_image)
SDL_TTF_LDLIBS := $(shell pkg-config --libs SDL2_ttf)
LDLIBS ?= -lm $(SDL_LDLIBS) $(SDL_IMAGE_LDLIBS) $(SDL_TTF_LDLIBS)

EXEC = breakout-game

INCLUDE_PATH ?= ./include
SRC_PATH = ./src
OBJ_PATH = ./obj
BIN_PATH = ./bin

SOURCES := $(filter-out $(SRC_PATH)/main.cpp, $(wildcard $(SRC_PATH)/*.cpp $(SRC_PATH)/*/*.cpp $(SRC_PATH)/*/*/*.cpp))
INCLUDES := $(wildcard $(INCLUDE_PATH)/*.hpp $(INCLUDE_PATH)/*/*.hpp $(INCLUDE_PATH)/*/*/*.hpp)
OBJECTS  := $(SOURCES:$(SRC_PATH)/%.cpp=$(OBJ_PATH)/%.o)

all:
	$(MAKE) $(BIN_PATH)/$(EXEC)

test: all
	$(MAKE) -C ./test

docs:
	mkdir -p ./docs
	doxygen Doxyfile

$(BIN_PATH)/$(EXEC): $(OBJ_PATH)/main.o $(OBJECTS)
	mkdir -p $(BIN_PATH)
	$(CC) -o $@ $^ $(CFLAGS) -I$(INCLUDE_PATH) $(LDLIBS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJ_PATH)/%.o : $(SRC_PATH)/%.cpp 
	mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDE_PATH) 

$(OBJ_PATH)/main.o: $(SRC_PATH)/main.cpp
	mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDE_PATH)


.PHONY: clean
clean:
	rm -fr $(OBJ_PATH)
	rm -fr $(BIN_PATH)