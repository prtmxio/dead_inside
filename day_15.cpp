#include <bits/stdc++.h>
#include <cstddef>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    // do BFS (node, col)
    // go left col-- else col++  :  for all nodes
    // while popping out from queue store them all in hashmap 0f that level only
    // add the level_hash map to the main hash while sorting the vector for each col
    // return min -> max from hashmap

    if(root == NULL) return ans;
    int col = 0;
    queue<pair<TreeNode* , int>> q;
    map<int, vector<int>> col_store;
    q.push({root, col});
    int min_col = 0, max_col = 0;
    while(!q.empty()){
        int size = q.size();
        map<int, vector<int>> level_map;
        for(int i = 0; i < size; i++){
            pair<TreeNode*, int> temp = q.front();
            q.pop();
            int currentCol = temp.second;
            if(temp.first->left != NULL) q.push({temp.first->left, currentCol - 1});
            min_col = min(min_col, currentCol - 1);
            if(temp.first->right != NULL) q.push({temp.first->right, currentCol + 1});
            max_col = max(max_col, currentCol + 1);
            level_map[temp.second].push_back(temp.first->val);
        }
        for(auto pair : level_map){
            sort(pair.second.begin(), pair.second.end());
            col_store[pair.first].insert(
                col_store[pair.first].end(),      // pos to insert
                pair.second.begin(), 
                pair.second.end()    
            );
           
        }
    }
    for (int i = min_col; i <= max_col; ++i) {
        if (col_store.count(i)) {
            ans.push_back(col_store[i]);
        }
    }
    return ans;
}

int main(){
    return 0;
}
