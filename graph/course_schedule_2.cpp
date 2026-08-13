class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
     vector<vector<int>>adj(n);
     vector<int>inDegree(n , 0);
     
     for(int i=0 ; i<prerequisites.size() ; i++){
         int u = prerequisites[i][0];
         int v = prerequisites[i][1];
         
         adj[v].push_back(u);
         inDegree[u]++;
     }
      queue<int>q;
      vector<int>ans;
      
      for(int i=0 ; i<n ;i++){
          if(inDegree[i] == 0){
              q.push(i);
          }
      }
      
      while(!q.empty()){
          int node = q.front();
          q.pop();
          
          ans.push_back(node);
          
          for(auto it : adj[node]){
              inDegree[it]--;
              
              if(inDegree[it] == 0) q.push(it);
          }
      }
      return ans.size() == n ? ans : vector<int>{} ;
    }
};