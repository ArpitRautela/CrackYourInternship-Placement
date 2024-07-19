class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n,0);
        stack<int> s1;
        for(int i = 0;i<n;i++){
            while(!s1.empty() && temperatures[s1.top()]<temperatures[i]){
                res[s1.top()] = i-s1.top();
                s1.pop();
            }
            s1.push(i);
        }
        return res;
    }
};
