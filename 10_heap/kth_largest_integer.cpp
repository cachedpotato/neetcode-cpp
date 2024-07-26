#include <vector>
#include <iostream>
#include <queue>

using namespace std;
                  
class KthLargest   {
private:          
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
  int k;

public:
  KthLargest(int k, std::vector<int>& nums) {
    this -> k = k;
    for (int &n: nums) {
      minHeap.push(n);
      if (minHeap.size() > k) {
        minHeap.pop();
      }
    }
  }

  int add(int val) {
    minHeap.push(val);
    if (minHeap.size() > k) {
      minHeap.pop();
    }

    return minHeap.top();
  }
};

int main() {
  std::vector<int> nums = {1, 2, 3, 3};
  KthLargest kthLargest(3, nums);
  std::cout << kthLargest.add(3) << std::endl; // return 3 
  std::cout << kthLargest.add(5) << std::endl; // return 3
  std::cout << kthLargest.add(6) << std::endl; // return 3
  std::cout << kthLargest.add(7) << std::endl; // return 5
  std::cout << kthLargest.add(8) << std::endl; // return 6
}