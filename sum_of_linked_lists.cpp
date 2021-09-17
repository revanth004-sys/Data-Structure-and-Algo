#include <iostream>
using namespace std;

class node{
    public:
      int data;
      node* link;
};
node* root = NULL;

node* sum(node* l1, node* l2){
    node* p = l1;
    node* temp = new node();
    root = temp;
    int c=0;
    while(p){
        c++;
        p = p->link;
    }
    while(c>0){
        temp->data = l1->data + l2->data;
        l1 = l1->link;
        l2 = l2->link;
        temp->link = new node();
        temp = temp->link;
        c--;
    }
    temp->link = NULL;
    
    return root;
    
}

void display(node* l){
    node* p = l;
    while(p){
        cout<<p->data<<" ";
        p=p->link;
    }
}

int main(){
    node* l1 = new node();
    l1->link = new node();
    l1->link->link = new node();
    
    l1->data = 2;
    l1->link->data = 5;
    l1->link->link->data = 7;
    l1->link->link->link = NULL;
    
    node* l2 = new node();
    l2->link = new node();
    l2->link->link = new node();
    
    l2->data = 3;
    l2->link->data = 4;
    l2->link->link->data = 6;
    l2->link->link->link = NULL;
    
   
   root=sum(l1,l2);
    
    display(root);
    
}