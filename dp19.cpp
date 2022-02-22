/*Given a string 'str' of size ‘n’. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome. Find the minimum numbers of characters we need to remove.
Note: The order of characters should be maintained.

Example 1:

Input: n = 7, str = "aebcbda"
Output: 2
Explanation: We'll remove 'e' and
'd' and the string become "abcba".
â€‹Example 2:

Input: n = 3, str = "aba"
Output: 0
Explanation: We don't remove any
character.*/


//CODE
int minDeletions(string str, int n) { 
    //complete the function here 
string str1=str;
reverse(str.begin(),str.end());
vector<vector<int>>dp(n+1,vector<int>(n+1));
for(int i=0;i<=n;i++)
{
    for(int j=0;j<=n;j++)
    {
        if(i==0|| j==0)
        {
            dp[i][j]=0;
        }
        else if(str1[i-1]==str[j-1])
        {
            dp[i][j]=1+dp[i-1][j-1];
        }
        else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
}
int x=dp[n][n];
int del=n-x;
return del;
} 
