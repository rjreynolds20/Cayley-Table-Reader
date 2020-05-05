driver: driver.o cayley.o
	g++ driver.o cayley.o -o driver

driver.o: driver.cc cayley.h
	g++ -c driver.cc

cayley.o: cayley.cc cayley.h
	g++ -c cayley.cc

clean:
	rm*.o run

run: driver
	./driver
