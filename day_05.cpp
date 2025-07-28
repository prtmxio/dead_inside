#include<bits/stdc++.h>
using namespace std;


void setter(vector<vector<int>>& matrix, int row, int col){
    for(int i = 0; i < matrix.size(); i++){
        matrix[i][col] = 0;
    }
    for(int i = 0; i < matrix[row].size(); i++){
        matrix[row][i] = 0;
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    vector<vector<int>> ref = matrix;
    for(int i = 0; i < ref.size(); i++){
        for(int j = 0; j < ref[i].size(); j++){
            if(ref[i][j] == 0){
                setter(matrix, i, j);
            }
        }
    }
}

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) {
        return;
    }
    int pivot = -1;
    for (int i = n - 2; i >= 0; --i) {
        if (nums[i] < nums[i+1]) {
            pivot = i;
            break;
        }
    }
    if (pivot == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = n - 1; i > pivot; --i) {
        if (nums[i] > nums[pivot]) {
            swap(nums[pivot], nums[i]);
            break;
        }
    }
    reverse(nums.begin() + pivot + 1, nums.end());
}

vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> p;
    vector<int> n;
    for(auto x : nums){
        if(x >= 0) p.push_back(x);
        else n.push_back(x);
    }
    int k = 0;
    int i = 0;
    int s = nums.size() / 2;
    while(i < s){
        nums[k] = p[i];
        nums[k+1] = n[i];
        i++;
        k += 2;
    }       
    return nums;
}

int maxProfit(vector<int>& prices) {
    int prof = 0;
    int b = 0; // buy
    int s = 1; // sell
    int n = prices.size();

    while(s < n){
        if(prices[b] < prices[s]){
            prof = max(prof, prices[s] - prices[b]);
        } else {
            b = s;
        }
        s++;
    }
    
    return prof;
}

int main(){
    vector<int> v = {7,1, 5, 3, 6, 4};
    int ans = maxProfit(v);
    cout << ans << endl;
    return 0;
}