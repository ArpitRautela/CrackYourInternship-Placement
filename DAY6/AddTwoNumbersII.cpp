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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> stack1, stack2;
        
        // Push the values of l1 into stack1
        while (l1 != nullptr) {
            stack1.push(l1->val);
            l1 = l1->next;
        }
        
        // Push the values of l2 into stack2
        while (l2 != nullptr) {
            stack2.push(l2->val);
            l2 = l2->next;
        }
        
        int carry = 0;
        ListNode* result = nullptr;
        
        while (!stack1.empty() || !stack2.empty() || carry) {
            int sum = carry;
            if (!stack1.empty()) {
                sum += stack1.top();
                stack1.pop();
            }
            if (!stack2.empty()) {
                sum += stack2.top();
                stack2.pop();
            }
            
            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            newNode->next = result;
            result = newNode;
        }
        
        return result;
    }
};
