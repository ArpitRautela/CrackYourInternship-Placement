class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> p1;
        unordered_set<int> p2;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    p1.insert(i);
                    p2.insert(j);
                }
            }
        }
        for(int x : p1){
            for(int i=0;i<n;i++){
                matrix[x][i]=0;
            }
        }
        for(int x : p2){
            for(int i=0;i<m;i++){
                matrix[i][x]=0;
            }
        }
    }
};
