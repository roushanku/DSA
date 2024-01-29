// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

class MyCalendar {
public:
    vector <pair<int,int>> v;
    set <pair<int,int>> st;
    MyCalendar() {
        //new MyCalendar();
    }
    
    bool book(int start, int end) {
        pair <int,int> p = {start , end};

    //O(n) search ko fast krna h
    //    for(auto it : v) {
    //        if(start < it.second && end > it.first) return false;
    //    }

    //     v.push_back(p);
    //     return true;

    //lo kr dia B.S se
    auto it = st.lower_bound(p);

    if(it != st.end() && it->first < end) return false;
    if(it != st.begin() && (--it)->second > start) return false;

    st.insert(p);
    return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
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