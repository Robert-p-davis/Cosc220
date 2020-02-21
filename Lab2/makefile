main: main.o payroll.o payroll.h
	g++  main.o payroll.o -o main -g

main.o: main.cpp payroll.h
	g++ -std=c++11 -c main.cpp -g

payroll.o: payroll.cpp payroll.h
	g++ -std=c++11 -c payroll.cpp -g

clean: 
	rm *.o main
