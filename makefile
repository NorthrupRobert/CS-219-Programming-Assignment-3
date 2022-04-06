exe: driver.o start.o hexoperations.o start.h hexoperations.h
	g++ driver.o start.o start.h hexoperations.h hexoperations.o -o exe

driver.o: driver.cpp
	g++ -c driver.cpp

start.o: start.cpp start.h
	g++ -c start.cpp start.h

hexoperations.o: hexoperations.cpp hexoperations.h
	g++ -c hexoperations.cpp hexoperations.h

clean:
	rm *.o *.gch exe