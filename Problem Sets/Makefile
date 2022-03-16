################################################################################
# Makefile for general code snippets
#
# by André Pereira
################################################################################

BIN_NAME = main

CXX = gcc
LD  = gcc

CXXFLAGS   = -O2 -std=c99 -Wall -ggdb

SRC_DIR = src
BIN_DIR = bin
BUILD_DIR = build
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst src/%.c,build/%.o,$(SRC))
BIN = $(BIN_NAME)

vpath %.c $(SRC_DIR)

################################################################################
# Rules
################################################################################

.DEFAULT_GOAL = all

$(BUILD_DIR)/%.o: %.c
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(BIN_DIR)/$(BIN_NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

checkdirs:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BIN_DIR)

all: checkdirs $(BIN_DIR)/$(BIN_NAME)

clean:
	rm -f $(BUILD_DIR)/* $(BIN_DIR)/*