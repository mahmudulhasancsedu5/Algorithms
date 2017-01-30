#include<bits/stdc++.h>

using namespace std;
int coins[1000];
int f[1000];
int N;
int make;

int CoinChange_rcv(int i,int fre,int sum)
{
    //cout<<i<<" "<<fre<<endl;
    if(i>=N)
    {
        if(sum==make){

                return 1;
        }
        else return 0;
    }
    int ret1=0,ret2=0;
    if(fre<f[i] && sum+coins[i]<=make)
    {
        ret1=CoinChange_rcv(i,fre+1,sum+coins[i]);
    }
    ret2=CoinChange_rcv(i+1,0,sum);

    return ret1+ret2;

}

int dp[1000][1000];
int CoinChange_dp(int i,int fre,int sum)
{
    if(i>=N)
    {
        return (sum==make)?1:0;
    }



    if(dp[i][sum]!=-1) return dp[i][sum];

    int ret1=0,ret2=0;
    if(fre<f[i] && sum+coins[i]<=make)
    {
        ret1=CoinChange_dp(i,fre+1,sum+coins[i]);

    }
    ret2=CoinChange_dp(i+1,0,sum);
    dp[i][sum]=ret1+ret2;

    return dp[i][sum];



}
int main()
{
    FILE* fp=fopen("in_finit.txt","r");
    fscanf(fp,"%d",&N);

    int i=0;

    while(i<N)
    {
        fscanf(fp,"%d",&coins[i]);
        i++;
    }
    i=0;
    while(i<N)
    {
        fscanf(fp,"%d",&f[i]);
        i++;
    }

    fscanf(fp,"%d",&make);

    int canMake=CoinChange_rcv(0,0,0);
    cout<<"recursive solution of coin change = "<<canMake<<endl;

    memset(dp,-1,sizeof(dp));

    canMake=CoinChange_dp(0,0,0);

    cout<<"DP memorization solution of coin change = "<<canMake<<endl;





    return 0;
}
