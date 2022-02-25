/*Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" becstring shortestCommonSupersequence(string str1, string str2) {
        int m=str1.size();
        int n=str2.size();
         vector<vector<int>>dp(m+1,vector<int>(n+1));
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0|| j==0)
                {
                    dp[i][j]=0;
                }
               else if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        string s;
        int i=m;
        int j=n;
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                s.push_back(str1[i-1]);
                i--;
                j--;
                
            }
            else if(dp[i][j-1]>=dp[i-1][j])
            {
                s.push_back(str2[j-1]);
                j--;
                
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                s.push_back(str1[i-1]);
                i--;
                
            }
        }
        while(i>0)
        {
            s.push_back(str1[i-1]);
            i--;
            
        }
        while(j>0)
        {
            s.push_back(str2[j-1]);
            j--;
            
        }
        reverse(s.begin(),s.end());
        return s;
    }ause we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"*/

//CODE:


string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.size();
        int n=str2.size();
         vector<vector<int>>dp(m+1,vector<int>(n+1));
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0|| j==0)
                {
                    dp[i][j]=0;
                }
               else if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        string s;
        int i=m;
        int j=n;
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                s.push_back(str1[i-1]);
                i--;
                j--;
                
            }
            else if(dp[i][j-1]>=dp[i-1][j])
            {
                s.push_back(str2[j-1]);
                j--;
                
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                s.push_back(str1[i-1]);
                i--;
                
            }
        }
        while(i>0)
        {
            s.push_back(str1[i-1]);
            i--;
            
        }
        while(j>0)
        {
            s.push_back(str2[j-1]);
            j--;
            
        }
        reverse(s.begin(),s.end());
        return s;
    }
