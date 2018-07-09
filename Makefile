TARGET = tic-tac-toe
INCLUDE = ./include/
SOURCE = ./source/*
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

.PHONY: all clean fclean re

$(TARGET):
	@$(CC) $(CFLAGS) $(SOURCE) -I $(INCLUDE) -o $(TARGET)

all: $(TARGET)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(TARGET)
	@rm -f a.out

re: fclean all
