# [!IMPORTANT] To be only run on Ubuntu and Windows OS. For MacOS, change .app to .run.

all: compile
compile: Assn2.o Cross.o Circle.o userInputData.o Rectangle.o ShapeTwoD.o Square.o algorithms.o
	g++ -std=c++11 Assn2.cpp Cross.cpp Circle.cpp userInputData.cpp Rectangle.cpp ShapeTwoD.cpp Square.cpp algorithms.cpp -o csci251_a2.app
		./csci251_a2.app
Assn2.o: Assn2.cpp
	g++ -std=c++11 -c Assn2.cpp
algorithms.o: algorithms.cpp algorithms.h
	g++ -std=c++11 -c algorithms.cpp
Cross.o: Cross.cpp Cross.h
	g++ -std=c++11 -c Cross.cpp
Circle.o: Circle.cpp Circle.h
	g++ -std=c++11 -c Circle.cpp
userInputData.o: userInputData.cpp userInputData.h
	g++ -std=c++11 -c userInputData.cpp
Rectangle.o: Rectangle.cpp Rectangle.h
	g++ -std=c++11 -c Rectangle.cpp
Square.o: Square.cpp Square.h
	g++ -std=c++11 -c Square.cpp
ShapeTwoD.o: ShapeTwoD.cpp ShapeTwoD.h
	g++ -std=c++11 -c ShapeTwoD.cpp


# Removes all object files:
clean:
	rm *.o