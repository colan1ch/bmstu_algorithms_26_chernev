#include <iostream>
#include <queue>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


std::vector< std::vector<int> > levelOrder(TreeNode *root) {
    std::vector< std::vector<int> > v;
    if (!root) return v;
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int cur_count = q.size();
        std::vector<int> cur_level;
        for (int i = 0; i < cur_count; ++i) {
            TreeNode *cur_node = q.front();
            cur_level.push_back(cur_node -> val);
            q.pop();
            if (cur_node -> left) q.push(cur_node -> left);
            if (cur_node -> right) q.push(cur_node -> right);
        }
        v.push_back(cur_level);
    }
    return v;
}


int main() {
    TreeNode *l3 = new TreeNode(6);
    TreeNode *r3 = new TreeNode(11);
    TreeNode *r2 = new TreeNode(8, l3, r3);
    TreeNode *l2 = new TreeNode(16);
    TreeNode *root = new TreeNode(9, l2, r2);
    std::vector< std::vector<int> > ans = levelOrder(root);

    for (int i = 0; i < ans.size(); ++i) {
        for (int j : ans[i]) {
            std::cout << j << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}