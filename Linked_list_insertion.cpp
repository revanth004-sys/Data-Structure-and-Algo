// Linked Lists Using CPP

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* link;
};
node* root = NULL;

void append(int x){
    node* temp = new node();
    temp->data = x;
    temp->link = NULL;
    if(root==NULL){
        root = temp;
    }
    else{
        node* p = root;
        while(p->link!=NULL){
            p=p->link;
        }
        p->link = temp;
    }
}

void insert(int pos, int x){
    
    node* p = root;
    
    node* temp = new node();
    temp->data = x;
    temp->link = NULL;
    
    int i = 1;
    
    while(i < pos-1){
         p = p->link;
         i++;
    }
    node* q = p->link;
    p->link = temp;
    temp->link = q;
}

void at_front(int x){
    node* temp = new node();
    temp->data = x;
    temp->link = NULL;
    node* p = root;
    temp->link = p;
    root = temp;
    
}

void display(){
    node* temp = root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->link;
    }
}

int main()
{
    append(1);     // insertion at end
    append(2);
    append(3);
    append(4);
    append(5);
    insert(2,10);  // insertion at middle
    insert(2,30);
    insert(3,40);
    at_front(0);   // inserion at start
    at_front(-1);
    display();
}
