// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <list>
template<typename T>
class TPQueue {
private:
    std::list<T> data;
public:
    void push(const T& elem) {
        auto it = data.begin();
        while (it != data.end() && it->prior >= elem.prior) {
            ++it;
        }
        data.insert(it, elem);
    }
    T pop() {
        T elem = data.front();
        data.pop_front();
        return elem;
    }

    bool isEmpty() const { return data.empty(); }
    const T& front() const { return data.front(); }
    size_t size() const { return data.size(); }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
