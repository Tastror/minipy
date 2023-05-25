CC = g++
CFLAGS = -Wall

SOURCE_DIR = src
BUILD_DIR = build

TARGET_FILE = compiler.exe
SRC_FILES = compiler.cpp
OTHER_FILES = compiler.h shell.hpp lexer.h parser.h

TARGET = $(BUILD_DIR)/$(TARGET_FILE)
SRCS = $(addprefix $(SOURCE_DIR)/, $(SRC_FILES))
OTHERS = $(addprefix $(SOURCE_DIR)/, $(OTHER_FILES))
OBJS = $(addprefix $(BUILD_DIR)/, $(SRC_FILES:.cpp=.o))

build: $(TARGET)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp $(OTHERS)
	$(CC) -c $< -o $@ $(CFLAGS)

$(TARGET): $(OBJS)
	g++ $^ -o $@

clean:
	rm -rf $(TARGET) $(OBJS)