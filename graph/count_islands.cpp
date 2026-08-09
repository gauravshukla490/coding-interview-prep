class Solution {
  public:
    vector<pair<int,int>>directions = {{-1 , -1} , {-1 , 1},{1 , 1},{1 , -1} , {0 , -1},{0 , 1},{-1 , 0},{1 , 0}};
    
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
     queue<pair<int,int>>q;
     int cnt = 0;
     
    for(int i=0 ; i<n ; i++){
        for(int j=0; j<m ; j++){
            if(grid[i][j] == 'L'){
                grid[i][j]='#';
                q.push({i , j});
                
                while(!q.empty()){
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    
                    for(auto it : directions){
                        int new_row = row + it.first;
                        int new_col = col + it.second;
                        
                        if(new_row < n && new_row >= 0 && new_col < m && new_col >= 0 &&grid[new_row][new_col]=='L'){
                            grid[new_row][new_col]='#';
                            q.push({new_row , new_col});
                        }
                    }
                    
                }
                
                cnt++;
            }
        }
    }
        return cnt;
    }
};