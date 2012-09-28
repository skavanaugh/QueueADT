BUILD = ../build
TEST = ../test
LIB = ../lib
SRC = ../src
GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a

GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

CPP = g++
CPPFLAGS = -Wall -Wextra

all: lqueue_test stllqueue_test aqueue_test

lqueue_test: Queue.cpp $(SRC)/LQueue/Queue.o $(GTEST_MAINA)
	$(CPP) $(CFLAGS) $(GTEST_INCLUDES) -pthread -o lqueue_test Queue.cpp $(SRC)/LQueue/Queue.o $(SRC)/LQueue/Node.o $(GTEST_MAINA)

stllqueue_test: Queue.cpp $(SRC)/STLLQueue/Queue.o $(GTEST_MAINA)
	$(CPP) $(CFLAGS) $(GTEST_INCLUDES) -pthread -o stllqueue_test Queue.cpp $(SRC)/STLLQueue/Queue.o $(GTEST_MAINA)

aqueue_test: Queue.cpp $(SRC)/AQueue/Queue.o $(GTEST_Maina)
	$(CPP) $(CFLAGS) $(GTEST_INCLUDES) -pthread -o aqueue_test Queue.cpp $(SRC)/AQueue/Queue.o $(GTEST_MAINA)

$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h
	cd $(GTEST)/make; make

clean:
	rm -f lqueue_test stllqueue_test aqueue_test
	rm -f $(GTEST_MAINA)
	cd $(GTEST)/make; $(MAKE) clean
	cd $(TEST)

