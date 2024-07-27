class Solution {
public:

    int ans = INT_MAX;
    void bfs(queue<vector<int>> q, vector<vector<int>> &arr){
        vector<vector<int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};
        int n = arr.size();
        int m = arr[0].size();

        while(q.size()!=0){
            vector<int> a = q.front();
            q.pop();
            int i = a[0];
            int j = a[1];

            for(int k=0; k<4; k++){
                int nr = i+dir[k][0];
                int nc = j+dir[k][1];

                if(nr>=0 && nc>=0 && nr<n && nc<m && arr[nr][nc]==1){
                    arr[nr][nc]=-1;
                    q.push({nr,nc});
                }
            }
        }
    }

    void bfs2(queue<vector<int>> q, vector<vector<int>> &arr, vector<vector<int>> visited){
        vector<vector<int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};
        int n = arr.size();
        int m = arr[0].size();

        while(q.size()!=0){
            vector<int> a = q.front();
            q.pop();
            int i = a[0];
            int j = a[1];
            int step = a[2];
            visited[i][j] = 1;
            for(int k=0; k<4; k++){
                int nr = i+dir[k][0];
                int nc = j+dir[k][1];
                if(nr>=0 && nc>=0 && nr<n && nc<m && visited[nr][nc]==0){

                    if(arr[nr][nc]==-1){
                        ans = min(ans,step);
                    }else{
                        visited[nr][nc] = 1;
                        q.push({nr,nc,step+1});
                    }
                }
            }
        }
    }


    int shortestBridge(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        queue<vector<int>> q;
        vector<int> a;

        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<m; j++){
                if(arr[i][j]==1){
                   a = {i,j};
                   break;
                }
            }
        }

        arr[a[0]][a[1]] = -1;
        q.push(a);
        bfs(q,arr);
        

        queue<vector<int>> qu;
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<m; j++){
                if(arr[i][j]==1){
                   qu.push({i,j,0});
                }
            }
        }

        vector<vector<int>> visited(n,vector<int>(m,0));

        bfs2(qu,arr,visited);
        return ans;
    }
};
