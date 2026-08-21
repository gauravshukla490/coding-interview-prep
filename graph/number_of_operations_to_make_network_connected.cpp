class Dsu {
    vector<int>rank,parent;
    public:
       Dsu(int n){
        rank.resize(n);
        parent.resize(n);

        for(int i=0;i<n;i++){
            rank[i]=0;
            parent[i]=i;
        }
       }

       int FindUPar(int u){
         if(parent[u] == u) return u;

         return parent[u] = FindUPar(parent[u]);
       }

       void UnionByRank(int u , int v){
        int pu = FindUPar(u);
        int pv  = FindUPar(v);

        if(pu == pv) return;

        else if(rank[pu] < rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv] < rank[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pu]=pv;
            rank[pv]++;
        }
       }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
    vector<vector<int>>adj(n);
    for(auto it : connections){
        int u = it[0];
        int v = it[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n,0);
    queue<int>q;
    int nc = 0;

    for(int i=0 ; i<n;i++){
      if(!vis[i]){
         q.push(i);
         vis[i]=1;
         nc++;

         while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
         }
      }
    }
    Dsu ds(n);
    int extraEdges = 0;
    for(auto it : connections){
        int u = it[0];
        int v = it[1];

        if(ds.FindUPar(u) != ds.FindUPar(v)){
            ds.UnionByRank(u,v);
        }
        else extraEdges++;
    }

    return extraEdges >= nc-1 ? nc-1 : -1 ;
    }
};