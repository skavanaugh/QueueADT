CPP = g++
CPPFLAGS = -Wall -Wextra

Queue.o: Queue.h Queue.cpp Node.o
	$(CPP) $(CPPFLAGS) -c Queue.cpp

Node.o: Node.h Node.cpp
	$(CPP) $(CPPFLAGS) -c Node.cpp
clean:
	rm -f *.o
	rm -f *~
