#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

size_t quicksort_pivot(size_t start, size_t length) {
  // Chooses a random pivot
  return rand() % length + start;
}

template <typename T>
size_t quicksort_partition(vector<T> &arr, size_t start, size_t length,
                           size_t p) {
  swap(arr[p], arr[start + length - 1]);
  p = start + length - 1;
  for (size_t i = start; i < start + length; ++i) {
    if (i == p)
      return p;
    if (arr[i] >= arr[p]) {
      swap(arr[i], arr[p - 1]);
      swap(arr[p - 1], arr[p]);
      --p;
      --i;
    }
  }
  return p;
}

template <typename T>
void quicksort_recur(vector<T> &arr, size_t start, size_t length) {
  if (length <= 1 || start >= arr.size())
    return;
  if (length == 2) {
    if (arr[start] > arr[start + 1])
      swap(arr[start], arr[start + 1]);
    else
      return;
  }
  size_t p = quicksort_pivot(start, length);
  p = quicksort_partition(arr, start, length, p);
  quicksort_recur(arr, start, p - start + 1);
  quicksort_recur(arr, p + 1, length - (p - start + 1));
}

template <typename T> vector<T> quicksort(vector<T> arr) {
  quicksort_recur(arr, 0, arr.size());
  return move(arr);
}

vector<int> make_array(size_t n) {
  vector<int> res;
  for (int i = 0; i < n; ++i) {
    res.push_back(rand() % n);
  }
  return move(res);
}

int main() {
  srand(time(NULL));
  vector<int> arr = make_array(40);
  vector<int> sorted_arr = quicksort(arr);
  for (auto &it : sorted_arr)
    cout << it << " ";
  cout << endl;
  return 0;
}
