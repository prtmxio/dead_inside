#include <algorithm>
#include <bits/stdc++.h>
#include <charconv>
#include <climits>
#include <cstddef>
#include <string>
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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

string removeOuterParentheses(string s) {
    int opens = 0;
    string ans = "";
    for(char i : s){
        if(i == '('){
            if(opens > 0) ans += i;
            opens++;
        } else {
            opens--;
            if(opens > 0) ans += i;
        }
    }
    return ans;
}

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 1) return strs[0];
    string prefix = "";
    if(strs[0].empty()) return prefix;
    int j = 0;
    for(auto i : strs[0]){
        bool sub = true;
        char ref = strs[0][j];
        for(int k = 1; k < strs.size(); k++){
            if(ref != strs[k][j] || j >= strs[k].size()){
                sub = false;
                break;
            }
        }
        if(!sub) return prefix;
        prefix += ref;
        if(sub && j+1 < strs[0].size()) ++j;
    }
    return prefix;
}

string rle(string n){
    string ans = "";
    int i = n.size() - 1;
    while(i >= 0){
        char ld = n[i];
        int count = 0;
        while(i >= 0 && n[i] == ld){
            --i;
            ++count;
        }
        string ch = to_string(count);
        ch += ld;
        reverse(ch.begin(), ch.end());
        ans += ch;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string countAndSay(int n) {
    if(n == 1) return "1";
    return rle(countAndSay(n-1));
}

ListNode* swapPairs(ListNode* head) {
    ListNode* temp = new ListNode(0);
    temp->next = head;
    ListNode* prev = temp;
    while(prev->next != NULL && prev->next->next != NULL){
        ListNode* a = prev->next;
        ListNode* b = a->next;
        //swap
        prev->next = b;
        a->next = b->next;
        b->next = a;
        prev = a;
    }
    return temp->next;
}

string multiply(string num1, string num2) {
    string res = "";
    if (num1 == "0" || num2 == "0") return "0";
    int m1 = num1.size();
    int m2 = num2.size();
    vector<int> ans(m1 + m2, 0);
    for(int i = m1-1; i >= 0; --i){
        for(int j = m2-1; j >= 0; --j){
            int carry = i + j;
            int val = i + j + 1;
            int prod = (num1[i] - '0') * (num2[j] - '0');
            int sum = ans[val] + prod;
            ans[val] = sum%10;
            ans[carry] += sum/10;
        }
    }

    for(int i : ans){
        if(res.empty() && i == 0) continue;
        res.push_back(i + '0');
    }
    return res.empty() ? "0" : res;
}


int main(){
    vector<string> v = {"flower","flow","flight"};
    // cout << countAndSay(4) << endl;
    // cout << rle("33") << endl;
    // countAndSay(4);
    return 0;
}
