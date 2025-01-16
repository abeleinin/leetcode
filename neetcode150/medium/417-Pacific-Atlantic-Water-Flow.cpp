#include <vector>

using namespace std;

void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int i, int j)
{
    static const vector<pair<int,int>> directions = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    vis[i][j] = true;

    for (auto d : directions) {
        if (0 <= i+d.first && i+d.first < heights.size() &&
            0 <= j+d.second && j+d.second < heights[0].size() &&
            heights[i][j] <= heights[i+d.first][j+d.second])
        {
            if (!vis[i+d.first][j+d.second]) {
                dfs(heights, vis, i+d.first, j+d.second);
            }
        }
    }

    return;
}

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        vector<vector<bool>> pac(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atl(heights.size(), vector<bool>(heights[0].size(), false));

        for (int j = 0; j < heights[0].size(); j++){
            dfs(heights, pac, 0, j);
            dfs(heights, atl, heights.size()-1, j);
        }

        for (int i = 0; i < heights.size(); i++){
            dfs(heights, pac, i, 0);
            dfs(heights, atl, i, heights[0].size()-1);
        }

        for (int i = 0; i < heights.size(); i++){
            for (int j = 0; j < heights[0].size(); j++){
                if (pac[i][j] && atl[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};