// Given a binary tree
// Print out the binary tree in-order

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int data;
  Node *left, *right;
  Node(int data, Node *left, Node *right)
      : data{data}, left{left}, right{right} {}
  Node *insert(int e) {
    if (e <= data) {
      if (this->left)
        return this->left->insert(e);
      else {
        this->left = new Node(e, nullptr, nullptr);
        return this->left;
      }
    } else {
      if (this->right)
        return this->right->insert(e);
      else {
        this->right = new Node(e, nullptr, nullptr);
        return this->right;
      }
    }
  }
  ~Node() {
    delete left;
    delete right;
  }
};

Node *make_tree_sorted(int n) {
  if (n == 0)
    return nullptr;
  Node *tree = new Node(0, nullptr, nullptr);
  for (int i = 1; i < n; ++i) {
    tree->insert(i);
  }
  return tree;
}

Node *make_tree_rnd(int n) {
  if (n == 0)
    return nullptr;
  Node *tree = new Node(rand() % 50, nullptr, nullptr);
  for (int i = 1; i < n; ++i) {
    tree->insert(rand() % 50);
  }
  return tree;
}

void inorder_traverse_loop(Node *tree) {
  vector<Node *> stack;
  stack.push_back(tree);
  Node *cur = tree;
  while (cur && cur->left) {
    stack.push_back(cur->left);
    cur = cur->left;
  }
  while (!stack.empty()) {
    cur = stack.back();
    stack.pop_back();
    cout << cur->data << " ";
    if (cur && cur->right) {
      stack.push_back(cur->right);
      cur = cur->right;
      while (cur && cur->left) {
        stack.push_back(cur->left);
        cur = cur->left;
      }
    }
  }
}

void inorder_traverse_recur(Node *tree) {
  if (tree->left)
    inorder_traverse_recur(tree->left);
  cout << tree->data << " ";
  if (tree->right)
    inorder_traverse_recur(tree->right);
}

int main() {
  srand(0);
  Node *tree = make_tree_rnd(20);
  inorder_traverse_recur(tree);
  cout << endl;
  inorder_traverse_loop(tree);
  cout << endl;
  delete tree;
  return 0;
}