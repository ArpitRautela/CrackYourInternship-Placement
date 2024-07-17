class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry  = 0;
        int l = a.length() - 1;
        int r = b.length() - 1;
        while(l>=0||r>=0||carry){
            if(l>=0){
                carry += a[l--] -'0';
            }
            if(r>=0){
                carry += b[r--] - '0';
            }
            ans+=carry%2 + '0';
            carry /= 2;
        }   
        reverse(begin(ans),end(ans));
        return ans;
    }
};
