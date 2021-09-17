#include<iostream>
#include<queue>
using namespace std;

class node{
 public:
    int data;
    node* left;
    node* right;
};
node* root = NULL;

void insert(int x){
    node* temp = new node();
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL){
        root = temp;
    }    
    else{
        node* curr = root;
        node* p;
        while(curr){
            p = curr;
            if(temp->data < curr->data){
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
        if(temp->data < p->data){
            p->left = temp;
        }
        else{
            p->right = temp;
        }
    }
}

void sumAt(node* t,int k){
    if(t == NULL){
        return;
    }
    
    queue<node*> q;
    q.push(t);
    q.push(NULL);
    
    int level = 0;
    int sum = 0;
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        if(temp!=NULL){
            if(level == k)
                 sum = sum+temp->data;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    cout<<sum;
}

int main(){
    insert(3);
    insert(1);
    insert(2);
    insert(5);
    insert(4);
    insert(0);
    insert(7);
    sumAt(root,0);
    
}