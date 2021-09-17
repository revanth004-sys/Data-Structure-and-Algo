#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> v;

void addedge(vector<int> adj[], int x,int y){
    adj[x].push_back(y);
    if( find(v.begin(),v.end(),x)==v.end() )
         v.push_back(x);
    if( find(v.begin(),v.end(),y)==v.end() )
         v.push_back(y);     
    
}

int bfs(vector<int> adj[] , int x){
    queue<int> q;
    vector<int> visited;
    int c=1;
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
                c++;
                visited[ele]=1;
            }
        }
        q.pop();
    }
    return c;
}

int main(){
    vector<int> adj[10];
    vector<int> v1;
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,3);
    addedge(adj,4,1);
    addedge(adj,5,2);
    addedge(adj,5,6);
    addedge(adj,6,4);
    addedge(adj,4,0);
    for(auto i:v){
        v1.push_back( bfs(adj,i) );
    }
    for(int i=0;i<v1.size();i++){
        if(v1[i]==v.size()){
            cout<<"mother vertex is "<<v[i];
            return 0;
        }
    }
}