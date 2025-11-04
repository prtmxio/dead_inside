#include<bits/stdc++.h>
using namespace std;

// string abbr(string word){
//     int n = word.size();
//     if(n > 10) {
//         string mid = to_string(n-2);
//         string ans = "";
//         ans += word[0];
//         ans += mid;
//         ans += word[n-1];
//         return ans;
//     }
//     return word;
// }



int main(){
    // int n;
    // cin >> n;
    // for(int i = 0; i < n; i++){
    //     string word;
    //     cin >> word;
    //     cout << abbr(word) << endl;
    // }

    // int n;
    // cin >> n;
    // int attempt = 0;
    // for(int i = 0; i < n; i++){
    //     int k = 3;
    //     int a, b, c;
    //     cin >> a >> b >> c;
    //     if(a+b+c >= 2) attempt++;
    // }
    // cout << attempt;

    int n, k;
    cin >> n >> k;
    int count = 0;
    vector<int> all(n);
    for(int i = 0; i < n; i++){
        int s;
        cin >> s;
        all[i] = s;
    }
    for(int i = 0; i < n; i++){
        if(all[i] >= all[k-1] && all[i] > 0) count++;
    }
    cout << count << endl;


    return 0;
}
