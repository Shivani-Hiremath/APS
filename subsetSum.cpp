#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    bool dp[n+1][sum+1]={false};

    for(int i=0;i<=n;i++)
        dp[i][0] = true; // Sum 0 can always be formed with an empty subset
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]<=j)
                dp[i][j]= dp[i-1][j] || dp[i-1][j-arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    if(dp[n][sum])
        cout<<"Subset with given sum exists"<<endl;
    else
        cout<<"Subset with given sum does not exist"<<endl;
}
//i=1, num=3
//sum = 3: dp[1][3] = dp[0][3] || dp[0][0] → false || true → true
