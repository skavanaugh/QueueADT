#include "Queue.h"
#include "Node.h"
#include <cassert>
#include <iostream>

Queue::Queue() {
  front=back=0;
  numElements=0;
}

Queue::~Queue() {
}

void Queue::enqueue(int value) {
  Node* curr=new Node(value);
  if (isEmpty()) {
    front=back=curr;
  } else {
    back->setNext(*curr);
    back=curr;
  }
  numElements++;
}

int Queue::dequeue() {
  assert (!isEmpty());
  
  Node* temp=front;
  int result=temp->getValue();
  front=temp->getNext();
  delete temp;
  numElements--;
  return result; 
}

int Queue::peek() {
  assert (!isEmpty());
  return front->getValue();
}

int Queue::size() {
  return numElements;
}

bool Queue::isEmpty() {
  if (size()>0) return false;
  else return true;
}
