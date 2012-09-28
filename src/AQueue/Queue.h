#ifndef __QUEUE_H__
#define __QUEUE_H__

class Queue {
 private:
  int* theQueue;
  int front;
  int back;
  int capacity;
  int numElements;
  const int initSize;
  const float EXPAND_ARRAY=2.0;
  const float REDUCE_ARRAY=0.5;
  const float REDUCE_ARRAY_CHECK=0.25;
  bool arrayIsFull();
  bool arrayTooLarge();

 public:
  Queue(int initialSize = 10);
  ~Queue(); //destructor
  void enqueue(int value);
  int dequeue();
  int peek();
  int size();
  bool isEmpty();
};


#endif
