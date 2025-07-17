/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// 1 2 4
// 1 3 5

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {

    if (list1 == nullptr && list2 == nullptr)
      return nullptr;
    else if (list1 == nullptr)
      return list2;
    else if (list2 == nullptr)
      return list1;
    else if (list1->val <= list2->val)
      return new ListNode(list1->val, mergeTwoLists(list1->next, list2));
    else
      return new ListNode(list2->val, mergeTwoLists(list1, list2->next));
  }
};
