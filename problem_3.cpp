#include<iostream>
using namespace std;

class node{
    public:
    int value;
    node*next;

    node(int v){
        value = v;
        next = NULL;
    }
};
void traverse(node*head){
    node*temp = head;
    while(temp!=NULL){
        cout<<temp->value<<"->";
        temp = temp->next;
    }
    cout<<"NULL";

}

void reverse(node*&head){
    node*previous = NULL;
    node*current = head;
    node*next;
    while(current){
        next = current->next;
        current->next=previous;
        previous=current;
        current=next;
    }
    head = previous;

}


int main(){
    node* a1 = new node(16);
    node* a2 = new node(15);
    node* a3 = new node(14);
    node* a4 = new node(13);
    node* a5 = new node(12);
    node* a6 = new node(11);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    a5->next = a6;
    node*head = a1;
    traverse(head);
    cout<<endl;
    reverse(head);
    traverse(head);
}