Main: Dictionary.o Main.o
	g++ Dictionary.o Main.o -o Main

Dictionary.o: Dictionary.cpp dictionary.h
	g++ -c Dictionary.cpp

Main.o: Main.cpp dictionary.h
	g++ -c Main.cpp

Clear: rm *.o
