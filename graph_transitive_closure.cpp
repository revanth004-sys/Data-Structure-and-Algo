#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> v;
int t[10][10];

void addedge(vector<int> adj[], int x,int y){
    adj[x].push_back(y);
    if( find(v.begin(),v.end(),x)==v.end() )
         v.push_back(x);
    if( find(v.begin(),v.end(),y)==v.end() )
         v.push_back(y);     
    
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
        t[x][i]=1;
        for(int ele: adj[i]){
            if(visited[ele]==0){
                q.push(ele);
                visited[ele]=1;
            }
        }
        
        q.pop();
    }
}

int main(){
    vector<int> adj[10];
    
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,3);
    addedge(adj,4,1);
    addedge(adj,5,2);
    addedge(adj,5,6);
    addedge(adj,6,4);
    addedge(adj,4,0);
    for(int i=0; i<v.size();i++){
        for(int j=0; j<v.size(); j++){
            t[i][j]=0;
        }
    }
    for(auto i:v){
        bfs(adj,i);
    }
    for(int i=0; i<v.size();i++){
        for(int j=0; j<v.size(); j++){
            cout<<t[i][j]<<" ";
        }
        cout<<"\n";
    }
}