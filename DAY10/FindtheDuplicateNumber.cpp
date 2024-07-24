class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,bool> mp;
        for(int i = 0;i<nums.size();i++){
            if(mp[nums[i]]) return nums[i];
            else{
                mp[nums[i]]=1;
            }
        }
        return -1;
    }
};
