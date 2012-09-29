BUILD = ../build
CPP = g++
CPPFLAGS = -Wall -Wextra
TTEST = TimingTests
STL = ListQueue
LL = LinkedListQueue
ARR = AQueue

all: $(BUILD)/STLtime $(BUILD)/LLtime $(BUILD)/Atime

$(BUILD)/STLtime: $(TTEST)/queue_tester.cpp $(STL)/Queue.o
	$(CPP) $(CPPFLAGS) -o $(BUILD)/STLtime $(TTEST)/queue_tester.cpp $(STL)/Queue.o

$(STL)/Queue.o: $(STL)/Queue.h $(STL)/Queue.cpp
	cd $(STL); $(MAKE)

$(BUILD)/LLtime: $(TTEST)/queue_tester.cpp $(LL)/Queue.o $(LL)/Node.o
	$(CPP) $(CPPFLAGS) -o $(BUILD)/LLtime $(TTEST)/queue_tester.cpp $(LL)/Queue.o $(LL)/Node.o

$(LL)/Queue.o: $(LL)/Queue.h $(LL)/Queue.cpp $(LL)/Node.o
	cd $(LL); $(MAKE)

$(LL)/Node.o: $(LL)/Node.cpp $(LL)/Node.h
	cd $(LL); $(MAKE)

$(BUILD)/Atime: $(TTEST)/queue_tester.cpp $(ARR)/Queue.o
	$(CPP) $(CPPFLAGS) -o $(BUILD)/Atime $(TTEST)/queue_tester.cpp $(ARR)/Queue.o

$(ARR)/Queue.o: $(ARR)/Queue.h $(ARR)/Queue.cpp
	cd $(ARR); $(MAKE)

clean:
	rm -f *.o
	rm -f *~
	rm -f $(BUILD)/Atime $(BUILD)/LLtime $(BUILD)/STLtime
	cd $(STL); $(MAKE) clean
	cd $(LL); $(MAKE) clean
	cd $(ARR); $(MAKE) clean

