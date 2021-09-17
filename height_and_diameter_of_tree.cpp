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

int height(node* t){
    if(t == NULL){
        return 0;
    }
    int left = height(t->left);
    int right = height(t->right);
    int h;
    if(left > right){
        h = 1+left;
    }
    else{
        h = 1+right;
    }
    return h;
}

int diameter(node* t){
    int lh = height(t->left);
    int rh = height(t->right);
    return 1+lh+rh;
}

int main(){
    insert(3);
    insert(1);
    insert(2);
    insert(5);
    insert(4);
    insert(0);
    insert(7);
    int h = height(root);
    int d = diameter(root);
    cout<<"height of the tree is "<<h;
    cout<<"\ndiameter of the tree is "<<d;
    
}