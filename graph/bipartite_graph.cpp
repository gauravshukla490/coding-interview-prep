class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
       
    //create adjacency list
    vector<vector<int>>adj(V);
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
      
      queue<int>q;
      vector<int>color(V,-1);
      
      q.push(0);
      color[0]=0;
      
      while(!q.empty()){
          int node = q.front();
          q.pop();
          
          for(auto it : adj[node]){
              
              if(color[it] == -1){
                  color[it] = !color[node];
                  q.push(it);
              }
              else if(color[it]  == color[node]){
                  return false;
              }
              else continue;
          }
      }
      return true;
    }
};