#include<iostream>
using namespace std;

//given the head of linked list,delete every alternate element
//from the list starting from the second element.

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

void deleteulternate(node*&head){
    node*temp = head;
    while(temp->next!=NULL&&temp->next->next!=NULL){
        node*deletenode = temp->next;
        temp->next=temp->next->next;
        free(deletenode);
    }
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
    deleteulternate(head);
    traverse(head);

}