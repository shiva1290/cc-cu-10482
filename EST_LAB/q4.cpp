#include<bits/stdc++.h>
using namespace std;


void DFS(int i,vector<vector<int>>&adj,stack<int>&st,vector<bool>&visited){
    visited[i]=true;
    for(auto it : adj[i]){
        if(!visited[it]){
            DFS(it,adj,st,visited);
        }
    }
    st.push(i);
}
int main(){
    
    int V;
    int E;
    cin>>V>>E;
    vector<vector<int>> arr(V);
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
    }
    vector<bool>visited(V,false);
    stack<int>st;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            DFS(i,arr,st,visited);
        }
    }
    if(st.size()!=V) {
        cout<<"Topo Sort not possible";
        return 0;
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}