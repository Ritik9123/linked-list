#include<iostream>
using namespace std;

//find middle of the linkedlist


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

int findmiddle(node*&head){
    node*slow = head;
    node*fast = head;

    while(fast !=NULL&& fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->value;
}

int main(){
    node* val1 = new node(78);
    node* val2 = new node(787);
    node* val3 = new node(781);
    node* val4 = new node(783);
    node* val5 = new node(7);
    val1->next=val2;
    val2->next=val3;
    val3->next=val4;
    val4->next=val5;
    node*head = val1;
    traverse(head);
    cout<<endl;
    cout<<findmiddle(head);
}