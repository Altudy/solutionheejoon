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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ans = head;
        vector<ListNode*> node;
        while (head != nullptr)
        {
            node.emplace_back(head);
            head = (*head).next;
        }
        
        int len = node.size();
        if(len-n-1 >= 0) node[len - n - 1]->next = node[len - n]->next;
        else if(len-n-1 <= 0 && n!=1) ans = node[len-n+1];
        else ans = nullptr;

        return ans;
    }
};



//////////////////////////////
/* best solution

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {        
        ListNode* test=new ListNode;
        ListNode* q;
        ListNode* p;
        test->next=head;
        p=test;
        q=test;
        for(int i=0;i<=n;i++)
          p=p->next; 
        
        while(p!=NULL) {
          p=p->next;
          q=q->next;
        }
        q->next=q->next->next;
        return test->next;      
    }
};

*/
