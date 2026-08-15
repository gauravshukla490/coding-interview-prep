class Solution {
public:
    vector<pair<int,int>>directions={{0,-1},{0,1},{1,0},{-1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[0][0] = 0;

    priority_queue<
    vector<int>,
    vector<vector<int>>,
    greater<vector<int>>
    > q;                   //{effort , row , col}
    
    q.push({0 , 0 ,0});

    while(!q.empty()){
        vector<int>temp = q.top();
        q.pop();
        int curr_effort = temp[0];
        int row = temp[1];
        int col = temp[2];
         
         if(row == n-1 && col == m-1)
           return curr_effort;

        for(auto it : directions){
            int new_r = row + it.first;
            int new_c = col + it.second;

            if(new_r < n && new_r >=0 && new_c >=0 && new_c < m){
                int effort = abs(heights[row][col] - heights[new_r][new_c]);
                int new_effort = max(curr_effort , effort);
                
                 if(new_effort < dist[new_r][new_c]) {
                     dist[new_r][new_c] = new_effort;
                     q.push({new_effort, new_r, new_c});
                 }
            }
        }
    }
    return 0;
    }
};