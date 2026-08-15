class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        vector<vector<pair<int,int>>>adj(n);

        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];

            adj[u].push_back({v , wt});
            adj[v].push_back({u, wt});
        }
        
          priority_queue<
            vector<long long>,
            vector<vector<long long>>,
            greater<vector<long long>>
        > q;
        q.push({0,0});
        dist[0]=0;
        ways[0]=1;

        while(!q.empty()){
            vector<long long>temp = q.top();
            q.pop();

            long long distance = temp[0];
            int node = temp[1];

            if(distance > dist[node])
                 continue;

            for(auto it : adj[node]){
                long long new_dist = distance + it.second;
                int neighbour = it.first;

                if(new_dist == dist[neighbour]){
                    ways[neighbour] = (ways[neighbour] + ways[node]) % MOD;
                }
                else if(new_dist < dist[neighbour]){
                    dist[neighbour] = new_dist;
                    ways[neighbour] = ways[node];
                    q.push({new_dist , neighbour});
                }
            }
        }

        return ways[n-1] == 0 ? -1 : ways[n-1];
    }
};