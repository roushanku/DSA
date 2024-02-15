// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

class MedianFinder {
public:
    priority_queue <int> lpq;
    priority_queue <int , vector <int> , greater<int>> rpq;
    MedianFinder() {
        
    }

    //suppose current stram is:
    //case1 : odd no of ele
    // 1 2 |3| 4 5
    //for this stream  we want to divide the strean in 1 2 3 and 4 5 . i.e for left part we need max ele
    //so we will use max heap for leaft part bcz it will left_mx in O(1) time
    //similarily for right part we need min ele so we will use min heap for right heap

    //case2 : consider the case of even no of ele
    //1 2 |3 4| 5 6
    //same chij bhai we need max ele from left part and min ele from rigth part


    //note : onr hting to observ : we will always keep left heap size one more or equa to right heap 
    
    void addNum(int num) {
        if(lpq.empty() || num < lpq.top()) lpq.push(num);

        else rpq.push(num); //agr left k top s ele bada h to right m dalo


        //to keep one or equal
        if(abs((int)lpq.size() - (int)rpq.size()) > 1) {
            rpq.push(lpq.top());
            lpq.pop();
        } 

        else if(rpq.size() > lpq.size()) { //right heap ka size bada ho gya
            lpq.push(rpq.top());
            rpq.pop();
            cout<<"debug1"<<" ";
        }
    }
    
    double findMedian() {
        double ans;
        if(lpq.size() == rpq.size()) {
            double num;
            if(lpq.size() > 0) num = lpq.top();

            if(rpq.size() > 0) num += rpq.top();
            ans = num / 2;
        }

        else{
            double num = (lpq.top());
            ans = num;
        }

        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
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