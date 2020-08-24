
all: p1 p2 p3 p4 p5

p1: p1.o
	gcc -g -o p1 p1.o 

p1.o: p1.c
	gcc -g -c p1.c

p2: p2.o test_int.o
	gcc -g -o p2 p2.o test_int.o

p2.o: p2.c
	gcc -g -c p2.c

test_int.o: test_int.c
	gcc -g -c test_int.c

p3: p3.o
	gcc -g -o p3 p3.o 

p3.o: p3.c
	gcc -g -c p3.c

p4: p4.o
	gcc -g -o p4 p4.o 

p4.o: p4.c
	gcc -g -c p4.c

p5: p5.o
	gcc -g -o p5 p5.o 

p5.o: p5.c
	gcc -g -c p5.c

clean:
	rm *.o p1 p2 p3 p4 p5

# run p5 as:  date; p5 0; date 
# vs          date; p5 1; date
