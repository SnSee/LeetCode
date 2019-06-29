src = $(wildcard ./*.c)
target = $(patsubst %.c, %, $(src))
CC = gcc -g -fsanitize=address
IPath = -I /Users/tugame/c/LeetCode/util/includes
LPath = -L/Users/tugame/c/LeetCode/util/src
lName = -lqueue
FLAGS = -o
                                                                                                                                                      
all:$(target)

%:%.c
	$(CC) -fPIC -shared $< $(IPath) $(LPath) $(lName) $(FLAGS) $@

clean:$(target)
	rm $^

.PHONY= all, clean

