//count the number of nodes in a level//

#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> adj[], int x, int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void clevel_bfs(vector<int> adj[],int x,int l){
    queue<int> q;
    vector<int> visited;
    for(int i=0; i<7; i++){
        visited.push_back(0);
    }
    
    int count=0;
    int level=1;
    
    q.push(x);
    q.push(-1);
    visited[x]=1;
    
    while(!q.empty()){
        int t=q.front();
        
        if(t!=-1){
        
            q.pop();
    
            for(int ele: adj[t]){
                if(visited[ele]==0){
                q.push(ele);
                if(level==l){
                count++;
                }
                visited[ele]=1;
                }
            }
        }
        
        else{
            level++;
            q.pop();
            if(!q.empty()){
                q.push(-1);
            }
        }
        
    }
    cout<<count;
    
    
}

int main(){
    vector<int> adj[7];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,3);
    addedge(adj,1,4);
    addedge(adj,1,5);
    addedge(adj,2,6);
    clevel_bfs(adj,0,1);
}