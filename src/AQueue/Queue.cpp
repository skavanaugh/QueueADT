#include "Queue.h"
#include <cassert>
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;

bool Queue::arrayIsFull() {
  if (size()==capacity) return true;
  else return false;
}

bool Queue::arrayTooBig() {
  if ((capacity>initSize) && (numElements<(int)(REDUCE_ARRAY_CHECK*capacity))) {
    return true;
  }  else return false;
}

Queue::Queue() {
  initSize = 10;
  theQueue = new int[initSize];
  front = back = numElements = 0;
  capacity = initSize;
  EXPAND_ARRAY=2.0;
  REDUCE_ARRAY=0.5;
  REDUCE_ARRAY_CHECK=0.25;
}

Queue::~Queue() {
  delete [] theQueue;
}

void Queue::enqueue(int value) {

  if (isEmpty()) {
    theQueue[back]=value;
    numElements++;
    return;
  } else 
    if (arrayIsFull()) {
    int* newQueue = new int[(int)(EXPAND_ARRAY*capacity)];
    for (int i = 0; i < size(); i++) {
      newQueue[i]=theQueue[front];
      front++;
      if (front>capacity)
        front=front%capacity;
    }
    back=size()-1;
    front=0;
    delete [] theQueue;
    theQueue=newQueue;
    capacity=(int)(EXPAND_ARRAY*capacity);
    }
    // the following code executes if (arrayIsFull() or !(isEmpty()))
    back++;
    if (back>capacity)
      back=back%capacity;
    theQueue[back]=value;
    numElements++;

    //std::cout << "i finished enqueuing " << value << " and now theQueue[front] is " << theQueue[front] << std::endl;
}

int Queue::dequeue() {
  assert(!isEmpty());
  
  //std::cout<<size()<<" "<<capacity<<" "<<peek()<<std::endl;

    if (arrayTooBig()) {
    int newCapacity=std::max((int)(REDUCE_ARRAY*capacity),initSize);  
    int* newQueue=new int[(int)newCapacity];
    for (int i=0; i<size(); i++) {
      newQueue[i]=theQueue[front];
      front++;
      if (front>capacity)
        front=front%capacity;
    }
    back=size()-1;
    front=0;
    delete [] theQueue;
    theQueue=newQueue;
    capacity=(int)newCapacity;
  } 
  int result=theQueue[front];
  //theQueue[front]=0;
  front++;
  if (front>capacity)
    front=front%capacity;
  numElements--;

  //std::cout<<size()<<" "<<capacity<<" "<<peek()<<std::endl;
  return result;  
}

int Queue::peek() {
  assert(!isEmpty());
  //std::cout << "theQueue[front] " << theQueue[front] << std::endl;
  return theQueue[front];
}

int Queue::size() {
  return numElements;
}

bool Queue::isEmpty() {
  if (size()>0) return false;
  else return true;
}
