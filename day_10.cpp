#include <bits/stdc++.h>
#include <vector>
using namespace std;

// (ix, diff, arr)
// either pick ix or never pick it up
// let the recursion tree grow
void backtrack(int ix, int curr_sum, int target, vector<int>& candidates, vector<vector<int>>& res, vector<int> temp){
    int n = candidates.size();
    if(curr_sum == target){
        res.push_back(temp);
        return;
    }

    if(curr_sum > target || ix == n) return;
    temp.push_back(candidates.at(ix));
    backtrack(ix, curr_sum + candidates.at(ix), target, candidates, res, temp);
    temp.pop_back();
    backtrack(ix+1, curr_sum, target, candidates, res, temp);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res = {};
    vector<int> temp = {};
    backtrack(0, 0, target, candidates, res, temp);
    return res;;
}

void tracko(int ix, int curr_sum, int target, vector<int>& candidates, vector<vector<int>>& res, vector<int> temp){
    int n = candidates.size();
    if(curr_sum == target){
        res.push_back(temp);
        return;
    }

    if(curr_sum > target || ix == n) return;

    if(candidates.at(ix) <= target){
        temp.push_back(candidates.at(ix));
        tracko(ix + 1, curr_sum + candidates.at(ix), target, candidates, res, temp);
        temp.pop_back();
        while (ix + 1 < n && candidates[ix] == candidates[ix + 1]) {
            ix++;
        }
        tracko(ix + 1, curr_sum, target, candidates, res, temp);
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res = {};
    vector<int> temp = {};
    sort(candidates.begin(), candidates.end());
    tracko(0, 0, target, candidates, res, temp);
    return res;
}

int main(){
    int target = 8;
    vector<int> candidates = {10,1,2,7,6,1,5};
    vector<vector<int>> res = combinationSum2(candidates, target);
    for(auto a : res){
        cout << endl;
        for(auto b : a){
            cout << b << " ";
        }
    }
    return 0;
}
