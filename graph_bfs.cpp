#include <iostream>
#include<vector>
#include<queue>
using namespace std;

void addedge(vector<int> adj[],int x, int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void bfs(vector<int> adj[] , int x){
    queue<int> q;
    vector<int> visited;
    for(int i=0; i<5; i++){
        visited.push_back(0);
    }
    q.push(x);
    visited[x]=1;
    
    while(!q.empty()){
        int i = q.front();
        for(int ele: adj[i]){
            if(visited[ele]==0){
                q.push(ele);
                visited[ele]=1;
            }
        }
        cout<<i<<" ";
        q.pop();
    }
    
}

int main(){
    vector<int> adj[5];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,3);
    addedge(adj,1,2);
    addedge(adj,2,4);
    addedge(adj,3,4);
    bfs(adj,1);
    
}
