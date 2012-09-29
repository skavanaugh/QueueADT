#ifndef __QUEUE_H__
#define __QUEUE_H__

class Queue {

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
