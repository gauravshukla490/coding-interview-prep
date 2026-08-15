class Solution {
	public:
	vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
	int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
		int n = mat.size();
		int m = mat[0].size();
		vector<vector<int>> vis(n, vector<int>(m, 0));
		
		if(mat[src[0]][src[1]] == 0 || mat[dest[0]][dest[1]] == 0)
              return -1;
		
		queue<vector<int>> q;
		q.push(src);
	    vis[src[0]][src[1]] = 1;
		
		int level = 0;
		
		while (!q.empty()) {
			
			int size = q.size();
			
			while (size--) {
				
				vector<int>temp = q.front();
				q.pop();
				
				if(temp == dest){
				    return level;
				}
				
				int row = temp[0];
				int col = temp[1];
				
				for (auto it : directions) {
					
					int new_r = row + it.first;
					int new_c = col + it.second;
					
					if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && mat[new_r][new_c] == 1 && vis[new_r][new_c]==0){
						q.push({new_r, new_c});
						vis[new_r][new_c] = 1;
					}
					
				}
				
			}
			level++;
		}
		return -1;
	}
};
