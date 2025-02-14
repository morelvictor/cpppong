
SRC_DIR = src
BIN_DIR = .bin
CC = g++
FLAGS = -Wall -Wno-unused-command-line-argument -std=c++11 `sdl2-config --libs --cflags` -lSDL2_image -lSDL2_ttf
EXE = pong

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(addprefix $(BIN_DIR)/, $(SRC:.cpp=.o))

all: clean pong

$(EXE): $(OBJ) $(BIN_DIR) $(SRC_DIR)
	$(CC) $(OBJ) -o $(EXE) $(FLAGS)

$(BIN_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp $(BIN_DIR)
	$(CC) -c $< -o $@ $(FLAGS)

$(SRC_DIR):
	@mkdir -p $(SRC_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)/$(SRC_DIR)

.PHONY: clean run

run: all
	./pong

clean:
	rm -rf $(BIN_DIR)

