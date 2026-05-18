#include <iostream>
#include <vector>
#include <queue>


std::vector< std::vector<int> > updateMatrix(std::vector< std::vector<int> > &mat) {
    int n = mat.size();
    int m = mat[0].size();

    std::vector< std::vector<int> > distance(n, std::vector<int>(m, -1));
    std::queue< std::pair<int, int> > q;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 0) {
                distance[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto &d : directions) {
            int new_x = x + d[0];
            int new_y = y + d[1];
            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && distance[new_x][new_y] == -1) {
                distance[new_x][new_y] = distance[x][y] + 1;
                q.push({new_x, new_y});
            }
        }
    }
    return distance;
}


int main() {
    std::vector<std::vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    std::vector<std::vector<int>> result = updateMatrix(mat);
    for (const auto &row : result) {
        for (size_t j = 0; j < row.size(); ++j) {
            std::cout << row[j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}