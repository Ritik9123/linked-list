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
        temp = temp->next;
    }
    cout<<"NULL";
}

void deletionAtnode(node*&head,int n){
    if(n==1){

        node*temp = head;
        head = head->next;
        free(temp);
        return;

    }

    node* previous = head;
    int count = 1;
    while(count<n-1){
        previous = previous->next;
        count++;
    }
    node* current = previous->next;
    previous->next = current->next;
    free(current);

}

int main(){
    node* val1 = new node(78);
    node* val2 = new node(787);
    node* val3 = new node(781);
    node* val4 = new node(783);
    val1->next=val2;
    val2->next=val3;
    val3->next=val4;
    node*head = val1;
    traverse(head);
    cout<<endl;
    deletionAtnode(head,1);
    traverse(head);
}