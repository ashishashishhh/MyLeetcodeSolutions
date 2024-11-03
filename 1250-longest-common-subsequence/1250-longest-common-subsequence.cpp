//TLE 

// class Solution {
// public:
//     int fun(string text1, string text2,int i,int j,vector<vector<int>>&dp){
//         if(i>=text1.length() || j>=text2.length())
//         return 0;

//         if(dp[i][j]!=-1)
//         return dp[i][j];

//         if(text1[i]==text2[j])
//         return dp[i][j]=1 + fun(text1,text2,i+1,j+1,dp);
//         else{
//             return dp[i][j]=max(fun(text1,text2,i+1,j,dp),fun(text1,text2,i,j+1,dp));
//         }
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
//         return fun(text1,text2,0,0,dp);
        
//     }
// };

//tabulation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) dp[0][j]=0;


        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(text1[ind1-1]==text2[ind2-1])  dp[ind1][ind2]= 1 + dp[ind1-1][ind2-1];
                else dp[ind1][ind2]= max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        
        return dp[n][m];
    }
};