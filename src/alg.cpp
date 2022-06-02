// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
  T ar[100];
  int f, l;
 public:
  TPQueue() : f(0), l(0) {}
  void push(T znach) {
    int i = l++;
    while ((--i >= f) && (ar[i % size].prior < znach.prior)) {
      ar[(i + 1) % size] = ar[i % size];
    }
    ar[(i + 1) % size] = znach;
  }
  T pop() {
  return ar[(f++) % size];
  }
};

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
