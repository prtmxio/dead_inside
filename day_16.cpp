#include <bits/stdc++.h>
#include <climits>
#include <cstddef>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


bool canJump(vector<int>& nums) {
    int reach = 0; // farthest ix that can be reached
    int i = 0;
    int s = nums.size();
    while(i < s){
        if(reach >= s-1) return true;
        if(reach >= i){
            reach = max(reach, i + nums[i]);
        } else {
            return false;
        }
        ++i;
    }
    return true;
}

void helper(vector<int> p, vector<int>& v, vector<vector<int>>& res){
    if(p.size() == v.size()){
        res.push_back(p);
        return;
    }
    for(int i = 0; i < v.size(); i++){
        if(v[i] == INT_MAX) continue;
        if (i > 0 && v[i] == v[i-1] && v[i-1] != INT_MAX) continue;
        int temp = v[i];
        v[i] = INT_MAX;
        p.push_back(temp);
        helper(p, v, res);
        p.pop_back();
        v[i] = temp;

    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    helper({}, nums, res);
    return res;
}

ListNode* rotateRight(ListNode* head, int k) {
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    if(dummy->next == NULL) return head;
    int length = 0;
    ListNode* temp = dummy->next;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    if(length <= k) k = k%length;
    for(int i = 0; i < k; i++){
        ListNode* last = dummy->next;
        ListNode* last_prev = dummy->next;
        while(last_prev->next->next != NULL){
            last_prev = last_prev->next;
        }
        last = last_prev->next;
        last->next = dummy->next;
        last_prev->next = NULL;
        dummy->next = last;
    }
    return dummy->next;
}

void calc_path(int r, int c, int &count, int m, int n){
    if(r==m-1 || c==n-1){
        ++count;
        return;
    }

    if(r+1 < m) calc_path(r+1, c, count, m, n);
    if(c+1 < n) calc_path(r, c+1, count, m, n);
}

int uniquePaths(int m, int n) {
    int count = 0;
    calc_path(0, 0, count, m, n);
    return count;
}

void get_path(TreeNode* root, string path, vector<string> &res){
    path = path + to_string(root->val);
    if(root->left) get_path(root->left, path + "->", res);
    if(root->right) get_path(root->right, path + "->", res);
    if(!root->left && !root->right) res.push_back(path);

}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if(root) get_path(root, "", res);
    return res;
}

int main(){
    vector<int> v = {2,3,1,1,4};
    vector<vector<int>> ans = permuteUnique(v);
    cout << uniquePaths(3, 4) << endl;
    return 0;
}
