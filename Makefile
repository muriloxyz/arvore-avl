#Compila
myavl: myavl.o AVLStruct.o
	gcc myavl.o AVLStruct.o -o myavl -Wall

# Gera "a.out" para uso no gdb
debug: myavl.o AVLStruct.o
	gcc myavl.o AVLStruct.o -g -Wall

# Remove os arquivos .o
clean:
	rm *.o

#Remove os executaveis e arquivos .o
purge:
	rm -f myavl *.o a.out

myavl.o: myavl.c
	gcc -c myavl.c -Wall

AVLStruct.o: AVLStruct.c AVLStruct.h
	gcc -c AVLStruct.c -Wall
