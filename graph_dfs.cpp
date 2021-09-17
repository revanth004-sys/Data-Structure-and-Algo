#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> adj[],int x, int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void dfs(vector<int> adj[], int x){
    vector<int> visited(7,0);
    stack<int> st;
    st.push(x);
    
    while(!st.empty()){
        int s = st.top();
        st.pop();
        
        if( visited[s]!=1 ){
            cout<<s<<" ";
            visited[s]=1;
        }
        
        for(auto i:adj[s]){
            if(visited[i]!=1){
                st.push(i);
            }
        }
    }
}

int main(){
   vector<int> adj[7];
   addedge(adj,0,1);
   addedge(adj,0,2);
   addedge(adj,1,3);
   addedge(adj,1,4);
   addedge(adj,1,5);
   addedge(adj,2,6);
   dfs(adj,0);
}