# Makefile for resource_lab
CC = gcc
CFLAGS = -O2 -pthread -Wall -Wextra -Wconversion -Wshadow -Wformat=2 -pipe
LDFLAGS = -pthread
TARGET = resource_lab
SRC = resource_lab.c

.PHONY: all run clean debug

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

debug: CFLAGS += -g -O0
debug: clean all

clean:
	rm -f $(TARGET)
