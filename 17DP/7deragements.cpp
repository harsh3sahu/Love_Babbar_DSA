#include<bits/stdc++.h>
#define MOD 1000000007

long long int solveRec(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }

    long long int ans= ((n-1)%MOD)*((solveRec(n-1)%MOD)+(solveRec(n-2)%MOD));

    return ans;

}

long long int solveMem(int n, vector<long long int>&dp){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n]=  ( ((n-1)%MOD)*((solveMem(n-1,dp)%MOD)+(solveMem(n-2,dp)%MOD)) %MOD);

    return dp[n];

}

long long int solveTab(int n){

    vector<long long int> dp(n+1,0);
    
    dp[1]=0;
    dp[2]=1;
    long long int prev2 = dp[1];
    long long int prev1 = dp[2];

    for(int i=3;i<=n;i++){
        
        long long int first=prev1 % MOD;
        long long int second=prev2 % MOD;

        long long int ans=( (first+second)%MOD * (i-1) )%MOD;
        prev2=prev1;
        prev1=ans;
    }

    return prev1;



}


long long int countDerangements(int n) {
    Write your code here.
    return solveRec(n);

    vector<long long int> dp(n+1,-1);
    return solveMem(n,dp);

    return solveTab(n);
}
