myavl: myavl.o AVLStruct.o
#Compila
	gcc myavl.o AVLStruct.o -o myavl -Wall

debug: myavl.o AVLStruct.o
	gcc myavl.o AVLStruct.o -g -Wall

clean:
#Remove Arquivos Objeto
	rm *.o

purge:
#Remove tudo o que nao for uma source file
	rm -f myavl *.o a.out

myavl.o: myavl.c
	gcc -c myavl.c -Wall

AVLStruct.o: AVLStruct.c AVLStruct.h
	gcc -c AVLStruct.c -Wall
