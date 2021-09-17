//dfs using recursion

#include<bits/stdc++.h>
using namespace std;

vector<bool> visited(7,false);

void dfs(vector<int> adj[], int x){
    visited[x]=true;
    cout<<x<<" ";
    for(int i=0; i< adj[x].size() ; i++){
        if(visited[adj[x][i]]!=true){
            dfs(adj,adj[x][i]);
        }
    }
}

int main(){
    vector<int> adj[7];
    
    for(int i=0; i<6; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj,0);
    
}