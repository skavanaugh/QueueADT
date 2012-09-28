BUILD = ../../build
CPP = g++
CPPFLAGS = -Wall -Wextra

Amain: queue_tester.cpp Queue.o
	$(CPP) $(CPPFLAGS) -o $(BUILD)/Amain queue_tester.cpp Queue.o

Queue.o: Queue.h Queue.cpp 
	$(CPP) $(CPPFLAGS) -c Queue.cpp

clean:
	rm -f *.o
	rm -f *~
	rm -f $(BUILD)/main
