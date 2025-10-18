#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

void name_rec(int n, string name){
    if (n < 1)
        return;
    name_rec(n-1, name);
    cout << "pass : " << n << " | " << name << endl;

}

void sum_param(int i, int sum){
    if(i < 1){
        cout << "Sum : " << sum << endl;
        return; 
    }
    sum_param(i-1, sum+i);
}

int sum_nopar(int i){
    if(i < 1)
        return 0;

    return i + sum_nopar(i-1); 
}

int fac(int n){
    if(n < 2)
        return 1;

    return n * fac(n-1);
}

vector<int> rev(vector<int> v, int l, int r){
    if(l >= r)
        return v;

    // swap
    swap(v.at(l), v.at(r));
    return rev(v, l+1, r-1); 
}

vector<int> rev(vector<int> v, int i){
    if(i >= int(v.size() / 2))
        return v;

    // swap
    swap(v.at(i), v.at(v.size() - i - 1));
    return rev(v, i + 1); 
}

bool palindrome(string s, int i){
    if(i >= int(s.size() / 2))
       return true;

    if(s.at(i) != s.at(s.size() - i - 1)) 
        return false;

    return palindrome(s, i+1);
}

int fibo(int n){
    if(n <= 1) return n;
    return fibo(n-1) +fibo(n-2);
}

int main() {
    int n;
    // cin >> n;
    // cout << "Fac : " << fac(n) << endl;
    // vector<int> v = {1, 2, 3, 4};
    // vector<int> ans = rev(v, 0);
    // for(auto x : ans){
    //     cout << x << " ";
    // }
    
    string s = "acda";
    for(int i = 0; i < 10; i++) cout << fibo(i) << endl; 
    return 0;
}

