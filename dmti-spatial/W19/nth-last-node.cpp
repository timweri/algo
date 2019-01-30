// Given a linked list and a number n
// Return the nth last node with just ONE pass

#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int data, Node *next) : data{data}, next{next} {}
  ~Node() { delete next; }
};

Node *make_list(int n) {
  Node *root, *cur = nullptr;
  for (int i = 0; i < n; ++i) {
    cur = new Node(i, cur);
    root = cur;
  }
  return root;
}

void print_list(Node *list) {
  Node *cur = list;
  while (cur) {
    cout << cur->data << " -> ";
    cur = cur->next;
  }
  cout << "NULL" << endl;
}

int nth_last_node(Node *list, size_t n) {
  vector<int> v;
  Node *cur = list;
  while (cur) {
    v.push_back(cur->data);
    cur = cur->next;
  }
  if (n > v.size()) {
      return -1;
  }
  else return v[v.size() - n - 1];
}

int main() {
  Node *lst = make_list(5);
  print_list(lst);
  cout << nth_last_node(lst, 0) << endl;
  delete lst;
  return 0;
}