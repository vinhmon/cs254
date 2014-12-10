main: main.o ParseData.o ParseField.o ParseList.o word.o 
	g++ -std=c++11 -o main main.o ParseData.o ParseField.o ParseList.o word.o 

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

ParseData.o: ParseData.cpp
	g++ -std=c++11 -c ParseData.cpp

ParseField.o: ParseField.cpp
	g++ -std=c++11 -c ParseField.cpp

ParseList.o: ParseList.cpp
	g++ -std=c++11 -c ParseList.cpp

word.o: word.cpp
	g++ -std=c++11 -c word.cpp

clean:
	rm -f *.o main output.txt


