CC = g++
CFLAGS = -g -Wall 

src = $(wildcard *.cc)
target = $(patsubst %.cc, %.exe, ${src})

.PHONY: all clean

%.exe:%.cc
	$(CC) ${CFLAGS} $^ -o $@

all: ${target}

clean:
	rm ${target}

