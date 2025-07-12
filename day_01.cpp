#include<bits/stdc++.h>
using namespace std;

// Two Sum 
vector<int> twoSum(vector<int>& nums, int target){
  map<int, int> seen; // will contain nums -> index
  for(int i = 0; i < nums.size(); i++){
    int ref = target - nums[i];
    if(seen.count(ref)){
      return vector<int> {seen[ref], i};
    }
    seen[nums[i]] = i; // store index to the nums
  }
  return vector<int>{};
}


// Add Two numbers
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        current->next = new ListNode(sum % 10);
        current = current->next;
        carry = sum / 10;
    }

    return dummy->next;
}


// Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(string s){
  int l = 0;
  int max_length = 0;
  unordered_set<int> seen;
  for (int r = 0; r < s.size(); r++) {
      while (seen.count(s[r])) {
          seen.erase(s[l]);
          l++;
      }
      seen.insert(s[r]);
       max_length = max(max_length, r - l + 1);
  }
  return max_length;
}

int main(){
  return 0;
}
