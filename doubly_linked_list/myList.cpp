#include <iostream>
#include <utility>
#include <string>
#include "myList.hpp"
#include "myInteger.hpp"

// default constructor
template <typename T>
MyList<T>::MyList() {
  sentinel->prev = sentinel;
  sentinel->next = sentinel;
}

// copy constructor
template <typename T>
MyList<T>::MyList(const MyList& other) {
  sentinel->prev = sentinel;
  sentinel->next = sentinel;
  Node* cur = other.sentinel->next;
  while (cur != other.sentinel) {
    push_back(cur->data);
    cur = cur->next;
  }
}

// assignment operator
template <typename T>
MyList<T>& MyList<T>::operator=(MyList other) {
  std::swap(sentinel, other.sentinel);
  std::swap(size_, other.size_);
  return *this;
}


// destructor
template <typename T>
MyList<T>::~MyList() {
  while(!empty()) {
    pop_back();
  }
  delete sentinel;
}

// constructor from an initializer list
template <typename T>
MyList<T>::MyList(std::initializer_list<T> vals) {
  sentinel->prev = sentinel;
  sentinel->next = sentinel;
  for (T val : vals) {
    push_back(val);
  }
}

// push back
template <typename T>
void MyList<T>::push_back(T val) {
  Node* newN = new Node(val, sentinel->prev, sentinel);
  sentinel->prev->next = newN;
  sentinel->prev = newN;
  ++size_;
}

// pop back
template <typename T>
void MyList<T>::pop_back() {

  if (empty()) {
    return;
  }

  Node* temp = sentinel->prev;
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  delete temp;
  --size_;
}

template <typename T>
void MyList<T>::push_front(T val) {
  Node* newN = new Node(val, sentinel, sentinel->next);
  sentinel->next->prev = newN;
  sentinel->next = newN;
  ++size_;
}

template <typename T>
void MyList<T>::pop_front() {
  if (empty()) {
    return;
  }

  Node* temp = sentinel->next;
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  delete temp;
  --size_;
}

// return the first element by reference
template <typename T>
T& MyList<T>::front() {
  return sentinel->next->data;
}

// return the first element by const reference
template <typename T>
const T& MyList<T>::front() const {
  return sentinel->next->data;
}

// return the last element by reference
template <typename T>
T& MyList<T>::back() {
  return sentinel->prev->data;
}

// return the last element by const reference
template <typename T>
const T& MyList<T>::back() const {
  return sentinel->prev->data;
}

// is the list empty?
template <typename T>
bool MyList<T>::empty() const {
  return size_ == 0;
}

// return the number of elements in the list
template <typename T>
int MyList<T>::size() const {
  return size_;
}
// return an iterator pointing to the first element
template <typename T>
typename MyList<T>::Iterator MyList<T>::begin() const {
  return Iterator(sentinel->next);
}

// return an iterator pointing to the last element
template <typename T>
typename MyList<T>::Iterator MyList<T>::end() const {
  return Iterator(sentinel);
}

// insert an element into the linked list before *it with the value val
template <typename T>
void MyList<T>::insert(const Iterator& it, const T& val) {
  Node* cur = it.getCur();
  Node* newN = new Node(val, cur->prev, cur);
  cur->prev->next = newN;
  cur->prev = newN;
  ++size_;
}

// remove *it from the list
template <typename T>
void MyList<T>::erase(const Iterator& it) {
  Node* cur = it.getCur();

  if(cur == sentinel) {
    return;
  }

  cur->prev->next = cur->next;
  cur->next->prev = cur->prev;
  delete cur;
  --size_;
}

// Iterator constructor
template <typename T>
MyList<T>::Iterator::Iterator(Node* pointer) {
  current_ = pointer;
}

// (pre-)increment an iterator
template <typename T>
typename MyList<T>::Iterator& MyList<T>::Iterator::operator++() {
  current_ = current_->next;
  return *this;
}

// (pre-)decrement an iterator
template <typename T>
typename MyList<T>::Iterator& MyList<T>::Iterator::operator--() {
  current_ = current_->prev;
  return *this;
}

// return the value pointed at by an iterator
template <typename T>
T& MyList<T>::Iterator::operator*() const {
  return current_->data;
}

template class MyList<int>;
template class MyList<std::string>;
template class MyList<MyInteger>;

