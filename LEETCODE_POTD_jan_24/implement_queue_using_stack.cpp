// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

class MyQueue {
public:
    stack <int> st1 , st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    //pop and peek st2 k top ele hi lo of st2 is empty then put all ele of st1 in st2 and dont push back ele of st2 into st1 -> wate of time uska koi kaam h nhi
    //amortized o(1) -> max time O(1) , sometime (n)
    int pop() {
        int ans = -1;
        if(!st2.empty()) {
            ans = st2.top();
            st2.pop();
        }

        //dekh rhe ho jb st2 khaali h tb daal rhe sabhi ele
        else{
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }

            if(!st2.empty()) {
                ans = st2.top();
                st2.pop();
            }
            //lekin st1 m return s nhi dala -> koi kaam hi nhi h bhai
        }
        return ans;
    }
    
    int peek() {

        int ans = -1;
        if(!st2.empty()) {
            ans = st2.top();
        }

        else{
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }

            if(!st2.empty()) {
                ans = st2.top();
            }
        }
        return ans;
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//patience Bro , thoda sa logic soch k try ur own test case
//hadbad m kaafi gadbad kie ho islie aaram s -> You will do best for Youself
//First, solve the problem. Then, write the code.
int t;
cin>>t;
while(t--){
           
}
return 0;
}