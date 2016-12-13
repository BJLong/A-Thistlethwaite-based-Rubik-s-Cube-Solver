all: genlist interpreter

genlist: genlist.o Project.o
	g++ -o genlist genlist.o Project.o

genlist.o: genlist.cc cube.h
	g++ -c genlist.cc

Project.o: Project.cc cube.h
	g++ -c Project.cc

interpreter: Project.o Interpreter.o
	g++ -o interpreter Project.o Interpreter.o

Interpreter.o: Interpreter.cc cube.h
	g++ -c Interpreter.cc

