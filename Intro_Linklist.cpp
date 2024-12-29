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
    node*temp = head;
    while(temp!=NULL){
        cout<<temp->value<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

void insertAtHead(node*&head,int num){
    node* newh = new node(num);
    newh->next = head;
    head = newh;
}

void insertAtTail(node*&head,int val){

    node* tail = new node(val);
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next=tail;
}

void insertAtAny(node*&head,int pos,int val){

    if(pos==1){
        insertAtHead(head,val);
        return;
    }


    node* newele = new node(val);
    node* prev = head;
    int count = 1;
    while(count<(pos-1)){
        prev = prev->next;
        count++;
    }
    newele->next=prev->next;
    prev->next=newele;
}

void deleteAtEnd(node* &head){
    node* secondlast=head;
    while(secondlast->next->next!=NULL){
        secondlast = secondlast->next;
    }
    node*lastnode = secondlast->next;
    secondlast->next=NULL;
    free(lastnode);
}

void deletionkth(node*head,int posi){

    if(head==NULL){
        return;
    }
    node*preposi = head;
    int count =1;
    while(count<(posi-1)){
        preposi=preposi->next;
        count++;
    }
    node* current = preposi->next;
    preposi->next=current->next;
    free(current);
}

int main(){
    node* h1 = new node(2);
    node* h2 = new node(3);
    node* h3 = new node(5);
    h1->next=h2;
    h2->next=h3;
    node*head = h1;
    traverse(head);
    cout<<endl;
    insertAtHead(head,8);
    traverse(head);
    cout<<endl;
    insertAtTail(head,9);
    traverse(head);
    cout<<endl;
    insertAtAny(head,1,422);
    traverse(head);
    cout<<endl;
    deleteAtEnd(head);
    traverse(head);
    cout<<endl;
    deletionkth(head,4);
    traverse(head);

}