#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Problem {
  vector<pair<int, int>> A;
  vector<int> sortedA;
  size_t N; // total number of elements

  static size_t choose_pivot(size_t start, size_t length) {
    return start + length - 1;
  }

public:
  Problem(vector<pair<int, int>> A) : A{A} {
    N = 0;
    // construct the normal set
    for (auto &it : A) {
      N += it.second;
      for (int i = 0; i < it.second; ++i)
        sortedA.push_back(it.first);
    }
    // sort it
    sort(sortedA.begin(), sortedA.end());
  }

  int median_slow() {
    // use the normal set to find the median
    if (sortedA.size() % 2 == 1)
      return sortedA[(sortedA.size() - 1) / 2];
    else
      return 0.5 *
             (sortedA[(sortedA.size() - 1) / 2] + sortedA[sortedA.size() / 2]);
  }

  size_t partition(size_t start, size_t length, size_t pivot,
                   vector<pair<int, int>> &A_tmp) {
    swap(A_tmp[pivot], A_tmp[start + length - 1]);
    pivot = start + length - 1;
    for (size_t i = start; i < start + length; ++i) {
      if (i == pivot)
        return pivot;
      if (A_tmp[i].first > A_tmp[pivot].first) {
        swap(A_tmp[i], A_tmp[pivot - 1]);
        swap(A_tmp[pivot - 1], A_tmp[pivot]);
        --pivot;
        --i;
      }
    }
    return pivot;
  }

  int find_kth_smallest(size_t start, size_t length, size_t k,
                        vector<pair<int, int>> &A_tmp) {
    if (length == 1)
      return A_tmp[start].first;

    size_t pivot = choose_pivot(start, length);
    pivot = partition(start, length, pivot, A_tmp);

    // find the number of number on the left of pivot
    size_t left_qty = 0;
    for (size_t i = start; i < pivot; ++i) {
      left_qty += A_tmp[i].second;
    }

    // if k <= left_qty then the kth largest lies on the left of the pivot
    if (k <= left_qty)
      return find_kth_smallest(start, pivot - start, k, A_tmp);
    // if left_qty < k <= left_qty + A[pivot].second
    // then the pivot is the kth smallest
    else if (left_qty < k && k <= left_qty + A_tmp[pivot].second)
      return A_tmp[pivot].first;
    // else, k > left_qty + A[pivot].second
    // kth smallest lies in the high partition
    // and is the (k - left_qty - A[pivot])th smallest in that partition
    else
      return find_kth_smallest(pivot + 1, length - (pivot - start + 1),
                               k - left_qty - A_tmp[pivot].second, A_tmp);
  }

  int find_kth_smallest(size_t k) {
    vector<pair<int, int>> A_tmp = A;
    return find_kth_smallest(0, A_tmp.size(), k, A_tmp);
  }

  int median_fast() {
    if (N % 2 == 1)
      return find_kth_smallest((N - 1) / 2);
    else
      return 0.5 * (find_kth_smallest((N - 1) / 2) + find_kth_smallest(N / 2));
  }
};

int main() {
  Problem p1{{{55, 3}, {26, 1}, {17, 2}, {49, 4}}};
  Problem p2{{{58, 1}, {57, 1}, {55, 1}, {56, 1}}};
  Problem p3{{{58, 1}, {59, 1}, {57, 2}}};
  cout << (p1.median_slow() == p1.median_fast()) << " " << p1.median_slow()
       << " " << p1.median_fast() << endl;
  cout << (p2.median_slow() == p2.median_fast()) << " " << p2.median_slow()
       << " " << p2.median_fast() << endl;
  return 0;
}