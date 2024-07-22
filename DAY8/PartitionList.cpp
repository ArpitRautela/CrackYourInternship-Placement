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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;
        vector<int> fst;
        vector<int> scd;

        while (temp != nullptr) {
            if (temp->val < x) {
                fst.push_back(temp->val);
            } else {
                scd.push_back(temp->val);
            }
            temp = temp->next; 
        }

        ListNode dummy;
        ListNode* ans = &dummy;

        for (int i = 0; i < fst.size(); ++i) {
            ListNode* newnode = new ListNode(fst[i]);
            ans->next = newnode;
            ans = ans->next;  
        }

        for (int i = 0; i < scd.size(); ++i) {
            ListNode* newnode = new ListNode(scd[i]);
            ans->next = newnode;
            ans = ans->next;  
        }

        return dummy.next;  
    }
};
