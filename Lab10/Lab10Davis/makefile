main:main.o Emp.o Exec.o Hourly.o
		g++ -o main -std=c++11 main.o Emp.o Exec.o Hourly.o
main.o:main.cpp Emp.cpp Exec.cpp Hourly.cpp
		g++ -c main.cpp -std=c++11
Emp.o:main.cpp Emp.cpp Exec.cpp Hourly.cpp Emp.h Hourly.h Exec.h
		g++ -c Emp.cpp -std=c++11
Hourly.o:Hourly.cpp Hourly.h
		g++ -c Hourly.cpp -std=c++11
Exec.o:Exec.h Exec.cpp
		g++ -c Exec.cpp -std=c++11

clean:
		rm -f *.o main
