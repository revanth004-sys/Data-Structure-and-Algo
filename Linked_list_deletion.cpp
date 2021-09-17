#include <iostream>

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
            p = p->link;
        }
        p->link = temp;
    }
}

void pop(){
    node* p = root;
    while(p->link->link!=NULL){
        p = p->link;
    }
    node* q = p->link;
    p->link = NULL;
    delete q;
}

void pop_front(){
    node* temp = root;
    root = temp->link;
    delete temp;
}

void erase(int pos){
    node* p = root;
    int i = 1;
    while(i<pos-1){
        p = p->link;
        i++;
    }
    node* q = p->link;
    p->link = q->link;
    q->link = NULL;
    delete q;
}

void display(){
    node* temp = root;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->link;
    }
}

int main(){
    append(1);
    append(2);
    append(3);
    append(4);
    append(5);
    append(6);
    append(7);
    pop();           // deletion at end
    pop();  
    pop_front();     // deletion at start
    pop_front();
    erase(2);        // deletion at certain position in middle
    display();
}