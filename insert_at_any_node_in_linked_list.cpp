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
        cout<< temp->value<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

void insertAt_Kth_node(node*&head,int position,int val){

    if(position==1){
        
        node* newnum =new node(val);
        newnum->next=head;
        head = newnum;
        return;
    }


    node* newnode = new node(val);
    node* previous = head;
    int count = 1;
    while(count<(position-1)){
        previous=previous->next;
        count++;
    }
    newnode->next=previous->next;
    previous->next=newnode;
}


int main(){
    node* n1 = new node(9);
    node* n2 = new node(18);
    node* n3 = new node(27);
    n1->next=n2;
    n2->next=n3;
    node*head = n1;
    traverse(head);
    cout<<endl;
    insertAt_Kth_node(head,2,6);
    traverse(head);

}