class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        int time = 0;

        int arr[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        while (!q.empty()) {
            int size = q.size();
            bool a = false;

            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front();
                q.pop();

                int l = p.first;
                int k = p.second;

                for (int i = 0; i < 4; i++) {
                    int nr = l + arr[i][0];
                    int nc = k + arr[i][1];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        a = true;
                    }
                }
            }
            if (a == true)
                time++;
        }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1)
                        return -1;
                }
            }
        return time;
    }
};