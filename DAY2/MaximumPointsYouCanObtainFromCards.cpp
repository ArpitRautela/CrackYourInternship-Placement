class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int n = cardPoints.size();

        for(int i =0 ;i<k;i++){
            sum+=cardPoints[i];
        }

        int maxSum = sum;

        for(int i = k-1 ,j = n-1;i>=0;i--,j--){
            sum-=cardPoints[i];
            sum+=cardPoints[j];
            maxSum = max(sum,maxSum);
        }
        return maxSum;
    }
};
