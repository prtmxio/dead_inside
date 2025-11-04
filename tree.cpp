#include <bits/stdc++.h>
#include <climits>
#include <cstddef>
#include <stack>
#include <vector>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// DFS
void preorder(struct node* node){
    if(node == NULL) return;
    cout << node->data;
    preorder(node->left);
    preorder(node->right);
}

vector<int> itr_pre(struct node* node){
    vector<int> pre;
    if(node ==NULL) return pre;
    stack<struct node*> st;
    st.push(node);
    while(!st.empty()){
        struct node* temp = st.top();
        st.pop();
        pre.push_back(temp->data);
        if(temp->right != NULL) st.push(temp->right);
        if(temp->left != NULL) st.push(temp->left);

    }
    return pre;
}

void postorder(struct node* node){
    if(node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data;
}

vector<int> itr_post(struct node* node){
    vector<int> post;
    if(node == NULL) return post;
    stack<struct node*> st1;
    stack<struct node*> st2;
    st1.push(node);
    while(!st1.empty()){
        struct node* temp = st1.top();
        st1.pop();
        st2.push(temp);
        if(temp->left != NULL) st1.push(temp->left);
        if(temp->right != NULL) st1.push(temp->right);
        st2.push(st1.top());
        st1.pop();
    }
    while(!st2.empty()){
        post.push_back(st2.top()->data);
        st2.pop();
    }
    return post;
}

vector<int> itr_post_single(struct node* node){
    vector<int> post;
    stack<struct node*> st;
    while(node != NULL || !st.empty()){
        if(node != NULL){
            st.push(node);
            node= node->left;
        } else {
            struct node* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                post.push_back(temp->data);
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    post.push_back(temp->data);
                }
            } else {
                node = temp;
            }
        }
    }
    return post;
}

void inorder(struct node* node){
    if(node == NULL) return;
    inorder(node->left);
    cout << node->data;
    inorder(node->right);
}

vector<int> itr_in(struct node* node){
    vector<int> in;
    if(node == NULL) return in;
    stack<struct node*> st;
    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        } else {
            if(st.empty() == true) break;
            struct node* temp = st.top();
            st.pop();
            in.push_back(temp->data);
            node = temp->right;
        }
    }
    return in;
}

// BFS (level order traversal)
vector<vector<int>> levle_order(struct node* node){
    vector<vector<int>> ans;
    if(node == NULL) return ans;
    queue<struct node*> q;
    q.push(node);
    while(!q.empty()){
        int size = q.size();
        vector<int> lvl;
        for(int i=0; i<size;i++){
            struct node* temp = q.front();
            q.pop();
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
            lvl.push_back(temp->data);
        }
        ans.push_back(lvl);
    }
    return ans;
}


int max_Depth(struct node* root){
    if(root == NULL) return true;

    int lh = max_Depth(root->left);
    int rh = max_Depth(root->right);
    if(lh == -1) return -1;
    if(rh == -1) return -1;
    if(abs(lh - rh) > 1) return -1;

    return 1 + max(lh, rh);
}

bool is_balanced(struct node* root){
    return max_Depth(root) != -1;
}

int diameter(struct node* root, int& dia){
    if(root == NULL) return 0;
    int lh = diameter(root->left, dia);
    int rh = diameter(root->right, dia);
    dia = max(dia, lh+rh);
    return  1 + max(rh, lh);
}

int path_sum(struct node* root, int& max_sum){
    if(root == NULL) return 0;

    int left_sum = path_sum(root->left, max_sum);
    int right_sum = path_sum(root->right, max_sum);

    max_sum = (max_sum < 0) ? 0 : max_sum;
    max_sum = max(max_sum, left_sum + right_sum + root->data);
    return (root->data) + max(left_sum, right_sum);
}

bool equal_tree(struct node* r1, struct node* r2){
    if(r1 == NULL || r2 == NULL) return (r1 == r2);
    return (r1->data == r2->data) && equal_tree(r1->left, r2->left) && equal_tree(r1->right, r2->right);

}

void printTree(struct node* root, string indent, bool isLeft) {
    if (root == NULL) return;
    printTree(root->right, indent + (isLeft ? "│   " : "    "), false);

    cout << indent;

    if (isLeft) cout << "└── "; // Left child marker
    else  cout << "┌── "; // Right child marker (or root)

    cout << root->data << endl;

    printTree(root->left, indent + (isLeft ? "    " : "│   "), true);
}

int main(){
    struct node *root = new node(0);
    root->left = new node(1);
    root->right = new node(-2);
    root->left->right = new node(5);
    struct node *root_2 = new node(0);
    root_2->left = new node(1);
    root_2->right = new node(-2);
    root_2->left->right = new node(5);
    // root_2->left->left = new node(5);

    cout << equal_tree(root, root_2) << endl;

    // cout << root->data << endl;
    // cout << root->left->data << " and ";
    // cout << root->right->data << endl;
    // cout << root->left->right->data << endl;

    // cout << "Preorder : ";
    // // preorder(root);
    // vector<int> k = itr_pre(root);
    // for(auto i : k) cout << i;
    // cout << endl;

    // cout << "Postorder : ";
    // // postorder(root);
    // vector<int> k2 = itr_post(root);
    // for(auto i : k2) cout << i;
    // cout << endl;

    // cout << "Inorder : ";
    // // inorder(root);
    // vector<int> k3 = itr_in(root);
    // for(auto i : k3) cout << i;
    // cout << endl;

    // int dia = 0;
    // diameter(root, dia);
    // cout << "Diameter : " << dia << endl;

    // int max_sum = INT_MIN;
    // path_sum(root, max_sum);
    // cout << "Max_sum : " << max_sum << endl;

    // cout << "Level order traversal : " << endl;;
    // vector<vector<int>> v = levle_order(root);
    // for(auto lvl : v){
    //     for(auto i : lvl){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    // cout << "Max_depth : " << max_Depth(root) << endl;
    // cout << "is_balanced : " << is_balanced(root) << endl;

    return 0;
}
