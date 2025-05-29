#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    cout<<"Enter first string: ";
    //Scin.ignore(); 
    getline(cin, s1); 
    cout<<"Enter second string: ";
    getline(cin, s2); 
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    //Initilaization
    for(int i=0;i<n;i++)
    dp[i][0]=i;
    for(int j=0;j<m;j++)
    dp[0][j]=j;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i]==s2[j])
                dp[i][j] = dp[i-1][j-1]; // No cost if characters match
            else
                dp[i][j] = min({dp[i-1][j] + 1,   // Deletion
                              dp[i][j-1] + 1,   // Insertion
                              dp[i-1][j-1] + 1}); // Replacement
        }
    }
    cout << "Edit Distance: " << dp[n][m] << endl;

}