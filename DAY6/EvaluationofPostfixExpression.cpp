//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> stk;
        int num1;
        int num2;
        for(auto ch : S){
            if(ch == '*'||ch == '-'||ch == '+'||ch == '/'){
                num1=stk.top();
                stk.pop();
                num2=stk.top();
                stk.pop();
                if(ch == '*'){
                    num1=num1*num2;
                }
                else if(ch == '+'){
                    num1=num1+num2;
                }
                else if(ch == '-'){
                    num1=num2-num1;
                }
                else if(ch == '/'){
                    num1=num2/num1;
                }
                stk.push(num1);
            }
            else{
                stk.push(ch - '0');
            }
        }
        return stk.top();
        
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends
