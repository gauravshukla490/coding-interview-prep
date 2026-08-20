class Dsu {
    vector<int>parent , rank;
    
    public: 
         Dsu(int n){
             parent.resize(n);
             rank.resize(n);
             
             for(int  i=0 ; i<n ; i++){
                 parent[i]=i;
                 rank[i]=1;
             }
         }
         
         int findUPar(int u ){
             if(parent[u] == u) return u;
             
              return parent[u] = findUPar(parent[u]);
         }
         
         void UnionByRank(int u , int v){
             int pu = findUPar(u);
             int pv = findUPar(v);
             
             if(pu == pv) return;
             
             else if(rank[pu] < rank[pv]){
                 parent[pu]=pv;
             }
             else if(rank[pv] < rank[pu]){
                 parent[pv]=pu;
             }
             else {
                     parent[pv] = pu;
                     rank[pu]++;
                 }
             
       }
     
};
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        vector<pair<int, pair<int,int>>> edgesList;

        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            edgesList.push_back({wt, {u, v}});
        }
        
        sort(edgesList.begin(), edgesList.end());
        
        Dsu ds(V);
        int ans = 0;
        
        for(auto it : edgesList){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUPar(u) != ds.findUPar(v)){
                ans += wt;
                
                ds.UnionByRank(u , v);
            }
        }
        return ans;
    }
};