// Beats 71%
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
class Solution {
public:
  ListNode *mergeNodes(ListNode *head) {
    ListNode *currentNode = head->next;
    ListNode *prevZeroNode = head;
    int runningSum = 0;
    while (currentNode->next != nullptr) {
      if (currentNode->val == 0) {
        currentNode->val = runningSum;
        prevZeroNode->next = currentNode;
        prevZeroNode = currentNode;
        runningSum = 0;
      } else {
        runningSum += currentNode->val;
      }
      currentNode = currentNode->next;
    }
    if (currentNode->val != 0) {
      return nullptr;
    }
    currentNode->val = runningSum;
    prevZeroNode->next = currentNode;
    return head->next;
  }
};
