CC = g++
CFLAGS = -g -Wall -I./ -L./

src = $(wildcard *.cc)
target = main.exe

.PHONY: all clean

${target} : ${src}
	$(CC) ${CFLAGS} $^ -o $@

all: ${target}

clean:
	rm ${target}
#del ${target}

