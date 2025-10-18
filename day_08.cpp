#include <bits/stdc++.h>
#include <climits>
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


double myPow(double x, int n) {
    if(x == 1) return 1;
    if(x == -1) return (n % 2 == 0) ? 1 : -1;
    if(n <= INT_MIN) return 0;
    if(n == 0) return 1;
    if(n < 0) return 1 / myPow(x, -n);
    if(n%2 == 0) {
        double k = myPow(x, n/2);
        return k*k;
    } else {
        return x * myPow(x, (n-1));
    }
}


vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* temp = st.top();
        st.pop();
        ans.push_back(temp->val);
        if(temp->right != NULL) st.push(temp->right);
        if(temp->left != NULL) st.push(temp->left);
    }
    return ans;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> temp;
        int size = q.size();
        for(int i = 0; i < size; i++){
            TreeNode* node = q.front();
            q.pop();
            temp.push_back(node->val);

            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);

        }
        ans.push_back(temp);
    }
    return ans;
}

int helper(TreeNode* root, int& m){
    if(root == NULL) return 0;
    int left = helper(root->left, m);
    int right = helper(root->right, m);
    m = max(m, left + right + root->val);
    int k = root->val + max(left, right);
    return (k < 0) ? 0 : k;
}

int maxPathSum(TreeNode* root) {
    int m = INT_MIN;
    helper(root, m);
    return m;
}



int main(){
    TreeNode* root = new TreeNode(2);
    root->right = new TreeNode(-1);
    // root->right->left = new TreeNode(3);
    // vector<vector<int>> vec = levelOrder(root);
    // for(auto i : vec){
    //     cout << endl;
    //     for(auto v : i){
    //         cout << v << " ";
    //     }
    // }
    cout << maxPathSum(root) << endl;
    return 0;
}
