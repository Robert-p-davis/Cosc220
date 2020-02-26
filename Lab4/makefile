main: main.o payroll.o payroll.h PayRollList.o PayRollList.h
	g++ PayRollList.o payroll.o main.o -std=c++11 -o main -g

main.o: main.cpp  payroll.h
	g++ -c  main.cpp -std=c++11 -g

payroll.o: payroll.cpp payroll.h
	g++ -c  payroll.cpp -std=c++11 -g

PayRollList.o: PayRollList.cpp PayRollList.h
	g++ -c PayRollList.cpp -std=c++11 -g

clean:
	rm -f main.o main
