#include <bits/stdc++.h>
#include <vector>
using namespace std;
int nodes;
vector<vector<int>> adj;
vector<bool> visited;

// DFS
void dfs(int ix){
    if(visited[ix]) return;
    visited[ix] = true;
    cout << "Node visited : " << ix << endl;
    for(int next_node : adj[ix]){
        dfs(next_node);
    }
}

// connected_components
void find_comps(){
    int count = 0;
    for(int i = 0; i < nodes; i++){
        if(!visited[i]){
            ++count;
            dfs(i);
        }
    }
    cout << "Total connected comps : "<< count << endl;
}

int main(){
    int edges;
    cout << "Nodes : ";
    cin >> nodes;
    cout << "Edges : ";
    cin >> edges;
    adj.resize(nodes);
    visited.resize(nodes, false);
    vector<int> comps;
    cout << "Lets feed the grpah..." << endl;
    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // int start_node = 0;
    // dfs(start_node);
    find_comps();
    return 0;
}
