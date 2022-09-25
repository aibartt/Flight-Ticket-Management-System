MyProject: main.o flighthashtable.o flightticket.o MyVector.o
	  g++ main.o flighthashtable.o flightticket.o MyVector.o

main.o: main.cpp
	g++ -c main.cpp

flighthashtable.o: flighthashtable.cpp flighthashtable.h
	g++ -c flighthashtable.cpp

flightticket.o: flightticket.cpp flightticket.h
	g++ -c flightticket.cpp

MyVector.o: MyVector.cpp MyVector.h
	g++ -c MyVector.cpp

clean :
	rm MyProject *.o 