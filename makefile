CC = g++
FLEX = flex
BISON = bison
CFLAGS = -Wall
FLEX_BISON_CFLAGS = $(CFLAGS) -Wno-unused-function -Wno-write-strings -Wno-class-memaccess -Wno-unused-value -Wno-unused-label

SOURCE_DIR = src
BUILD_DIR = build
DEBUG_DIR = debug

TARGET_FILE = compiler.exe
SRC_FILES = compiler.cpp common.cpp log.cpp shell.cpp lexer.cpp parser.cpp symbol.cpp

TARGET = $(BUILD_DIR)/$(TARGET_FILE)
SRCS = $(addprefix $(SOURCE_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(BUILD_DIR)/, $(SRC_FILES:.cpp=.o))


FLEX_FILE_NAME = lexer.l
BISON_FILE_NAME = parser.y
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


.PHONY: building help test show alltest clean clean-debug

building: $(BUILD_DIR) $(FLEX_BISON_REQUIRES) $(TARGET)

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

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp $(SOURCE_DIR)/%.h
	$(CC) -c $< -o $@ $(CFLAGS)

$(BUILD_DIR)/%.o: $(BUILD_DIR)/%.cpp
	$(CC) -c $< -o $@ $(FLEX_BISON_CFLAGS)

$(TARGET): $(OBJS) $(FLEX_BISON_OBJS)
	$(CC) $^ -o $@ $(CFLAGS)

help:
	$(TARGET) --help

test:
	$(TARGET) test.py --time

show:
	$(TARGET) test.py --time --show

alltest: $(DEBUG_DIR)
	$(TARGET) test.py --time -dshell $(DEBUG_DIR)/1_shell.txt
	$(TARGET) test.py --time -dlex $(DEBUG_DIR)/2_lex.txt
	$(TARGET) test.py --time -dparse $(DEBUG_DIR)/3_parse.txt
	$(TARGET) test.py --time -dast $(DEBUG_DIR)/4_ast.txt
	$(TARGET) test.py --time -dsym $(DEBUG_DIR)/5_sym.txt
	$(TARGET) test.py --time -dir $(DEBUG_DIR)/6_ir.txt
	$(TARGET) test.py --time -dcfg $(DEBUG_DIR)/7_cfg.txt
	$(TARGET) test.py --time -dasm $(DEBUG_DIR)/8_asm.txt
	$(TARGET) test.py --time -S

clean:
	rm -rf $(BUILD_DIR)

clean-debug:
	rm -rf $(DEBUG_DIR)