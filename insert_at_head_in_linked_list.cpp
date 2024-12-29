#include<iostream>
using namespace std;

class node{
    public:
    int value;
    node* next;

    node(int v){
        value = v;
        next =NULL;
    }
};
void traverse(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->value<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

void insertathead(node* &head,int n){
    node* new_num = new node(n);
    new_num->next = head;
    head = new_num;
}


int main(){

    node* num1= new node(5);
    node* num2= new node(10);
    num1->next=num2;
    node*head=num1;
    
    traverse(head);
    cout<<endl;
    insertathead(head,15);
    traverse(head);
}