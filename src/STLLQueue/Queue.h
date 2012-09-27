#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <list>

class Queue {
 private:
  std::list<int> theQueue;

 public:
  Queue();
  //Queue(int initialSize = 10);
  ~Queue(); //destructor
  void enqueue(int value);
  int dequeue();
  int peek();
  int size();
  bool isEmpty();
};

#endif
