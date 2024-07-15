class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int min=arr[0];
        int maxprofit=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<min){
                min=arr[i];
            }
            else if(arr[i]-min > maxprofit){
                maxprofit=arr[i]-min;
            }
        }
        
        return maxprofit;
    }
};
