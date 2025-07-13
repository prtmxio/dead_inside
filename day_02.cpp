#include "bits/stdc++.h"
using namespace std;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size() + nums2.size();
    vector<int> ans;
    int i = 0, j = 0;

    // Merge two sorted arrays
    while(i < nums1.size() && j < nums2.size()) {
        if(nums1[i] <= nums2[j]) {
            ans.push_back(nums1[i++]);
        } else {
            ans.push_back(nums2[j++]);
        }
    }

    while(i < nums1.size()) ans.push_back(nums1[i++]);
    while(j < nums2.size()) ans.push_back(nums2[j++]);

    int m = n / 2;

    if(n % 2 == 0) {
        return (ans[m - 1] + ans[m]) / 2.0; 
    } 
    return ans[m];
}

int reverse(int x) {
  int rev = 0;
  while(x){
    if(rev < INT_MIN/10 || rev > INT_MAX/10) return 0;
    rev = rev*10 + (x%10);
    x /= 10;
  }
    return rev;
}

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int goodNodes(TreeNode* root) {
   
}

int maxArea(vector<int>& height){
    int max_water = 0;
    int i = 0;
    int j = height.size() - 1;
    while(i < j){
      max_water = max(max_water, (j-i)*min(height[i], height[j]));
      if(height[i] < height[j]) i++;
      else j--;
    }
    return max_water;
}

int orangesRotting(vector<vector<int>>& grid) {
        
}

int main(){
  cout << reverse(1534236469) << endl;
  return 0;
}
