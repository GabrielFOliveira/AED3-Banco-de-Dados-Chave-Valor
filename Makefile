CC=gcc
CFLAGS=-I.


mainmake: main.c
  $(CC) -o simpledb main.c
