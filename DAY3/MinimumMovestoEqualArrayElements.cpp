class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mid = n&1==0?n+1/2 : n/2;
        int eq = nums[mid];
        int move = 0;
        for(int i = 0;i<n;i++){
            move += abs(eq - nums[i]);
        }
        return move;
    }
};
