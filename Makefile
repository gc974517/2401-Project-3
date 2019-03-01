CFLAGS = -Wall -std=c++11 -g
CC = g++

main: car.o carlist.o carmain.o
	$(CC) $(CFLAGS) car.o carlist.o carmain.o -o carmain

car.o:
	$(CC) $(CFLAGS) -c car.cc

carlist.o:
	$(CC) $(CFLAGS) -c carlist.cc

carmain.o:
	$(CC) $(CFLAGS) -c carmain.cc

clean:
	rm -f *.o carmain
