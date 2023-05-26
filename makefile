CC = g++
FLEX = flex
BISON = bison
CFLAGS = -Wall
FLEX_BISON_CFLAGS = -Wall -Wno-unused-function -Wno-write-strings -Wno-class-memaccess -Wno-unused-value -Wno-unused-label

SOURCE_DIR = src
BUILD_DIR = build
DEBUG_DIR = debug

TARGET_FILE = compiler.exe
SRC_FILES = compiler.cpp color.cpp common.cpp log.cpp shell.cpp lexer.cpp parser.cpp
OTHER_FILES = compiler.h color.h common.h log.h shell.h lexer.h parser.h

TARGET = $(BUILD_DIR)/$(TARGET_FILE)
SRCS = $(addprefix $(SOURCE_DIR)/, $(SRC_FILES))
OTHERS = $(addprefix $(SOURCE_DIR)/, $(OTHER_FILES))
OBJS = $(addprefix $(BUILD_DIR)/, $(SRC_FILES:.cpp=.o))


FLEX_FILE_NAME = compiler.l
BISON_FILE_NAME = compiler.y
FLEX_FILE = $(SOURCE_DIR)/$(FLEX_FILE_NAME)
BISON_FILE = $(SOURCE_DIR)/$(BISON_FILE_NAME)

FLEX_GEN_NAME = compiler_flex
BISON_GEN_NAME = compiler_bison
FLEX_GEN_HEAD = $(BUILD_DIR)/$(FLEX_GEN_NAME).h
BISON_GEN_HEAD =  $(BUILD_DIR)/$(BISON_GEN_NAME).h
FLEX_GEN_CPP = $(BUILD_DIR)/$(FLEX_GEN_NAME).cpp
BISON_GEN_CPP =  $(BUILD_DIR)/$(BISON_GEN_NAME).cpp
FLEX_BISON_REQUIRES = $(FLEX_GEN_HEAD) $(FLEX_GEN_CPP) $(BISON_GEN_HEAD) $(BISON_GEN_CPP)
FLEX_BISON_OBJS = $(BUILD_DIR)/$(FLEX_GEN_NAME).o $(BUILD_DIR)/$(BISON_GEN_NAME).o


.PHONY: building clean

building: $(DEBUG_DIR) $(BUILD_DIR) $(FLEX_BISON_REQUIRES) $(TARGET)

$(FLEX_GEN_HEAD): $(FLEX_GEN_CPP)
$(FLEX_GEN_CPP): $(FLEX_FILE)
	$(FLEX) -o $(FLEX_GEN_CPP) --header-file=$(FLEX_GEN_HEAD) $(FLEX_FILE)

$(BISON_GEN_HEAD): $(BISON_GEN_CPP)
$(BISON_GEN_CPP): $(BISON_FILE)
	$(BISON) -d -o $(BISON_GEN_CPP) --defines=$(BISON_GEN_HEAD) $(BISON_FILE) -v

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(DEBUG_DIR):
	mkdir -p $(DEBUG_DIR)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp $(OTHERS)
	$(CC) -c $< -o $@ $(CFLAGS)

$(BUILD_DIR)/%.o: $(BUILD_DIR)/%.cpp $(OTHERS)
	$(CC) -c $< -o $@ $(FLEX_BISON_CFLAGS)

$(TARGET): $(OBJS) $(FLEX_BISON_OBJS)
	$(CC) $^ -o $@ $(CFLAGS)

clean:
	rm -rf $(BUILD_DIR)