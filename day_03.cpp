#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums) {
    int rev = 0;
    int n = nums.size();
    bool check = (nums.at(0) >= nums.at(n - 1)) ? true : false;
    for(int i = 0; i < n - 1; i++){
        if(nums.at(i) > nums.at(i+1)){
            rev++;
        }
    }
    return (rev <= 1 && check);
}

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int i = 0; 
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j]; 
        }
    }
    return i + 1; 
}

void rev(vector<int> nums, int s, int e){
    while(s < e){
        // swap
        int temp = nums.at(s);
        nums.at(s) = nums.at(e);
        nums.at(e) = temp;
        ++s;
        --e;
    }
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if(n == 0) return;
    k = k % n;
    rev(nums, 0, n-1);
    rev(nums, 0, k-1);
    rev(nums, k, n-1);
}

bool compare(int a, int b){
    return a < b;
}

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    for(int i = 0; i < n; i++){
        if(nums.at(i) == 0) count++;
    }
    int k = 0;
    for(int i = 0; i < n; i++){
        if(nums.at(i) != 0){
            nums.at(k) = nums.at(i);
            ++k;
        }
    }
    for(int i = n - count; i < n; i++){
        nums.at(i) = 0;
    }

}


int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0;
    int temp = 0;
    for(auto x : nums){
        if(x == 1) ++count;
        if(x != 1) {
            temp = max(count, temp); 
            count = 0;
        }
    }
    return max(temp, count);
}


int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), compare);
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] != i){
            return i;
        }
    }
    return n;
}

int singleNumber(vector<int>& nums) {
    int ans = 0;
    map<int, int> m;
    for(auto x : nums){
        m[x]++;
    }
    for(auto &pair : m){
        if(pair.first == 1){
            ans = pair.second;
        }
    }
    return ans;
    
}

int majorityElement(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    map<int, int> m;
    for(auto x : nums){
        m[x]++;
    }  

    for(auto &pair : m){
        cout << pair.first << " | " << pair.second << endl;
    }
    
    for(auto &pair : m){
        if(pair.second > n/2){
            ans = pair.first;
        }
    }
    return ans;
}

int main(){
    vector<int> n = {3, 3, 4};
    int ans = majorityElement(n);
    cout << ans << "  ";
    // for(auto x : n){
    //     cout << x << "  ";
    // }
    return 0;
}