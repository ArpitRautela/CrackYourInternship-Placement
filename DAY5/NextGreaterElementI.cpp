class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        for (int i = 0; i < nums1.size(); ++i) {
            int nextGreater = -1;
            bool found = false;
            
            for (int j = 0; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    found = true;
                }
                if (found && nums2[j] > nums1[i]) {
                    nextGreater = nums2[j];
                    break;
                }
            }
            
            ans.push_back(nextGreater);
        }
        
        return ans;
    }
};
