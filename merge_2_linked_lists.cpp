#include <iostream>
using namespace std;

class node{
    public:
      int data;
      node* link;
};
node* root = NULL;

node* merge(node* l1, node* l2){
    if(l1==NULL)
        return l2;
        
    if(l2==NULL)
        return l1;
    
    node* temp;
    
    if(l1->data < l2->data)
    temp=l1, l1=l1->link;
    else
    temp=l2 , l2=l2->link;
    
    root=temp;
    
    
    while(l1!=NULL && l2!=NULL){
        if(l1->data <= l2->data){
            temp ->link=l1;
            l1 = l1->link;
            temp=temp->link;
        }
        else 
        {
            temp ->link=l2;
            l2 = l2->link;
            temp=temp->link;
        }
    }
    if(l1 == NULL)
        temp->link=l2;
    if(l2 == NULL)
        temp->link=l1;
        
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
    
   
   root=merge(l1,l2);
    
    display(root);
    
}