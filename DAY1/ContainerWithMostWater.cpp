class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int a = 0, b = n-1;
        int numofcontainer = n-1;
        int maxwater = numofcontainer * min(height[a],height[b]);
        int water;
        while(a<b){
            if(height[a]<=height[b]){
                a++;
                numofcontainer--;
                water = numofcontainer * min(height[a],height[b]);
            }
            else if(height[a]>height[b]){
                b--;
                numofcontainer--;
                water = numofcontainer * min(height[a],height[b]);
            }

            if(maxwater<water) maxwater = water;
        }
        return maxwater;
    }
};
