CFLAGS = gcc -std=c99
CXX = g++
CXXFLAGS = -Wall -g

c: matrix.c
	$(CFLAGS) matrix.c -o cTest

cpp: matrix.cpp
	$(CXX) $(CXXFLAGS) matrix.cpp -o cppTest