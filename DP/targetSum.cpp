//https://leetcode.com/problems/target-sum/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int a=(target+sum)/2;
        if(sum < abs(target) || (sum+target)%2) return 0;
        int t[n+1][a+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<a+1;j++){
                if(i==0){                           
                    t[i][j]=0;
                }
                if(j==0){
                    t[i][j]=1;
                }
            }
        }
            for(int i=1;i<n+1;i++){
                for(int j=1;j<a+1;j++){
                    if(nums[i-1]<=j){
                    t[i][j]=(t[i-1][j-nums[i-1]]) + (t[i-1][j]);
                    }
                    else{
                        t[i][j]=t[i-1][j];
                    }
                }
            }
            
            return t[n][a];
        
    }

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,target;
cin>>n>>target;

vector<int> nums;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    nums.push_back(x);
}

cout<<findTargetSumWays(nums,target)<<endl;
return 0;
}