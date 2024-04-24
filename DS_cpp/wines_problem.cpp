#include<iostream>
#include<vector>
using namespace std;
int winesRec(int dp[][10],vector<int> prices,int L, int R,int y){
    if(L > R) return 0;
    if(dp[L][R] != 0){
        return dp[L][R];
    }
    int left = prices[L] * y + winesRec(dp,prices,L+1,R,y+1);
    int right = prices[R] * y + winesRec(dp,prices,L,R -1,y+1);
    dp[L][R] = max(left,right);
    return dp[L][R];
}  
int winesIter(vector<int> prices,int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int i = n -1; i >= 0 ;i--){
        for(int j = 0; j < n; j++){
            if(i == j){
                dp[i][j] = n * prices[i];
            }
            if(i < j){
                int y = n -(j -i);
                int pick_left = prices[i] * y + dp[i+1][j];
                int pick_right = prices[j] * y + dp[i][j -1];
                dp[i][j] = max(pick_left,pick_right);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    // cout<<dp[0][n-1]<<"\n";
    return dp[0][n -1 ];

} 
int main(){
    vector<int> vec = {2,3,5,1,4};
    int n = 5;
    int dp[10][10] = {0};
    cout<<winesRec(dp,vec,0,n-1,1)<<"\n";
    for(int i = 0;i< n;i++){
        for(int j = 0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<winesIter(vec,n)<<"\n";
    
    return 0;
}