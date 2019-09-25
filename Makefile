TARGET=main

SOURCES=$(wildcard *.c)

OBJS=$(SOURCES:.c=.o)

INC_FLAGS=-I../include
CC=gcc
CFLAGS=-pedantic -c -Wall -Werror -Wconversion -ansi  -g -D _DEBUG=m $(INC_FLAGS)
CXXFLAGS= $(CFLAGS)
LDFLAGS=-g

.PHONY: clean run gdb valgrind

$(TARGET): $(OBJS)

include .depends

.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)

valgrind: 
	valgrind --leak-check=full ./$(TARGET)



