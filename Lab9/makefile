output: main.o payRoll.o
	g++ -std=c++11 main.o payRoll.o -o main

main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp

payRoll.o: payroll.h payRoll.cpp
	g++ -c -g -std=c++ payRoll.cpp

clean:
	rm -f *.o main
