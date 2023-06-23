CC = g++
FLEX = flex
BISON = bison

CFLAGS = -Wall
BISON_FLAGS = -d -v -Wno-other
FLEX_BISON_CFLAGS = $(CFLAGS) -Wno-unused-function -Wno-write-strings

# xxx/  abc_DIR     xxx/ xxx/  abc_DIRS
# xxx.c  abc_FILE   xxx.c xxx.c  abc_FILES
# xxx  abc_NAME     xxx xxx abc_NAMES
# xxx/xxx.c  abc    xxx/xxx.c xxx/xxx.c  abcS   (file var without _DIR(S) / _FILE(S) / _NAME(S) is always a path)

SOURCE_DIR = src
FLEX_BISON_SRC_DIR = src-gen
BUILD_DIR = build
DEBUG_DIR = debug
TARGET_FILE = compiler.exe
FLEX_FILE = lexer.l
BISON_FILE = parser.y
FLEX_GEN_NAME = compiler_flex
BISON_GEN_NAME = compiler_bison



SRCS = $(wildcard $(addprefix $(SOURCE_DIR)/, *.cpp))
SRC_FILES = $(notdir $(SRCS))
OBJS = $(addprefix $(BUILD_DIR)/, $(SRC_FILES:.cpp=.o))
TARGET = $(BUILD_DIR)/$(TARGET_FILE)

FLEX_SRC = $(SOURCE_DIR)/$(FLEX_FILE)
BISON_SRC = $(SOURCE_DIR)/$(BISON_FILE)

FLEX_GEN_CPP = $(FLEX_BISON_SRC_DIR)/$(FLEX_GEN_NAME).cpp
BISON_GEN_CPP =  $(FLEX_BISON_SRC_DIR)/$(BISON_GEN_NAME).cpp
FLEX_OBJ =  $(BUILD_DIR)/$(FLEX_GEN_NAME).o
BISON_OBJ =  $(BUILD_DIR)/$(BISON_GEN_NAME).o
FLEX_BISON_REQUIRES = $(FLEX_GEN_CPP) $(BISON_GEN_CPP)
FLEX_BISON_OBJS = $(FLEX_OBJ) $(BISON_OBJ)



.PHONY: building help test show clean sample clean-sample

building: $(BUILD_DIR) $(FLEX_BISON_REQUIRES) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(DEBUG_DIR):
	mkdir -p $(DEBUG_DIR)

$(FLEX_GEN_CPP): $(FLEX_SRC)
	$(FLEX) -o $(FLEX_GEN_CPP) --header-file=$(FLEX_GEN_CPP:.cpp=.h) $(FLEX_SRC)

$(BISON_GEN_CPP): $(BISON_SRC)
	$(BISON) -o $(BISON_GEN_CPP) --defines=$(BISON_GEN_CPP:.cpp=.h) $(BISON_SRC) $(BISON_FLAGS)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

$(BUILD_DIR)/%.o: $(FLEX_BISON_SRC_DIR)/%.cpp
	$(CC) -c $< -o $@ $(FLEX_BISON_CFLAGS)

$(TARGET): $(OBJS) $(FLEX_BISON_OBJS)
	$(CC) $^ -o $@ $(CFLAGS)

help: building
	$(TARGET) --help

test: building $(DEBUG_DIR)
	$(TARGET) test.py --assembly --out $(DEBUG_DIR)/out.asm --time

show: building $(DEBUG_DIR)
	$(TARGET) test.py --assembly --out $(DEBUG_DIR)/out.asm --time --show

clean:
	rm -rf $(BUILD_DIR)



SAMPLE_DIR = testsample/right
SAMPLE_FILES = $(notdir $(wildcard $(addprefix $(SAMPLE_DIR)/, *.py)))

sample: building $(DEBUG_DIR)
	@for f in $(SAMPLE_FILES); do \
	echo $(TARGET) $(SAMPLE_DIR)/$$f -t -dast $(DEBUG_DIR)/$$f.txt -S -o $(DEBUG_DIR)/$$f.s; \
	$(TARGET) $(SAMPLE_DIR)/$$f -t -dast $(DEBUG_DIR)/$$f.txt -S -o $(DEBUG_DIR)/$$f.s; \
	echo; \
	done

clean-sample:
	rm -rf $(DEBUG_DIR)