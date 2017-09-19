ReversePolishNotation.exe	:	ReversePolishNotation.o
	g++ ReversePolishNotation.o -std=c++11 -o ReversePolishNotation.exe

ReversePolishNotation.o	:	ReversePolishNotation.cpp ReversePolishNotation.h
	g++ -std=c++11 -c ReversePolishNotation.cpp
	