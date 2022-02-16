/*Given two sequences, print the longest subsequence present in both of them. 
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3. 
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
*/
vector<string> all_longest_common_subsequences(string s, string t)
		
		{
		    // Code here
		    int m=s.length();
		    int n=t.length();
		    vector<vector<int>>dp(m+1,vector<int>(n+1));
		    for(int i=0;i<=m;i++)
		    {
		        for(int j=0;j<=n;j++ )
		        {
		            if(i==0|| j==0)
		            {
		                dp[i][j]=0;
		            }
		            if(s[i-1]==t[j-1])
		            {
		                dp[i][j]=1+dp[i-1][j-1];
		            }
		            else
		            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		        }
		        
		        
		    }
		    int indx=dp[m][n];
		   char g[indx+1];
		   g[indx]='\0';
		    int i=m;
		    int j=n;
		    while(i>0&& j>0)
		    {
		        if(s[i-1]==t[j-1])
		        {
		         g[indx-1]=s[i-1];   
		         indx--;
		            i--;
		            j--;
		        }
		        else if(dp[i-1][j]>dp[i][j-1])
		        {
		            i--;
		        }
		        else
		        {
		            j--;
		        }
		    
		   }
		   vector<string>  g1;
		   g1.push_back(g);
		   return g1;
		}
};
