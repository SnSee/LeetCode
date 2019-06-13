src = $(wildcard ./*.c)
target = $(patsubst %.c, %, $(src))
CC = gcc -g -fsanitize=address
FLAGS = -o
                                                                                                                                                      
all:$(target)

%:%.c
	$(CC) $< $(FLAGS) $@

clean:$(target)
	rm $^

.PHONY= all, clean

