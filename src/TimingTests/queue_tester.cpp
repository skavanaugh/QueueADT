#include "../../include/Queue.h"
//#include "../AQueue/Queue.h"
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

int main() {
  Queue* q = new Queue();
  int start, end, elapsed = 0;
  double seconds = 0;
  int NUMLOOPS = 20000000;

  start = clock();
  for (int i = 1; i <= NUMLOOPS; i++) {
    q->enqueue(i);
  }
  end = clock();
  elapsed = end - start;
  seconds = (double) elapsed/CLOCKS_PER_SEC;
  cout << NUMLOOPS << " enqueues took " << seconds << " seconds." << endl;

  start = clock();
  for (int i = 1; i <= NUMLOOPS; i++) {
    q->dequeue();
  }
  end = clock();
  elapsed = end - start;
  seconds = (double) elapsed/CLOCKS_PER_SEC;
  cout << NUMLOOPS << " dequeues took " << seconds << " seconds." << endl;

  delete q;

  return 0;
}
