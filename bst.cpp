#include<iostream>
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

int search(int x){
    node* t = root;
    while(t){
        if(t->data == x ){
            return 1;
        }
        else if(t->data < x){
            t = t->right;
        }
        else{
            t = t->left;
        }
    }
    return 0;
}

void inorder(node* t){
    if(t->left){
        inorder(t->left);
    }
    cout<< t->data<<" ";
    if(t->right){
        inorder(t->right);
    }
}

int main(){
    insert(10);
    insert(5);
    insert(20);
    insert(7);
    insert(15);
    inorder(root);
    search(15)?cout<<"yes":cout<<"no";
}