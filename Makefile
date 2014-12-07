main: main.o ParseData.o ParseField.o ParseList.o word.o 
	g++ -o main main.o ParseData.o ParseField.o ParseList.o word.o 

main.o: main.cpp
	g++ -c main.cpp

ParseData.o: ParseData.cpp
	g++ -c ParseData.cpp

ParseField.o: ParseField.cpp
	g++ -c ParseField.cpp

ParseList.o: ParseList.cpp
	g++ -c ParseList.cpp

word.o: word.cpp
	g++ -c word.cpp

clean:
	rm -f *.o main output.txt


