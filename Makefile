CXX = g++
CXXFLAGS = -Wall -g -std=c++17
INC = -Iinc/
LIB = -lboost_system -lboost_program_options
SOURCE = ./src/*
OUTPUT_DIR = ./target/
OUTPUT = $(OUTPUT_DIR)/LanScanner

all:
	mkdir -p $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(OUTPUT) $(INC) $(LIB)

clean:
	rm -rf target
