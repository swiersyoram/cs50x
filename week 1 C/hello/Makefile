CC = gcc
CFLAGS = -Wall
LDLIBS="-lcs50"

TARGET = hello

.PHONY: all clean

all: $(TARGET)

$(TARGET): hello.c
	$(CC) $(CFLAGS) -o $@ $(LDLIBS)	$^ && ./$@

clean:
	rm -f $(TARGET)