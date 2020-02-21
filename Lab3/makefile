main: main.o payroll.o payroll.h Listpayroll.o Listpayroll.h
	g++ Listpayroll.o payroll.o main.o -std=c++11 -o main -g

main.o: main.cpp  payroll.h
	g++ -c  main.cpp -std=c++11 -g

payroll.o: payroll.cpp payroll.h
	g++ -c  payroll.cpp -std=c++11 -g

Listpayroll.o: Listpayroll.cpp Listpayroll.h
	g++ -c Listpayroll.cpp -std=c++11 -g

clean:
	rm -f main.o main
