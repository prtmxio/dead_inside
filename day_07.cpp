#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
}

int largest(vector<int> v){
    int max = 0;
    int n = v.size();
    for(auto i = 1; i < n; i++){
        if(v[i] > v[max]) max = i;
    }
    return max;
}

int sec_largest(vector<int> v){
    int n = v.size();
    int max = 0;
    int sec = -1;
    for(int i = 1; i < n; i++){
        if(v[i] > v[max]) max = i;
    }
    for(int i = 0; i < n; i++){
        if(v[i] != v[max]){
            if(v[i] > v[sec]) sec = i;
        } else {
            continue;
        }
    }
    return sec;
}

int sec_optimal(vector<int> v){
    int sec = -1;
    int max = 0;
    int n = v.size();

    for(int i=0; i < n; i++){
        if(v[i] > v[max]){
            sec = max;
            max = i;
        } else if(v[i] > v[max] && v[i] < v[sec]){
            sec = i;
        }
    }
    
    return sec;
}

bool check_sort(vector<int> v){
    return true;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 10, -12, 9, 20};
    cout << check_sort(v) << endl;
    return 0;
}

