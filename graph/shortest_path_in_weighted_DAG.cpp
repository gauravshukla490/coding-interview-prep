class Solution {
  public:
    stack<int>st;
    void topoSort(int node ,vector<vector<pair<int,int>>>& adj , vector<int>&vis ){
        vis[node]=1;
        
        for(auto it : adj[node]){
            if(!vis[it.first]){
                topoSort(it.first , adj , vis);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
      vector<vector<pair<int,int>>> adj(V);
       vector<int>distance(V,INT_MAX);
       distance[0]=0;
       
      for(int i = 0; i < edges.size(); i++) {
          int u = edges[i][0];
          int v = edges[i][1];
          int wt = edges[i][2];

          adj[u].push_back({v, wt});
      }
      
      vector<int>vis(V,0);
      for(int i=0 ; i<V ; i++){
          if(!vis[i]){
              topoSort(i , adj , vis);
          }
      }
        
     while(!st.empty()){
         int node = st.top();
         st.pop();
         
         for(auto it : adj[node]){
             int point = it.first;
             int dist = it.second;
             
             if(distance[node] + dist < distance[point]){
                 distance[point] = distance[node] + dist; 
             }
         }
     }
     return distance;
    }
};
