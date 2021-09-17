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

void reverse(){
    node* temp = root;
    node* prevnode = NULL;
    node* p;
    while(temp){
        p = temp->link;
        temp->link = prevnode;
        prevnode = temp;
        temp = p;
    }
    root = prevnode;
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
    append(5);     // insertion at end
    append(10);
    append(15);
    append(20);
    append(25);
    reverse();
    display();
}
