#ifndef GENERIC_CYCLE_HPP_
#define GENERIC_CYCLE_HPP_

template <typename T, typename F>
int findCycleLength(const T& start, const F& f) {
  T slow = start;
  T fast = start;

  slow = f(slow);
  fast = f(f(fast));

  while (slow != fast) {
    slow = f(slow);
    fast = f(f(fast));
  }

  int length = 1;

  slow = f(slow);
  fast = f(f(fast));

  while (slow != fast) {
    slow = f(slow);
    fast = f(f(fast));
    ++length;
  }

  return length;
}

#endif    // GENERIC_CYCLE_HPP_

