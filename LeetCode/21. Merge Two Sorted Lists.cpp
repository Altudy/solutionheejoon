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
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         ListNode* ans;
         ListNode* temp;
         if (l1 == nullptr && l2 == nullptr) return ans;
         else if (l1 == nullptr) return l2;
         else if (l2 == nullptr) return l1;

         if (l1->val >= l2->val) {
             ans = l2;
             swap(l1, l2);
         }
         else {
             ans = l1;
         }

         while (true)
         {
             while (l1->next != nullptr && l1->next->val < l2->val) {
                 l1 = l1->next;
             }
             if (l1->next == nullptr) {
                 l1->next = l2; break;
             }
             else {
                 temp = l1->next;
                 l1->next = l2;
                 l1 = temp;
                 swap(l1, l2);
             }
         }
         return ans;
     }
     void swap(ListNode*& l1, ListNode*& l2)
     {
         ListNode* temp;
         temp = l1;
         l1 = l2;
         l2 = temp;
     }
 };
 
 ////////////////////////////////////////////////////////////////////
 /* best solution
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        while (l1 || l2) {
            int val1 = l1? l1->val: numeric_limits<int>::max();
            int val2 = l2? l2->val: numeric_limits<int>::max();
            if (val1 < val2) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr = dummy->next;
        delete dummy;
        return curr;
    }
};
 
 */
