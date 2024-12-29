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
    while(temp){
        cout<<temp->value<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

void rotateByK(node*&head, int k){
    //find total number of node
    node*temp = head;
    int n=1;
    while(temp->next){
        n++;
        temp = temp->next;
    }
    //find k
    k = k%n;
    if(k==0){
        return;
    }
    //last node to head linking
    temp->next=head;
    //n-k th node

    temp = head;
    
    for(int i=1;i<n-k;i++){
        temp = temp->next;
    }
    //new head
    node*newhead = temp->next;
    //n-k th node pointing to null
    temp->next = NULL;

    head = newhead;


}

int main(){
    node* a1 = new node(1);
    node* a2 = new node(5);
    node* a3 = new node(10);
    node* a4 = new node(15);
    node* a5 = new node(51);
    node* a6 = new node(111);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    a5->next = a6;
    node*head = a1;
    traverse(head);
    cout<<endl;
    rotateByK(head,2);
    traverse(head);

}