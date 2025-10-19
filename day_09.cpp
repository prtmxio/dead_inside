#include <bits/stdc++.h>
#include <vector>
using namespace std;

void helper(int l, int r, int n, string p, vector<string>& ans){
    if(p.length() == 2 * n) {
        ans.push_back(p);
        return;
    }

    if(l < n) helper(l+1, r, n, p+'(', ans);
    if(l > r) helper(l, r+1, n, p+')', ans);

}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    helper(0, 0, n, "", ans);
    return ans;
}

void checker(int k, vector<int>p, vector<int> nums, vector<vector<int>>& ans){
    if( k == 0){
        ans.push_back(p);
        return;
    }
    checker(k-1, p, nums, ans);
    p.push_back(nums.at(nums.size() - k));
    checker(k-1, p, nums, ans);

}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    int k = nums.size();
    checker(k, {}, nums, ans);
    return ans;
}

int main(){
    vector<int> k = {1,2, 3};
    vector<vector<int>> vec = subsets(k);
    for(auto i : vec){
        cout << endl;
        for(auto v : i){
            cout << v << " ";
        }
    }
    return 0;
}
