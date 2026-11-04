class Solution {
public:
    void solve(int node, vector<vector<int>>& adj, vector<int>& vis) {
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            for (int i = 0; i < adj[a].size(); i++) {
                int b = adj[a][i];
                if (!vis[b]){
                    vis[b] = 1;
                    q.push(b);
            }
        }
    }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size = connections.size();
        if (size < n - 1)
            return -1;
        vector<vector<int>> adj(n);
        for (auto it : connections) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int c = 0;
        for (int i = 0; i < vis.size(); i++) {
            if (vis[i] == 0) {
                solve(i, adj, vis);
                c++;
            }
        }
        return c - 1;
    }
};