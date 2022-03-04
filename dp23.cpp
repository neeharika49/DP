/*Given two strings A and B, find if A is a subsequence of B.

Example 1:

Input:
A = AXY 
B = YADXCP
Output: 0 
Explanation: A is not a subsequence of B
as 'Y' appears before 'A'.
 

Example 2:

Input:
A = gksrek
B = geeksforgeeks
Output: 1
Explanation: A is a subsequence of B.
 

Your Task:  
You dont need to read input or print anything. Complete the function isSubSequence() which takes A and B as input parameters and returns a boolean value denoting if A is a subsequence of B or not. 

 

Expected Time Complexity: O(N) where N is length of string B.
Expected Auxiliary Space: O(1)


Constraints:
1<= |A|,|B| <=104Given two strings A and B, find if A is a subsequence of B.


*/



//code
long long Lcs(string x,string y)
    {
        int m=x.length();
        int n=y.length();
    long long dp[m+1][n+1];
        
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
                else if(x[i-1]==y[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    bool isSubSequence(string A, string B) 
    {
        // code here
        int l=Lcs(A,B);
        
        if(l==A.length())
        {
            return true ;
        }
         return false;
    }




//Two point Approach
//code



 bool isSubSequence(string A, string B) 
    {
        // code here
        int m=A.length();
        int n=B.length();
        int i=0,j=0;
        
        while(i<m && j<n)
        {
            if(A[i]==B[j])
            {
                i++;
            }
            j++;
        }
        if(i==m)
        {
            return true;
        }
        return false;
    }








