#include "Queue.h"
#include <cassert>
#include <iostream>

private bool Queue::arrayIsFull() {
  if (size()==capacity) return true;
  else return false;
}

private bool Queue::arrayTooBig() {
  if ((capacity>initSize) && (numElements<=REDUCE_ARRAY_CHECK*capacity)) {
    return true;
  }  else return false;
}

Queue::Queue(int initialSize) {
  theQueue = new int[initialSize];
  front = back = numElements = 0;
  capacity = initSize = initialSize;
}

Queue::~Queue() {
  delete [] theQueue;
}

void Queue::enqueue(int value) {
  // if theQueue is full
  // create new queue twice as big
  // copy all elements to new queue
  // delete old queue
  // point old queue pointer to new stack

  if (arrayIsFull()) {
    int* newQueue = new int[EXPAND_ARRAY*capacity];
    for (int i = 0; i < size(); i++) {
      newQueue[i]=theQueue[front];
      front++;
      if (front>capacity)
        front=front%capacity;
    }
    back=front;
    front=0;
    delete [] theQueue;
    theQueue=newQueue;
    capacity=EXPAND_ARRAY*capacity;
    }
   
    back++;
    if (back>capacity)
      back=back%capacity;
    theQueue[back]=value;
    numElements++;
}

int Queue::dequeue() {
  assert(!isEmpty());
  
  if (arrayTooBig()) {
    int newCapacity=max(REDUCE_ARRAY*capacity,initSize);  
    int* newQueue=new int[newCapacity)];
    for (int i=0; i<size(); i++) {
      newQueue[i]=theQueue[front];
      front++;
      if (front>capacity)
        front=front%capacity;
    }
    back=front;
    front=0;
    delete [] theQueue;
    theQueue=newQueue;
    capacity=REDUCE_ARRAY*capacity;
  }
  int result=theQueue[front];
  theQueue[front]=0;
  front++;
  if (front>capacity)
    front=front%capacity;
  numElements--;
  return result;  
}

int Queue::peek() {
  assert(!isEmpty()); 
  return theQueue[front];
}

int Queue::size() {
  return numElements;
}

bool isEmpty() {
  if (size()>0) return false;
  else return true;
}
