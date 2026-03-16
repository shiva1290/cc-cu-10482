#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int>& vis, stack<int>& st, vector<int> adj[]) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            DFS(it, vis, st, adj);
        }
    }
    st.push(node);
}

vector<int> dfstopoSort(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            DFS(i, vis, st, adj);
        }
    }
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

vector<int> bfstopoSort(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++) {
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto neighbours : adj[node]){
            indegree[neighbours]--;
            if(indegree[neighbours] == 0){
                q.push(neighbours);
            }
        }
    }
    return ans;
}

int main(){

    int V = 6;
    vector<int> adj[6];
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(5);
    adj[4].push_back(5);
    adj[4].push_back(0);

    vector<int> bfsans = bfstopoSort(V, adj);
    vector<int> dfsans = dfstopoSort(V, adj);

    cout << "BFS (Kahn's): ";
    for (auto it : bfsans) cout << it << " ";
    cout << "\nDFS:          ";
    for (auto it : dfsans) cout << it << " ";

    return 0;
}
