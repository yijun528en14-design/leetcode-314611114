class Solution {
public:
    int m, n;
    vector<vector<char>> board;
    string word;
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    bool dfs(int x, int y, int idx) {
        if (idx == word.size()) return true;  // 全部找到
        
        if (x < 0 || x >= m || y < 0 || y >= n) return false;
        if (board[x][y] != word[idx]) return false;

        char temp = board[x][y];
        board[x][y] = '#';  // 標記已使用

        for (int k = 0; k < 4; k++) {
            int nx = x + dirs[k][0];
            int ny = y + dirs[k][1];
            if (dfs(nx, ny, idx + 1)) return true;
        }

        board[x][y] = temp; // 回溯還原
        return false;
    }

    bool exist(vector<vector<char>>& b, string w) {
        board = b;
        word = w;
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0)) return true;
            }
        }
        return false;
    }
};