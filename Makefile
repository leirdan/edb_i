CC = g++
CFLAGS = -c -Wall -std=c++11
TARGET = app.exe
OUTPUT_DIR = bin
SRC_DIR = src
CPP_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OUTPUT_DIR)/%.o, $(CPP_FILES))

all: $(OUTPUT_DIR)/$(TARGET)

$(OUTPUT_DIR)/$(TARGET): $(OBJ_FILES)
	@if not exist $(OUTPUT_DIR) mkdir $(OUTPUT_DIR)
	$(CC) $(OBJ_FILES) -o $@

$(OUTPUT_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist $(OUTPUT_DIR) mkdir $(OUTPUT_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	@if exist $(OUTPUT_DIR) rmdir /s /q $(OUTPUT_DIR)

.PHONY: all clean