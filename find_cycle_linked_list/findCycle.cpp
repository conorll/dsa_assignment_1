#include <gtest/gtest.h>
#include <iostream>
#include "findCycle.hpp"

int findCycleLength(Node* start) {

  Node* cycleStart = nullptr;

  Node* slow = start;
  Node* fast = start;

  while(fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      cycleStart = slow;
      break;
    }
  }

  if (cycleStart == nullptr) {
    return -1;
  }

  int length = 0;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    ++length;
    if (slow == fast) {
      break;
    }
  }
  return length;
}


