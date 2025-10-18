#include <bits/stdc++.h>
using namespace std;


int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> seen;
    seen[0] = 1; // base case: sum = 0 has been seen once
    int count = 0, sum = 0;

    for (int num : nums) {
        sum += num;
        if (seen.count(sum - k)) {
            count += seen[sum - k];
        }
        seen[sum]++;
    }

    return count;
}

int main(){

    return 0;
}