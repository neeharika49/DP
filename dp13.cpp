/*Given two strings. The task is to find the length of the longest common substring.


Example 1:

Input: S1 = "ABCDGH", S2 = "ACDGHR"
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.
Example 2:

Input: S1 = "ABC", S2 "ACB"
Output: 1
Explanation: The longest common substrings
are "A", "B", "C" all having length 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestCommonSubstr() which takes the string S1, string S2 and their length n and m as inputs and returns the length of the longest common substring in S1 and S2.


Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).


Constraints:
1<=n, m<=1000*/

//code:RECURSIVE
int find(string x,string y,int n,int m,int result)
    {
      if(m==0 || n==0)
        {
            return result;
        }
        if(x[n-1]==y[m-1])
        {
            return find(x,y,n-1,m-1,result+1);
        }
        else
        return max(result,max(find(x,y,n-1,m,0),find(x,y,n,m-1,0)));
        
    }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int res=0;
        return find(S1,S2,n,m,res);
     
      
      
      
      
      
      //code:TOP-DOWN
      int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int maX=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(S1[i-1]==S2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    maX=max(maX,dp[i][j]);
                }
                else 
                dp[i][j]=0;
            }
        }
        return maX;
    }
