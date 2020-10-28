# Makefile for lab5
CC=gcc
CFLAGS = -Wall -g 
GOAL = fork

all: $(GOAL)

shellex: shellex.c csapp.c
	gcc -o shellex shellex.c csapp.c -lpthread

mysignal: mysignal.c csapp.c
	gcc -o mysignal mysignal.c csapp.c -lpthread

clean: 
	rm -f $(GOAL) *.o
