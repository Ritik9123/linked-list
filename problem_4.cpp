#include<iostream>
using namespace std;
//check Palindrome
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

bool checkPalindrome(node*head){
    if(head->next==NULL){
        return true;
    }
    // find mid
    node*slow = head;
    node*fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    //reverse
    node*prev = NULL;
    node*curr = slow->next;
    node*next;
    while (curr)
    {
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    //compare
    node*head2 = prev;
    while(head2){
        if(head->value!=head2->value){
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }

    return true;
    
}

int main(){
    node* a1 = new node(1);
    node* a2 = new node(5);
    node* a3 = new node(10);
    node* a4 = new node(10);
    node* a5 = new node(5);
    node* a6 = new node(1);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    a5->next = a6;
    node*head = a1;
    traverse(head);
    cout<<endl;
    cout<<checkPalindrome(head);
    

}