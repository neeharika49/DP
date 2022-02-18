/*Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Example 1:

Input: str1 = "heap", str2 = "pea"
Output: 3
Explanation: 2 deletions and 1 insertion
p and h deleted from heap. Then, p is 
inserted at the beginning One thing to 
note, though p was required yet it was 
removed/deleted first from its position 
and then it is inserted to some other 
position. Thus, p contributes one to the 
deletion_count and one to the 
insertion_count.
Example 2:

Input : str1 = "geeksforgeeks"
str2 = "geeks"
Output: 8
Explanation: 8 deletions*/

//CODE:
int lcs(string x,string y, int m, int n)
	{ 
	    vector<vector<int>>dp(m+1,vector<int>(n+1));
	    for(int i=0;i<=m;i++)
	    {
	        for(int j=0;j<=n;j++)
	        {
	            if(i==0|| j==0)
	            {
	                dp[i][j]=0;
	            }
	            else if(x[i-1]==y[j-1])
	            {
	                dp[i][j]=1+dp[i-1][j-1];
	            }
	            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    return dp[m][n];
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int a=str1.length();
	    int b=str2.length();
	    int g=lcs(str1,str2,a,b);
	    int x1=a-g;
	    int x2=b-g;
	    int x=x1+x2;
	    return x;
	} 
