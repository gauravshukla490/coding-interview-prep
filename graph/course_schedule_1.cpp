class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& pre) {
    vector<vector<int>>adj(n);
    vector<int>inDegree(n , 0);
    
    for(int i=0 ; i<pre.size() ; i++){
        int u = pre[i][0];
        int v = pre[i][1];
        
        adj[u].push_back(v);
        inDegree[v]++;
    }
    
    queue<int>q;
    vector<int>ans;
    
    for(int i=0 ; i<n ; i++){
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
    
    return ans.size() == n ? true : false ;
    }
};