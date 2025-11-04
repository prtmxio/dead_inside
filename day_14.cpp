#include <bits/stdc++.h>
#include <climits>
#include <cstddef>
#include <iostream>
#include <queue>
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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(root == NULL) return res;
    queue<TreeNode*> q;
    bool ltr = true;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int> lvl(n);
        for(int i = 0; i < n; i++){
            TreeNode* temp = q.front();
            q.pop();
            int ix = (ltr) ? i : (n - 1 - i);
            lvl[ix] = temp->val;
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
        ltr = !ltr;
        res.push_back(lvl);
    }
    return res;
}

bool is_leaf(TreeNode* node){
    return (node->left == NULL && node->right == NULL);
}

void left_bound(TreeNode* node, vector<int>& res){
    if (node == NULL) return;
    if (is_leaf(node)) return;

    res.push_back(node->val);
    if (node->left) left_bound(node->left, res);
    else left_bound(node->right, res);

}

void leaves(TreeNode* node, vector<int>& res){
    if (node == NULL) return;
    if(is_leaf(node)) {
        res.push_back(node->val);
        return;
    }
    if(node->left) leaves(node->left, res);
    if(node->right) leaves(node->right, res);
}

void right_bound(TreeNode* node, vector<int>& res){
    if (node == NULL) return;
    if (is_leaf(node)) return;

    if (node->right) right_bound(node->right, res);
    else right_bound(node->left, res);
    res.push_back(node->val);
}

vector<int> acw_boundary(TreeNode* root){
    vector<int> res;
    if(!root) return res;
    if(!is_leaf(root)) res.push_back(root->val);
    // res = left_bound_w/o_leaf + leaves + right_bound_in_reverse_w/o_leaf
    left_bound(root->left, res);
    leaves(root, res);
    right_bound(root->right, res);
    return res;
}

void printTree(TreeNode* root, string indent, bool isLeft) {
    if (root == NULL) return;
    printTree(root->right, indent + (isLeft ? "│   " : "    "), false);

    cout << indent;

    if (isLeft) cout << "└── "; // Left child marker
    else  cout << "┌── "; // Right child marker (or root)

    cout << root->val << endl;

    printTree(root->left, indent + (isLeft ? "    " : "│   "), true);
}

bool helper(TreeNode* left, TreeNode* right){
    if( (left == NULL && right == NULL))  return true;
    if( (left == NULL || right == NULL))  return false;
    if(left->val != right->val) return false;
    return (left->val == right->val) && helper(left->left, right->right) && helper(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    return helper(root->left, root->right);
}

TreeNode* invertTree(TreeNode* root) {
    if(root == NULL) return root;
    // swap
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

vector<int> largestValues(TreeNode* root) {
    vector<int> res;
    if(root == NULL) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        int max_lvl = INT_MIN;
        for(int i = 0; i < n; i++){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
            max_lvl = max(max_lvl, temp->val);
        }
        res.push_back(max_lvl);
    }
    return res;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left =  new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(3);
    // root->right->left = new TreeNode(4);
    // root->right->right = new TreeNode(10);
    root->left->left->left = new TreeNode(10);
    // root->left->right->right = new TreeNode(14);

    vector<int> boundary = acw_boundary(root);
    printTree(root, "", false);
    // cout << "Bound : ";
    // for (int val : boundary) {
    //     cout << val << " ";
    // }
    cout << endl;

    vector<int> rsv = largestValues(root);
    for(auto i : rsv){
        cout << i << " ";
    }

    // cout << isSymmetric(root) << endl;
    // root = invertTree(root);
    // printTree(root, "", false);
    return 0;
}
