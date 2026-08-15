class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>>adj(n);
    vector<int>cost(n,1e9);
    for(int i=0;i<flights.size();i++){
        int u = flights[i][0];
        int v = flights[i][1];
        int wt = flights[i][2];
        
        adj[u].push_back({v,wt});  
    }

    queue<vector<int>>q; //{stops , node , cost}
    q.push({0 , src , 0});
    cost[src]=0;

    while(!q.empty()){

        vector<int>temp = q.front();
        q.pop();

        int stops = temp[0];
        int  node = temp[1];
        int  curr_cost = temp[2];

        for(auto it : adj[node]){
              
              if(stops+1 <= k+1){
                int new_cost = curr_cost + it.second;
                   
                   if(new_cost < cost[it.first]){
                       cost[it.first] = new_cost;
                       q.push({stops+1 ,it.first ,new_cost });
                   }
              }
        }
    }
    return cost[dst]==1e9 ? -1 : cost[dst];
    }
};