CXX = g++
CXXFLAGS = -Wall -g -std=c++17
INC = -Iinc/
SOURCE = ./src/*
OUTPUT_DIR = ./target/
OUTPUT = $(OUTPUT_DIR)/LanScanner

all:
	mkdir -p $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(OUTPUT) $(INC)

clean:
	rm -rf target
