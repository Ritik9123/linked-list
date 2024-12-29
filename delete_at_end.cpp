#include<iostream>
using namespace std;

class node{
    public:
    int value;
    node* next;

    node(int v){
        value = v;
        next = NULL;
    }
};

void traverse(node*head){
    node*temp = head;
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<"NULL";
}

void deleteAtEnd(node*&head){

    if(head==NULL){
        return;
    }
    node*secondend = head;
    while(secondend->next->next!=NULL){
        secondend=secondend->next;
    }
    node*end = secondend->next;
    secondend->next = NULL;
    free(end);
}

int main(){
    node* a1 = new node(7);
    node* a2 = new node(74);
    node* a3 = new node(56);
    a1->next = a2;
    a2->next = a3;
    traverse(a1);
    cout<<endl;
    deleteAtEnd(a1);
    traverse(a1);
}