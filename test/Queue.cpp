#include "gtest/gtest.h"
#include "../../include/Queue.h"
//#include "../src/AQueue/Queue.h"
#include <iostream>

using std::cout;

TEST(QueueTest, Enqueue) {
  Queue* q = new Queue();
  q->enqueue(6);

  EXPECT_EQ(6, q->peek());
  delete q;
}

TEST(QueueTest, EnqueueDequeue) {
  Queue* q = new Queue();
  for(int i=0;i<43;i++) {
    q->enqueue(i);
    EXPECT_EQ(i+1,q->size());
    EXPECT_FALSE(q->isEmpty());
  }
  for(int i=0;i<43;i++) {
    EXPECT_EQ(i,q->dequeue());
    EXPECT_EQ(42-i,q->size());
  }
  delete q;
}

TEST(QueueTest,WrapAround) {
  Queue* q = new Queue();
  for(int i=0;i<10;i++) {
    q->enqueue(i);
  }
  for(int i=0;i<5;i++) {
    EXPECT_EQ(i,q->dequeue());
  }
  for(int i=0;i<25;i++) {
    q->enqueue(5*i);
  }
  for(int i=5;i<10;i++) {
    EXPECT_EQ(i,q->dequeue());
  }
  for(int i=0;i<25;i++) {
    EXPECT_EQ(5*i,q->dequeue());
  }
  delete q;
}

