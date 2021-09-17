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

void print_level_order(node* t){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        cout<<temp->data<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
           q.push(temp->right);
        q.pop();   
    }
}

int main(){
    insert(3);
    insert(1);
    insert(2);
    insert(5);
    insert(4);
    insert(0);
    insert(7);
    print_level_order(root);
    
}