class Solution {
public:
    void DFS(vector<vector<int>>& a, vector<int>& color,vector<int>& g, int x){
        color[x] = 1;
        for(int i = 0; i < a[x].size(); i++){
            if (!color[a[x][i]] && g[a[x][i]]){
                DFS(a, color, g, a[x][i]);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>> a(n*m);
        vector<int> color(n*m), g(n*m);
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] == '1' && i - 1 >= 0 && grid[i-1][j] == '1'){
                    a[i*m + j].push_back((i-1)*m + j);
                }
                if (grid[i][j] == '1' && i + 1 < n && grid[i+1][j] == '1'){
                    a[i*m + j].push_back((i+1)*m + j);
                }
                if (grid[i][j] == '1' && j - 1 >= 0 && grid[i][j-1] == '1'){
                    a[i*m + j].push_back(i*m + j - 1);
                }
                if (grid[i][j] == '1' && j + 1 < m && grid[i][j + 1] == '1'){
                    a[i*m + j].push_back(i*m + j + 1);
                }
                g[i*m + j] = (grid[i][j] == '1');
            }
        }
        for(int i = 0; i < n*m; i++){
            if (!color[i] && g[i]){
                DFS(a, color, g, i);
                ans++;
            }
        }
        return ans;
    }
};