#include<bits/stdc++.h>


using namespace std;

char in1[1000]="My name is Mahmudul Hasan";
char in2[1000]="What is your fathers name?";
int n=strlen(in1);
int m=strlen(in2);
int dp[1000][1000];
int lcs(int i,int j)
{
    cout<<i<<" "<<j<<endl;
    if(i>=n || j>=m) return 0;

    if(dp[i][j]!=-1) return dp[i][j];
    if(in1[i]==in2[j])
    {

        return dp[i][j]=1+lcs(i+1,j+1);
    }

    int res1=lcs(i,j+1);
    int res2=lcs(i+1,j);
    return dp[i][j]=max(res1,res2);
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cout<<lcs(0,0)<<endl;


    return 0;

}
