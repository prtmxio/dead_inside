#include <bits/stdc++.h>
using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* temp = new ListNode(0);  
    temp->next = head;

    ListNode* fast = temp;
    ListNode* slow = temp;

    // Move fast ahead by n+1 steps
    for (int i = 0; i <= n; ++i) {
        fast = fast->next;
    }

    // Move both until fast reaches the end
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode* toDelete = slow->next;
    slow->next = toDelete->next;
    // delete toDelete;

    ListNode* newHead = temp->next;
    // delete temp;
    return newHead;
}


vector<int> values(ListNode* head){
    vector<int> ans;
    ListNode* temp = head;
    while(temp != nullptr){
        ans.push_back(temp->val);
        temp = temp->next;
    }
    return ans;
}


// ListNode* mergeKLists(vector<ListNode*>& lists) {
//     vector<int> ans;
//     ListNode* head = new ListNode(0);
//     for(int i = 0; i < lists.size(); i++){
//         vector<int> ref = values(lists.at(i));
//         for(auto x : ref){
//             ans.push_back(x);
//         }
//     }
//     sort(ans.begin(), ans.end());
//     ListNode dummy(0);
//     ListNode* curr = &dummy;

//     for (int val : ans) {
//         curr->next = new ListNode(val);
//         curr = curr->next;
//     }

//     return dummy.next;
        
// }


struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;  // less priority of a if this condition hit
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

    for (auto list : lists) {
        if (list != nullptr) {
            minHeap.push(list);
        }
    }

    ListNode dummy(0);
    ListNode* curr = &dummy;

    while (!minHeap.empty()) {
        ListNode* smallest = minHeap.top(); // samllest head
        minHeap.pop();

        curr->next = smallest;
        curr = curr->next;

        // If the list has more nodes, push the next node
        if (smallest->next != nullptr) {
            minHeap.push(smallest->next);
        }
    }

    return dummy.next;
}



vector<vector<int>> helper(vector<int>& arr, int target, int skipIndex) {
    unordered_map<int, int> m;
    set<vector<int>> result;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (i == skipIndex) continue;
        int needed = target - arr[i];
        if (m.count(needed) && m[needed] != skipIndex && m[needed] != i) {
            vector<int> triplet = {arr[i], needed};
            sort(triplet.begin(), triplet.end());
            result.insert(triplet);
        }
        m[arr[i]] = i;
    }

    vector<vector<int>> pairs;
    for (auto& pair : result) {
        pairs.push_back(pair);
    }
    return pairs;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        auto pairs = helper(nums, -nums[i], i);
        for (auto& pair : pairs) {
            pair.push_back(nums[i]);
            sort(pair.begin(), pair.end());
            ans.insert(pair);
        }
    }
    return vector<vector<int>>(ans.begin(), ans.end());
}    

void transpose(vector<vector<int>>& matrix){
    int n = matrix.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){  // only upper triangle
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
    

void rotate(vector<vector<int>>& matrix) {
    transpose(matrix);
    for(auto x : matrix){
        for(auto k : x){
            cout << k << " ";
        }
        cout << endl;
    }

    int s = 0;
    int e = matrix.size() - 1;
    while(s <= e){
        for(int i = 0; i < matrix.size(); i++){
            int temp = matrix[i][s];
            matrix[i][s] = matrix[i][e];
            matrix[i][e] = temp;
        }
        ++s;
        --e;
    } 
    cout << endl;

    for(auto x : matrix){
        for(auto k : x){
            cout << k << " ";
        }
        cout << endl;
    }
}





int main(){

    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    rotate(arr);

    return 0;
}