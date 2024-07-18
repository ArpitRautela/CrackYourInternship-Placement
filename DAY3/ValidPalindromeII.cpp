class Solution {
public:
    bool isPalindrome(string s,int l,int r){
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else{
                return false;
            }
            
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.length()-1;
        while(l<r){
            if(s[l]==s[r]){
            l++;
            r--;
            }
            else{
                return isPalindrome(s,l+1,r)|| isPalindrome(s,l,r-1);
            }
        }
        return true;
    }
};
