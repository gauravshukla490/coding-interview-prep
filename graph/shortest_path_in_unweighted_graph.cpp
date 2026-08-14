class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<int>>adj(V);
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<pair<int,int>>q;
        vector<int>distance(V , INT_MAX);
        distance[src]=0;
        q.push({src , 0});
        
    while(!q.empty()){
        int node = q.front().first;
          int dist = q.front().second;
          q.pop();
          
          for(auto it : adj[node]){
              if(distance[it] > dist+1 ){
                  distance[it] = dist  + 1;
                  q.push({it , dist+1});
              }
          }
    }
    return distance[dest]==INT_MAX ? -1 : distance[dest] ;
    }
};
