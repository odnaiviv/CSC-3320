#makefile that executes the main program that includes all the functions

question5: question5.o problem5char.o problem5words.o problem5lines.o
	gcc -o question5 question5.o problem5char.o problem5words.o problem5lines.o

question5.o: question5.o problem5char.o problem5words.o problem5lines.o
	gcc -c question5.c problem5char.c problem5words.c problem5lines.c

#adding library header files to function files
problem5char.o: problem5char.c
	gcc -c problem5char.c problem5char.h

problem5words.o: problem5words.c
	gcc -c problem5words.c problem5words.h

problem5lines.o: problem5lines.c
	gcc -c problem5lines.c problem5lines.h
