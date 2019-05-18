myavl: myavl.o AVLStruct.o
	gcc myavl.o AVLStruct.o -o myavl -Wall

myavl.o: myavl.c
	gcc -c myavl.c -Wall

AVLStruct.o: AVLStruct.c AVLStruct.h
	gcc -c AVLStruct.c -Wall
