CC = gcc
CFLAGS = -Wall
LDLIBS="-lcs50"

TARGET = scrabble

.PHONY: all clean

all: $(TARGET)

$(TARGET): scrabble.c
	$(CC) $(CFLAGS) -o $@ $(LDLIBS)	$^ && ./$@

clean:
	rm -f $(TARGET)