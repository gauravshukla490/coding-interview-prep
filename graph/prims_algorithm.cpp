class Solution {
	public:
	int spanningTree(int V, vector<vector<int>> & edges) {
		vector<vector<pair<int, int>> >adj(V);
		
		for (int i = 0 ; i<edges.size() ; i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			int wt = edges[i][2];
			
			adj[u].push_back({v, wt});
			adj[v].push_back({u, wt});
		}
	    
	    priority_queue<
         pair<int,int>,
         vector<pair<int,int>>,
         greater<pair<int,int>>
         > q;
     
		vector<int>vis(V, 0);
		q.push({0, 0}); // wt,node
		int sum = 0 ;
		
		while (!q.empty()) {
			auto it = q.top();
			q.pop();
			
			int wt = it.first;
			int node = it.second;
			
			if (vis[node])
				continue;
			
			vis[node] = 1;
			sum += wt;
			
			for (auto it: adj[node]) {
				
				int adjNode = it.first;
				int adjWt = it.second;
				if (!vis[adjNode]) {
					q.push({ adjWt,adjNode});
				}
			}
		}
		return sum;
	}
};