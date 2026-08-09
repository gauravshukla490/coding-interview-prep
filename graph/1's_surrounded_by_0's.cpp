class Solution {
  public:
    vector<pair<int,int>>directions = {{0 , -1},{0 , 1},{1 , 0},{-1 , 0}};
    
    int cntOnes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
    
     queue<pair<int,int>>q;
     
     for(int i=0 ; i<n ; i++){
         if(i==0 || i == n-1){
             for(int j=0 ; j<m ; j++){
                 if(grid[i][j] == 1){
                     grid[i][j]='#';
                     q.push({i , j});
                 }
             }
         }
         else {
             if(grid[i][0] == 1){
                  grid[i][0]='#';
                  q.push({i , 0});
             }
             
             if(grid[i][m-1] == 1){
                 grid[i][m-1] = '#';
                 q.push({i , m-1});
             }
         }
     }
      
     while(!q.empty()){
         int row = q.front().first;
         int col = q.front().second;
         q.pop();
         
         for(auto it : directions){
             int new_row = row + it.first;
             int new_col = col + it.second;
             
             if(new_row < n && new_row >= 0 && new_col < m && new_col >= 0 && grid[new_row][new_col] == 1){
                 grid[new_row][new_col] = '#';
                 q.push({new_row , new_col});
             }
         }
     }  
      
      int cnt = 0;
      for(int i=0 ; i<n ; i++){
          for(int j=0; j<m ; j++){
              if(grid[i][j] == 1){
                  cnt++;
              }
          }
      }
      
      return cnt;
    }
};