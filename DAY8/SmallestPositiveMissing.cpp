//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        int j=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=0){
                swap(arr[i],arr[j]);
                j++;
            }
        }
        for(int i=j;i<n;i++){
            int num=abs(arr[i]);
            if(num-1+j<n && arr[num-1+j]>0){
                arr[num-1+j]= -arr[num-1+j];
            }
        }
        for(int i=j;i<n;i++){
            if(arr[i]>0){
                return i+1-j;
            }
        }
        return n-j+1;
    }
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends
