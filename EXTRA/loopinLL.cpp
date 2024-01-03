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

bool loopInLL(Node* &head){   // checking of loop in LL using map.
    Node* n = head;
    map<Node*,bool> mp;
    while(n != NULL){
        if(mp[n]==true){
            return true;
        }
        mp[n] = true;
        n = n -> next;
    }
    return false;
}

Node* Floyddetect(Node* &head){  //2nd approach for loop detection(floyd-detection)
    if(head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow== fast){
            //cout<<"intersection"<<" "<<slow -> data <<endl;
            return slow;
        }
    }

    return NULL; 
}

Node* startnode(Node* &head){
    if(head == NULL){
        return NULL;
    }
    Node* fast = Floyddetect(head);
    Node* slow = head;
    
    while(slow != fast){
        slow = slow -> next;
        fast = fast -> next;
    }

    return slow;
}

void removeloop(Node* head){
    Node* startofloop = startnode(head);
    Node* temp = startofloop;

    while(temp -> next != startofloop){
        temp = temp -> next;
    }

    temp -> next = NULL;
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

inserAtposition(tail,head,5,0);
print(head);

inserAtposition(tail,head,1,1);
print(head);

int c=0;
Node* temp = head;
while(c<2){
    temp = temp -> next;
    c++;
}

tail -> next = temp;

cout<<"head"<<" "<<head -> data <<endl;
cout<<"tail"<<" "<<tail -> data <<endl;

cout<<loopInLL(head)<<endl;
cout<<"intersection"<<" "<<Floyddetect(head) -> data<<endl;
//print(head);

cout<<"start node"<<" "<<startnode(head) -> data <<endl;

removeloop(head);

cout<<loopInLL(head)<<endl;

return 0;
}