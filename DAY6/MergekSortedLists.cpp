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
        // Use a vector to store all the values from the linked lists
        vector<int> ans;
        
        // Traverse each linked list and add its elements to the vector
        for (int i = 0; i < lists.size(); i++) {
            ListNode* current = lists[i];
            while (current != nullptr) {
                ans.push_back(current->val);
                current = current->next;
            }
        }
        
        // Sort the collected values
        sort(ans.begin(), ans.end());
        
        // Create a new linked list from the sorted values
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        for (int i = 0; i < ans.size(); i++) {
            temp->next = new ListNode(ans[i]);
            temp = temp->next;
        }
        
        return dummy->next;
    }
};
