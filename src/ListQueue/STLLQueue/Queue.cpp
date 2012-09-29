#include "Queue.h"
#include <cassert>
#include <list>
#include <iostream>

Queue::Queue() {
}

Queue::~Queue() {
}

void Queue::enqueue(int value) {
  theQueue.push_back(value);  
}

int Queue::dequeue() {
  assert (!isEmpty());
  int result=theQueue.front();
  theQueue.pop_front();
  return result;
}

int Queue::peek() {
  assert (!isEmpty());
  return theQueue.front();
}

int Queue::size() {
  return theQueue.size();
}

bool Queue::isEmpty() {
  return theQueue.empty();  
}
