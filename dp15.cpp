/*You are given an array A of length N consisting of positive integers. Your task is to print the maximum subsequence sum such that no three consecutive elements are taken from array A.
Note:
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements
Input Format:
The first line of the input contains ‘T’ denoting the number of test cases.

The first line of each test case contains an integer ‘N’, representing the length of the array.

The second line of each test case contains 'N' space-separated integers of the array 'A'. 
Output Format:
For each test case, print a single line containing a single integer denoting the maximum sum subsequence.

The output of each test case will be printed on a new line.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 10 ^ 4
1 <= A[i] <=10 ^ 5

Where ‘T’ denotes the number of test cases and N denotes the length of array 'A'.

Time limit: 1 sec.
Sample Input 1:
2
3
1 1 1 
4
6 3 3 2
Sample Output 1:
2
11
Explanation For Sample Input 1:
For test case 1: 

All subsequences sum  are:  
1 (A[0]), 1 (A[1]), 1 (A[2]), 2 (A[0] + A[1]), 2 (A[0] + A[2]), 2 (A[1] + A[2]), 3(A[0] + A[1] + A[2]) 

The max sum subsequence without three consecutive elements is 2 ( A[0] + A[1] or A[0] + a[2] or A[1] + A[2]).

For test case 2:

All subsequences sum are:  
6 (A[0]), 3 (A[1]), 3 (A[2]), 2 (A[3]),  9 (A[0] + A[1]), 9 (A[0] + A[2]), 8 (A[0] + A[3]), 6 (A[1] + A[2]), 5 (A[1] + A[3]), 5 *  (A[2] + A[3]), … 11 (A[0] + A[1] + A[3]), ... 11 (A[0] + A[2] + A[3])

The max sum subsequence without three consecutive elements is 11 ( A[0] + A[1] + A[3]  or A[0] + A[2] + A[3] ).
Sample Input 2:
2
8
1 2 3 4 5 6 7 8
1
46
Sample Output 2:
27
46
*/
//code:
int maxSum(vector<int> &a, int n) 
{
    
    vector<int> dp(n);
    dp[0]=a[0];
    for(int i=1;i<n;i++)
    {
        int sum1=a[i]+a[i-1];
        if(i-3>=0)
            sum1=sum1+dp[i-3];
        int sum2=a[i];
        if(i-2>=0)
            sum2=sum2+dp[i-2];
        int nottake=dp[i-1];
        dp[i]=max(sum1,max(sum2,nottake));
    }
    return dp[n-1];
}
