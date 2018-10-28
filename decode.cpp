// https://www.interviewbit.com/problems/ways-to-decode/

int Solution::numDecodings(string A) {
    int ans = 0;
    int n = A.size();
    if(n==0)    return 0;
    int dp[n+1];
    cout << sizeof(dp);
    memset(dp, 0, sizeof(dp));
                for(int j=0; j<=n; j++)
                cout << dp[j] << " ";   
    dp[0] = 1;
    dp[1] = (A[0]!='0');
    for(int i=1; i<n; i++){
        dp[i+1] = 0;
        if(A[i-1] == '1' || (A[i-1]=='2' && A[i]<'7')){
            dp[i+1] += dp[i-1];
        }
        if(A[i] != '0') dp[i+1] += dp[i];
    }
    // for(int i=0; i<=n; i++)
    //     cout << dp[i] << " ";
    return dp[n];
}
