/*Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of given string.


Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".
Example 2:

Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".

Your Task:
You do not need to read input or print anything, Your task is to complete the function palindromicPartition() which takes the string str as input parameter and returns minimum number of partitions required.


Expected Time Complexity: O(n*n) [n is the length of the string str]
Expected Auxiliary Space: O(n*n)


Constraints:
1 ≤ length of str ≤ 500*/


//CODE:


//RECURSIVE - APPROACH

bool isPalindrome(string s1,int i,int j)
{
    int n=s1.length();
    
    while(i<j)
    {
        if(s1[i]!=s1[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve(string s, int i,int j)
{
    if(i>=j)
    {
        return 0;
        
    }
    if(isPalindrome(s,i,j)==true)
    {
        return 0;
    }
    int mini=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp=1+solve(s,i,k)+solve(s,k+1,j-1);
        if(temp<mini)
        {
            mini=temp;
        }
    }
    return mini;
}
    int palindromicPartition(string str)
    {
        // code here
        int n1=str.length();
        int x=solve(str,0,n1-1);
        return x;
    }

//CODE:
class Solution{
public:
int  dp[501][501];
bool isPalindrome(string &s1,int i,int j)
{
    int n=s1.length();
    
    while(i<j)
    {
        if(s1[i]!=s1[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve(string &s, int i,int j)
{
    if(i>=j)
    {
        return dp[i][j]=0;
        
    }
    if(isPalindrome(s,i,j)==true)
    {
        return dp[i][j]=0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int mini=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp=1+solve(s,i,k)+solve(s,k+1,j);
        if(temp<mini)
        {
            mini=temp;
        }
    }
    return dp[i][j]=mini;
}
    int palindromicPartition(string str)
    {
        // code here
        
        int n1=str.length();
        memset(dp,-1,sizeof(dp));
        int x=solve(str,0,n1-1);
        return x;
    }




