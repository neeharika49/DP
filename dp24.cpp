/*Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd


Example 1:

Input: str = "abcd"
Output: 3
Explanation: Inserted character marked
with bold characters in dcbabcd
Example 2:

Input: str = "aa"
Output: 0
Explanation:"aa" is already a palindrome.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function countMin() which takes the string str as inputs and returns the answer.

Expected Time Complexity: O(N2), N = |str|
Expected Auxiliary Space: O(N2)

Constraints:
1 ≤ |str| ≤ 103
str contains only lower case alphabets.*/



//CODE:

int countMin(string str){
    //complete the function here
   string str1=str;
    reverse(str.begin(),str.end());
    int n=str.length();
vector<vector<int>>dp(n+1,vector<int>(n+1));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0|| j==0)
            {
                 dp[i][j]=0;
            }
            else if(str[i-1]==str1[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
   int lps=dp[n][n];
    int ins=n-lps;
    return ins;
    }
