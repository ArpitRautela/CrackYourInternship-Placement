class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        
        for(char i : s) {
            if(i == '#') {
                if(!st1.empty()) {
                    st1.pop();
                }
            } else {
                st1.push(i);
            }
        }
        
        for(char i : t) {
            if(i == '#') {
                if(!st2.empty()) {
                    st2.pop();
                }
            } else {
                st2.push(i);
            }
        }
        
        while(!st1.empty() && !st2.empty()) {
            if(st1.top() != st2.top()) {
                return false;
            } else {
                st1.pop();
                st2.pop();
            }
        }
        
        return st1.empty() && st2.empty();
    }
};
