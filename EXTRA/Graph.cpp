#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template<typename T >

class graph{
public:
    unordered_map <T,list<T> > adj;

    void addedge(T u,T v,bool direction){
        //direction = 0 --> undirected
        //direction = 1 --> directed

        //create an edge from u to v

        adj[u].push_back(v);

        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printadjlist(){
        for(auto &i:adj){
            cout<<i.first<<"->";
            for(auto &j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cout<<"enter no of node"<<endl;
cin>>n;

int m;
cout<<"enter no of edges"<<endl;
cin>>m;

graph <int> g;
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    //ceate graph
    g.addedge(u,v,0);
}

g.printadjlist();
return 0;
}