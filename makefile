CC = g++
FLEX = flex
BISON = bison
CFLAGS = -Wall
FLEX_BISON_CFLAGS = $(CFLAGS) -Wno-unused-function -Wno-write-strings -Wno-class-memaccess -Wno-unused-value -Wno-unused-label

SOURCE_DIR = src
BUILD_DIR = build
TARGET_FILE = compiler.exe

SRCS = $(wildcard $(addprefix $(SOURCE_DIR)/, *.cpp))
SRC_FILES = $(notdir $(SRCS))
OBJS = $(addprefix $(BUILD_DIR)/, $(SRC_FILES:.cpp=.o))
TARGET = $(BUILD_DIR)/$(TARGET_FILE)

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



.PHONY: building help test show clean sample clean-sample

building: $(BUILD_DIR) $(FLEX_BISON_REQUIRES) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(FLEX_GEN_HEAD): $(FLEX_GEN_CPP)
$(FLEX_GEN_CPP): $(FLEX_FILE)
	$(FLEX) -o $(FLEX_GEN_CPP) --header-file=$(FLEX_GEN_HEAD) $(FLEX_FILE)

$(BISON_GEN_HEAD): $(BISON_GEN_CPP)
$(BISON_GEN_CPP): $(BISON_FILE)
	$(BISON) -d -o $(BISON_GEN_CPP) --defines=$(BISON_GEN_HEAD) $(BISON_FILE) -v

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

clean:
	rm -rf $(BUILD_DIR)



DEBUG_DIR = debug
SAMPLE_DIR = testsample/right
SAMPLE_FILES = $(notdir $(wildcard $(addprefix $(SAMPLE_DIR)/, *.py)))

$(DEBUG_DIR):
	mkdir -p $(DEBUG_DIR)

sample: $(DEBUG_DIR)
	@for f in $(SAMPLE_FILES); do \
	# echo $(TARGET) $(SAMPLE_DIR)/$$f -t -dast $(DEBUG_DIR)/$$f.txt -S --out $(DEBUG_DIR)/$$f.s; \
	$(TARGET) $(SAMPLE_DIR)/$$f -t -dast $(DEBUG_DIR)/$$f.txt -S --out $(DEBUG_DIR)/$$f.s; \
	echo; \
	done

clean-sample:
	rm -rf $(DEBUG_DIR)