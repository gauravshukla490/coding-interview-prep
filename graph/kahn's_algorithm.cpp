class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
    //create adjacency list and inDegree array
    
    vector<vector<int>>adj(V);
    vector<int>inDegree(V,0);
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        inDegree[v]++;
    }
        
     queue<int>q;
     
     for(int i=0;i<V;i++){
         if(inDegree[i]==0){
             q.push(i);
         }
     }
     
     vector<int>ans;
     
     while(!q.empty()){
         int node = q.front();
         q.pop();
         
         ans.push_back(node);
         
         for(auto it : adj[node]){
             inDegree[it]--;
             
             if(inDegree[it] == 0){
                 q.push(it);
             }
         }
     }
     return ans;
    }
};