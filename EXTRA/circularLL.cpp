#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete (next);
            this -> next = NULL;
        }
        cout<<"memory free for"<<" "<<value<<endl;
    }
    
};

void insertNode(Node* &tail,int ele,int d){
    //assuming ele is present
    //empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //non empty list
        Node* curr = tail;
        while(curr -> data != ele){
            curr = curr -> next;
        }

        Node* temp =new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }
}

void deleteNode(Node* &tail,int ele){
    //empty list
    if(tail == NULL){
        cout<<"empty"<<endl;
    }
    else{
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != ele){
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;
        if(tail == curr){
            tail = prev;
        }
        curr -> next = NULL;
        delete (curr);
    }
}

void print(Node* tail){
    Node* temp = tail;
    do {
        cout<<tail -> data <<" ";
        tail = tail -> next;
    } while(tail != temp);
    cout<<endl;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

Node* tail = NULL;
insertNode(tail,5,3);
print(tail);

insertNode(tail,3,5);
print(tail);

insertNode(tail,5,6);
print(tail);

deleteNode(tail,5);
print(tail);

return 0;
}