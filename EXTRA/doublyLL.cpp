#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //comstructor
    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int val = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory free for"<<" "<<val<<endl;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

void insertAtHead(Node* &head,int d){
    if(head == NULL){                   // if list is empty.
        Node* temp = new Node(d);
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}
  

void insertAtTail(Node* &tail,int d){
    if(tail == NULL){                   // if list is empty.
        Node* temp = new Node(d);
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}


void insertAtposition(Node* &tail,Node* &head,int position,int d){
    if(position==1){
        insertAtHead(head,d);
        return;
    }

    Node* temp = head;
    Node* n = new Node(d);
    int c=1;
    while(c<position-1){
        temp = temp -> next;
        c++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail,d);
        return;
    }

    n -> next = temp -> next;
    temp -> next -> prev = n;
    n -> prev = temp;
    temp -> next = n;
}

void deleteNode(int position,Node* &head){
    //deleting first node
    if(position==1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete(temp);
    }
    else{
        //deleting any node
        Node* curr = head;
        Node* prev = NULL;
        int c=1;
        while(c<position){
            prev  = curr;
            curr = curr -> next;
            c++;
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete (curr);
    }
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

Node* node1 = new Node(10);
Node* head = node1;
Node* tail = node1;
print(head);

insertAtHead(head,11);
print(head);

insertAtHead(head,1);
print(head);

insertAtTail(tail,2);
print(head);

insertAtposition(tail,head,3,3);
print(head);

deleteNode(5,head);
print(head);


return 0;
}