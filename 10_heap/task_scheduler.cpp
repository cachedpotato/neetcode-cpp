#include <iostream>
#include <queue>
#include <deque>
#include <math.h>
#include <vector>
#include <unordered_map>

int leastInterval(std::vector<char>& tasks, int n) {
  std::unordered_map<char, int> count;
  std::priority_queue<int, std::vector<int>> taskHeap;
  std::deque<std::vector<int>> taskDeque;
  int cycles = 0;

  //getting task count information
  for (char& c: tasks) {
    if (count.find(c) == count.end()) {
      count[c] = 0;
    }
    count[c]++;
  }

  //setting up task heap (max heap w/ element: count)
  for (auto &t: count) {
    taskHeap.push(t.second);
  }

  while (!taskHeap.empty() || !taskDeque.empty()) {
    cycles++;

    if (!taskHeap.empty()) {
      //do the top node then move to deque
      int currentTask = taskHeap.top();
      taskHeap.pop();
      if (currentTask > 1) {taskDeque.push_back({currentTask - 1, cycles + n});}
    }

    //move from deque to heap
    if (!taskDeque.empty() && taskDeque.front()[1] == cycles) {
      taskHeap.push(taskDeque.front()[0]);
      taskDeque.pop_front();
    }
  }

  return cycles;
}

int main() {
  std::vector<char> tasks = {'A', 'A', 'A', 'B', 'C'};
  int n = 3;
  std::cout << leastInterval(tasks, n) << std::endl;

  std::vector<char> tasks2 = {'X', 'X', 'Y', 'Y'};
  int n2 = 2;
  std::cout << leastInterval(tasks2, n2) << std::endl;
}