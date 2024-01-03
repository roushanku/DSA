#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* createbinary(node* root){
    cout<<"enter data for root"<<endl;
    int d;
    cin>>d;

    root = new node(d);

    if(d==-1){
        return NULL;
    }

    cout<<"enter data for left of" <<d<<endl;

    root -> left = createbinary(root -> left);

    cout<<"enter data for right of"<<d<<endl;

    root -> right = createbinary(root -> right);
    return root;
}

void levelordertraversal(node* root){
    queue <node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp = q.front();
        
        q.pop();
            
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<<temp -> data <<" ";
            if(temp -> left){
                q.push(temp -> left);
        }

            if(temp -> right){
                q.push(temp -> right);
            }
        }
        
       
    }

}

void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root -> left);
    cout<< root -> data <<" ";
    inorder(root -> right);
}

void preorder(node* root){
    if(root == NULL){
        return;
    }

    cout<<root -> data <<" ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(node* root){
    if(root == NULL){
        return;
    }

    postorder(root -> left);
    postorder(root -> right);
    cout<<root -> data <<" ";
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

node* root = NULL;

//create binarytree
root = createbinary(root);

//levelordertraversal

//levelordertraversal(root); // ye to kaam hi nhi kr rha h

//inorder traversal
inorder(root);
cout<<endl;

//preorder traversal
preorder(root);
cout<<endl;

//postorder traversal
postorder(root);
return 0;
}