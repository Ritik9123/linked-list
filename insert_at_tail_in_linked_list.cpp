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

void traverse(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<"NULL";
}

void insertattail(node*&head,int val){
    node* n = new node(val);
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
int main(){
    node* n1=new node(1);
    node* n2=new node(3);
    node* n3=new node(5);
    n1->next=n2;
    n2->next=n3;
    traverse(n1);
    cout<<endl;
    insertattail(n1,5);
    traverse(n1);
}