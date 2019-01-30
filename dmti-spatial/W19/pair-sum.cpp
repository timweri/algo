// Given a sorted array and a number x
// Find the two elements that sum up to x
// runtime: O(n)
// space: O(1)

#include <iostream>
#include <vector>

using namespace std;

void find_pair(vector<int> arr, int x) {
  size_t start = 0, end = arr.size() - 1;
  while (start != end) {
    if (arr[start] + arr[end] > x)
      --end;
    else if (arr[start] + arr[end] < x)
      ++start;
    else {
      cout << arr[start] << " and " << arr[end] << endl;
      return;
    }
  }
  cout << "No such pair found" << endl;
}

int main() {
  find_pair({0, 10, 20, 30, 40, 50, 60, 70}, 30);
  return 0;
}