#ifndef __QUEUE_H__
#define __QUEUE_H__

class Queue {
 private:
  int* theQueue;
  int front;
  int back;
  int capacity;
  int numElements;
  int initSize;
  float EXPAND_ARRAY;
  float REDUCE_ARRAY;
  float REDUCE_ARRAY_CHECK;
  bool arrayIsFull();
  bool arrayTooBig();

 public:
  Queue();
  ~Queue(); //destructor
  void enqueue(int value);
  int dequeue();
  int peek();
  int size();
  bool isEmpty();
};


#endif
