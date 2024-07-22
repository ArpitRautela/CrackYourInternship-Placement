//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
        long long findPages(int n, int a[], int m) {
        // simple check
        if(n < m)
            return -1;
            
        long long left = 0, right = 0;
        for(int i=0; i<n; i++)
        {
            left = max(left, (long long)(a[i]));
            right += a[i];
        }
        
        long long mid;
        while(left < right)
        {
            mid = left + (right - left)/2;
            int pages = 0, count = 0;
            for(int i=0; i<n; i++)
            {
                if(pages + a[i] <= mid)
                    pages += a[i];
                else
                {
                    count++;
                    pages = a[i];
                }
            }
            if(pages)
                count++;
            
            
            if(count < m)
                right = mid - 1;    // each student needs less pages
            else if(count == m)
                right = mid;        // we need to minimize this
            else
                left = mid + 1;     // each student needs more pages
        }
        return left;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
