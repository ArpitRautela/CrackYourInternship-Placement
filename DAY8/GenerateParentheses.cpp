class Solution {
public:
    vector<string> ans;
    void rec(int i, int tot, int sm, string &s)
    {
        if(i==tot)
        {
            if(sm==0)
             ans.push_back(s);
             return;
        }
        s += '(';
        rec(i+1,tot,sm+1,s);
        s.pop_back();
        if(sm-1>=0)
        {
            s += ')';
            rec(i+1,tot,sm-1,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        string res;
        rec(0,2*n,0,res);
        return ans;
    }
};
