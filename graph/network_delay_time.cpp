class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<vector<pair<int,int>>>adj(n+1);

       for(int i=0;i<times.size();i++){
        int u = times[i][0];
        int v = times[i][1];
        int wt = times[i][2];

        adj[u].push_back({v , wt});
       } 
       
       vector<int>dist(n+1,1e9);
       priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> q;
       q.push({0 , k});
       dist[k]=0;

       while(!q.empty()){
        vector<int>temp = q.top();
        q.pop();

        int curr_time = temp[0];
        int node = temp[1];

           for(auto it : adj[node]){
              int new_time = curr_time + it.second;

              if(new_time < dist[it.first]){
                dist[it.first] = new_time;

                q.push({new_time , it.first});
              }
           }
       }
       int ans = INT_MIN;
       for(int i=1;i<=n;i++){
        if(dist[i]==1e9){
            return -1;
        }
        else ans = max(ans , dist[i]);
       }

       return ans;
    }
};