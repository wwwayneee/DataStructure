main: main.o Multiply.o CreateMatrix.o SetDimension.o Add.o Sub.o CheckDimension.o ChooseALUop.o SetOriginalMatrixSign.o SetOriginalMatrixUnsigned.o OutPut.o Atoi.o CreateList.o
	gcc -std=c11 main.o Multiply.o CreateMatrix.o SetDimension.o Add.o Sub.o CheckDimension.o ChooseALUop.o SetOriginalMatrixSign.o SetOriginalMatrixUnsigned.o OutPut.o Atoi.o CreateList.o -o main

main.o: main.c
	gcc -std=c11 main.c -o main.o

Multiply.o: Multiply.c
	gcc -std=c11 Multiply.c -o Multiply.o

CreateMatrix.o: CreateMatrix.c
	gcc -std=c11 CreateMatrix.c -o CreateMatrix.o

SetDimension.o: SetDimension.c
	gcc -std=c11 SetDimension.c -o SetDimension.o

Add.o: Add.c
	gcc -std=c11 Add.c -o Add.o

Sub.o: Sub.c
	gcc -std=c11 Sub.c -o Sub.o

CheckDimension.o: CheckDimension.c
	gcc -std=c11 CheckDimension.c -o CheckDimension.o

ChooseALUop.o: ChooseALUop.c
	gcc -std=c11 ChooseALUop.c -o ChooseALUop.o

SetOriginalMatrixSign.o: SetOriginalMatrixSign.c
	gcc -std=c11 SetOriginalMatrixSign.c -o SetOriginalMatrixSign.o

SetOriginalMatrixUnsigned.o: SetOriginalMatrixUnsigned.c
	gcc -std=c11 SetOriginalMatrixUnsigned.c -o SetOriginalMatrixUnsigned.o

OutPut.o: OutPut.c
	gcc -std=c11 OutPut.c -o OutPut.o

Atoi.o: Atoi.c
	gcc -std=c11 Atoi.c -o Atoi.o

CreateList.o: CreateList.c
	gcc -std=c11 CreateList.c -o CreateList.o

.PHONY: clean
clean:
	rm -rf *.o