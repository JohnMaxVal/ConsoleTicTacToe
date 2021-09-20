PG_NAME=tictactoe

CC=g++
C_FLAGS = -std=c++17

DEBUG_FLAG = -g

INCLUDES = -I./include/
SRC = ./src/*cpp

all:
	$(CC) $(DEBUG_FLAG) $(C_FLAGS) $(INCLUDES) $(SRC) main.cpp -o ${PG_NAME}