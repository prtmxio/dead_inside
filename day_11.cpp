#include <bits/stdc++.h>
#include <cstddef>
#include <string>
#include <vector>
using namespace std;


// -                            0-1-2  (0 -> n)           3-4-5 (n -> n+1)
// 6-7-8  (n+2 -> n+4)          9-10-11 (n+4 -> n+6)      12-13-14 (n+6 -> n+8)
// 15-16-17-18 (n+8 -> n+11)    19-20-21 (n+11 -> n+13)   22-23-24-25 (n+13 -> n+16)
//
//  45 - (9-k) (8-k)/2
//

vector<int> get_range(int n){
    int s = 3*(n-2);
    if( n < 7) {
        return vector<int>{s, s+2};
    } else if(n == 7){
        return vector<int>{s, s+3};
    } else if(n == 8){
        return vector<int> {s+1, s+3};
    } else if(n == 9){
        return vector<int> {s+1, s+4};
    }

    return vector<int> {};
}

void helper(string p, string up, vector<string>& res){
    if(up.size() == 0){
        res.push_back(p);
        return;
    }
    int n = up.size();
    char dig = up[0];
    vector<int> rng = get_range(up[0] - 48);
    for(int i = rng[0]; i <= rng[1]; i++){
        char ch = char('a' + i);
        helper(p+ch, up.substr(1, n), res);
    }

}

vector<string> letterCombinations(string digits) {
    string p = "";
    vector<string> res;
    helper(p, digits, res);
    return res;
}

void backtrack(int k, int curr_sum, int s, int n, vector<int> temp, vector<vector<int>>& res){
    if(curr_sum == n && temp.size() == k){
        res.push_back(temp);
        return;
    }
    if(curr_sum > n || temp.size() > k || s + curr_sum > n || s > 9) return;
    temp.push_back(s);
    backtrack(k, curr_sum + s, s+1, n, temp, res);
    temp.pop_back();
    backtrack(k, curr_sum, s+1, n, temp, res);
}

vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res = {};
        vector<int> temp = {};
        int max_sum = (19*k - k*k)/2;
        if(n > max_sum) {
            return res;
        } else if(n == max_sum){
            int i = 9;
            while(temp.size() < k){
                temp.push_back(i--);
            }
            res.push_back(temp);
            return res;
        }
        backtrack(k, 0, 1, n, temp, res);
        return res;
}

int main(){
    vector<string> ans = letterCombinations("");
    for(auto a : ans){
        cout << a << " ";
        // for(auto b : a){
        //     cout << b << " ";
        // }
    }

    // cout << '1' + 0 - 48<< endl;
    return 0;
}
