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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        ListNode* ans = nullptr;
        if (lists.size() == 0) return ans;

        // make pq
        for (auto list : lists) {
            while (list != nullptr) {
                pq.push(list);
                list = list->next;
            }
        }

        ListNode* pre = nullptr;
        if (!pq.empty())
        {
            ans = pq.top();
            pre = pq.top();
            pq.pop();
        }

        while (!pq.empty()) {
            pre->next = pq.top();
            pq.pop();
            pre = pre->next;
        }
        if (pre != nullptr) pre->next = nullptr;

        return ans;
    }
    struct cmp
    {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
};

///////////////////////////////////////////////////////
/* best solution

class Solution {
public:
    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (NULL == l1) return l2;
        else if (NULL == l2) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        int len = lists.size();
        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }
        
        return lists.front();
    }
};

*/
