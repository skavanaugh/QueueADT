BUILD = ../../build
CPP = g++
CPPFLAGS = -Wall -Wextra

Lmain: queue_tester.cpp Queue.o
	$(CPP) $(CPPFLAGS) -o $(BUILD)/Lmain queue_tester.cpp Queue.o Node.o

Queue.o: Queue.h Queue.cpp Node.o
	$(CPP) $(CPPFLAGS) -c Queue.cpp

Node.o: Node.h Node.cpp
	$(CPP) $(CPPFLAGS) -c Node.cpp
clean:
	rm -f *.o
	rm -f *~
	rm -f $(BUILD)/main
