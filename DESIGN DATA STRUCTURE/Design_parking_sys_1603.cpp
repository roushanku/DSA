// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

class ParkingSystem {
public:
    int one , two , three;
    ParkingSystem(int big, int medium, int small) {
        one = big;
        two = medium;
        three = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1) {
            if(one > 0) {
                one--;
                return true;
            }
            return false;
        }

        else if(carType == 2) {
            if(two > 0) {
                two--;
                return true;
            }
            return false;
        }

        else{
            if(three > 0) {
                three--;
                return true;
            }

            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
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