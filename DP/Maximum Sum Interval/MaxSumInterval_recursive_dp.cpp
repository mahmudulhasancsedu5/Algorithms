#include<bits/stdc++.h>

using namespace std;
int arr[1000];
int N;
int dp[1000][1000];
int flag[1000][1000];
int MaxSumInterval_rcv(int i,int j)
{
    cout<<i<<"  "<<j<<endl;
    if(i>j) return 0;
    if(i==j) return arr[i];

    if(flag[i][j]==1) return dp[i][j];

    int r1,r2,r3;
    r1=max(arr[i]+MaxSumInterval_rcv(i+1,j),MaxSumInterval_rcv(i+1,j));

    r2=max(arr[j]+MaxSumInterval_rcv(i,j-1),MaxSumInterval_rcv(i,j-1));
    flag[i][j]=1;
    dp[i][j]=max(max(r1,arr[i]),max(r2,arr[j]));
    return dp[i][j];
}

void print_res_mat()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            //cout<<solutions[i][j]<<" ";
            printf("%3d ",dp[i][j]);
        }
        cout<<endl;
    }
}
int main()
{
    memset(dp,-1,sizeof(dp));
    FILE* fp=fopen("in.txt","r");

    fscanf(fp,"%d",&N);

    int i=0;
    while(i<N)
    {
        fscanf(fp,"%d",&arr[i]);
        i++;
    }

    cout<<MaxSumInterval_rcv(0,N-1)<<endl;

    print_res_mat();




    return 0;
}
