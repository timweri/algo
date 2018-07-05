/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  Output: 7 -> 0 -> 8
  Explanation: 342 + 465 = 807.
*/

#include <stdlib.h>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
static ListNode* one = new ListNode(1);
public:
  ListNode* addTwoNumbersShort(ListNode* l1, ListNode* l2) {
    ListNode *cur1 = l1, *cur2 = l2;
    ListNode head(0);
    ListNode *curout = &head;
    int val1, val2, carry_over = 0;
    while(cur1 || cur2 || carry_over) {
      val1 = cur1 ? cur1->val : 0;
      val2 = cur2 ? cur2->val : 0;
      int temp = val1 + val2 + carry_over;
      curout->next = new ListNode(temp % 10);
      curout = curout->next;
      carry_over = temp / 10;
      cur1 = cur1 ? cur1->next : NULL;
      cur2 = cur2 ? cur2->next : NULL;
    }
    return head.next;
  }
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (_isZero(l1)) return l2;
    else if (_isZero(l2)) return l1;
  
    // Initialize pointers
    ListNode *output = NULL;
    ListNode *cur1 = l1, *cur2 = l2, *curout;
    char carry_over = 0;
    
    while (cur1 && cur2) {
        char temp_sum = cur1->val + cur2->val + carry_over;
        if (!output) {
          output = new ListNode(temp_sum % 10);
          curout = output;
        }
        else {
          curout->next = new ListNode(temp_sum % 10);
          curout = curout->next;
        }
        carry_over = temp_sum / 10;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    if (cur1) {
      if (carry_over) {
        curout->next = addTwoNumbers(cur1, one);
      } else {
        curout->next = cur1;
      }
    }
    else if (cur2) {
      if (carry_over) {
      curout->next = addTwoNumbers(cur2, one);
      } else {
        curout->next = cur2;
      }
    } else if (carry_over) {
      curout->next = new ListNode(carry_over);
    }
    return output;
  }
  
  void printNumber(ListNode* lst) {
    ListNode *cur = lst;
    while (cur) {
      cout << cur->val << " -> ";
      cur = cur->next;
    }
    cout << "\n";
  }
  ListNode* createList(int n) {
    ListNode *out, *curout;
    int cur = n;
    out = new ListNode(cur % 10);
    curout = out;
    cur = cur / 10;
    while (cur) {
      curout->next = new ListNode(cur % 10);
      curout = curout->next;
      cur = cur / 10;
    }
    return out;
  }
  bool _isZero(ListNode* lst) {
    // returns true if lst represents 0
    // returns false otherwise
    if (!lst) return false;
    if (lst->val==0 && !lst->next) return true;
    return false;
  }
  
  ListNode* _deepCopy(ListNode* lst) {
    // make a deep clone of a ListNode
    if (_isZero(lst)) return new ListNode(0);
    
    ListNode *cur = lst;
    ListNode *out = new ListNode(cur->val);
    ListNode *curout = out;
    cur = lst->next;
    while (cur) {
      curout->next = new ListNode(cur->val);
      curout = curout->next;
      cur = cur->next;
    }
    return out;
  }
};

int main () {
  Solution solution = Solution();
  ListNode *a = solution.createList(1041),
           *b = solution.createList(930);
  solution.printNumber(solution.addTwoNumbers(a,b));
  return 0;
}

