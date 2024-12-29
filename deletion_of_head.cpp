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
void traverse(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<"NULL";
}

void deletionAtStart(node* &head){

    if(head==NULL){
        return;
    }

    node*temp = head;
    head = head->next;
    free(temp);
}


int main(){
    node* q1 = new node(4);
    node* q2 = new node(48);
    q1->next=q2;
    traverse(q1);
    cout<<endl;
    deletionAtStart(q1);
    traverse(q1);
}