#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};

Node* insertintoBST(Node* root,int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root -> data){
        root -> right = insertintoBST(root->right,data);
    }

    else{
        root -> left = insertintoBST(root -> left,data);
    }

    return root;
}


void takeinput(Node* root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertintoBST(root,data);
        cin>>data;
    }

}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root -> left);
    cout<< root -> data <<" ";
    inorder(root -> right);
}

Node* minval(Node* root){
    Node* temp = root;
    while(temp != NULL){
        temp = temp -> left;
    }

    return temp;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

Node* root = NULL;
cout<<"enter data for bst"<<endl;
takeinput(root);

// cout<<"printing inorder BST"<<endl;
// inorder(root);

cout<<"minvalue"<<" "<<minval(root) -> data<<endl;
return 0;
}