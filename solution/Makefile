all: solution

solution: main.o
	g++ -std=c++11 -O3 main.o -o solution

main.o: main.cpp
	g++ -std=c++11 -O3 -c main.cpp

clean:
	rm -rf *.o solution
