C=g++
CFLAG=-c

all: main.o function1.o function2.o
	$(C) main.o function1.o function2.o -o hello

main.o: main.cpp
	$(C) $(CFLAG) main.cpp

function1.o: function1.cpp
	$(C) $(CFLAG) function1.cpp

function2.o: function2.cpp
	$(C) $(CFLAG) function2.cpp

clean:
	rm -rf *o hello
