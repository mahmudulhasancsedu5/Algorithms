#include<bits/stdc++.h>

using namespace std;
int coins[1000];
int make;
int N;
bool CoinCnange_rec(int poss,int sum)
{

    if(poss>=N)
    {
        if(sum==make) return 1;

        return 0;
    }
    int ret1=0,ret2=0;
    if(sum+coins[poss]<=make)
    {
        ret1=CoinCnange_rec(poss,sum+coins[poss]);
    }
    ret2=CoinCnange_rec(poss+1,sum);

    return ret1+ret2;


}
int dp[1000][1000];
bool CoinChange_dp(int poss,int sum)
{

    if(poss>=N)
    {
        return (sum==make)?1:0;
    }

    if(dp[poss][sum]!=0) return dp[poss][sum];

    int ret1=0,ret2=0;

    if(sum+coins[poss]<=make)
    {
        ret1=CoinChange_dp(poss,sum+coins[poss]);
    }
    ret2=CoinChange_dp(poss+1,sum);

    dp[poss][sum]=ret1+ret2;

    return dp[poss][sum];





}

int main()
{
    FILE* fp=fopen("in.txt","r");


    fscanf(fp,"%d",&N);


    int i=0;
    while(i<N)
    {

        fscanf(fp,"%d",&coins[i]);
        i++;
    }
    fscanf(fp,"%d",&make);

    int canMake=CoinCnange_rec(0,0);

    if(canMake>0)
    {
        printf("We can make %d by %d ways.\n",make,canMake);
    }

    canMake=CoinChange_dp(0,0);

    if(canMake>0)
    {
        printf("We can make %d by %d ways.\n",make,canMake);
    }


    return 0;
}
