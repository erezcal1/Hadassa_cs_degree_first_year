ex5a:  ex5a.o Stud.o Course.o 
	g++ ex5a.o Stud.o Course.o  -o ex5a 
	echo "A new multi files prog was created" 
main.o: ex5a.cc Stud.h Course.h 
	g++ -Wall -c main.cc
Stud.o: Stud.cc Stud.h 
	g++ -Wall -c Stud.cc 
Course.o: Course.cc Course.h
	g++ -Wall -c Course.cc 
	echo "I compiled Course.o"