#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) return -1;
        int cols = grid[0].size();
        int fresh = 0;
        vector<pair<int, int>> rotten;
    
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) fresh++;
                else if (grid[r][c] == 2) rotten.push_back({r, c});
            }
        }
        
        int minutes = 0;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!rotten.empty() && fresh > 0) {
            minutes++;
            vector<pair<int, int>> new_rotten;
            for (auto [x, y] : rotten) {
                for (auto [dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        new_rotten.push_back({nx, ny});
                    }
                }
            }
            rotten = new_rotten;
        }
        
        return fresh == 0 ? minutes : -1;
    }
};