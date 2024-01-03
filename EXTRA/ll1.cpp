//insertion in linked list.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data; // data of int type.
    Node* next; //pointer of node  type

    //contructor.
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //destructor.
    ~Node(){
        int value = this -> data;
        //memory free
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }

        cout<<"memory free for node with data"<<" "<<value<<endl;

    }
};

void insertAttail(Node* &tail,int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void insertAthead(Node* &head,int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void inserAtposition(Node* &tail,Node* &head,int position,int d){
    if(position==1){
        insertAthead(head,d);
        return;
    }
    
    Node* temp = head;
    Node* n = new Node(d);
    int c=1;
    while(c<position-1){
        temp = temp -> next;
        c++;
    }

    if(temp -> next ==NULL){
        insertAttail(tail,d);
        return;
    }

    n -> next = temp -> next;
    temp -> next = n;
}

void print(Node* &head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

void deleteNode(int position,Node* &head){
    //deleting first node
    if(position==1){
        Node* temp = head;
        head = head -> next;
        //memory free start node
        temp -> next = NULL;   //point to NULL before memory free.
        delete temp;
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
        prev -> next = curr -> next;
        //memory free
        curr -> next = NULL; //point to NULL before memory free.
        delete curr;
    }
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

Node* Node1 = new Node(10);
Node* head = Node1;
Node* tail = Node1;

insertAttail(tail,11);
print(head);

insertAttail(tail,15);
print(head);

insertAthead(head,12);
print(head);

// inserAtposition(tail,head,5,0);
// print(head);

inserAtposition(tail,head,1,1);
print(head);

cout<<"head"<<" "<<head -> data <<endl;
cout<<"tail"<<" "<<tail -> data <<endl;

deleteNode(5,head);
print(head);
return 0;
}