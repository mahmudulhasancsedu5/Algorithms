
#include<bits/stdc++.h>

using namespace std;
int coins[1000];
int make;
int N;
int table_dp[1000][1000];
void coinChange_Table()
{
    memset(table_dp,0,sizeof(table_dp));

    for(int i=1; i<=make; i++)
    {
        if(i<coins[0])
        {
            table_dp[0][i]=0;
        }
        else
        {
            if(i==coins[0] || table_dp[0][i-coins[0]]!=0)
            {
                table_dp[0][i]=1+table_dp[0][i-coins[0]];
            }
        }
    }

    for(int i=1; i<N; i++)
    {
        int coin_i=coins[i];
        for(int j=1; j<=make; j++)
        {
            if(j<coin_i)
            {

                table_dp[i][j]=table_dp[i-1][j];

            }
            else if(j==coin_i)
            {
                table_dp[i][j]=1;
            }
            else
            {
                cout<<j<<endl;
                if(table_dp[i-1][j]==0)
                {
                    if(table_dp[i][j-coin_i]!=0)
                        table_dp[i][j]=1+table_dp[i][j-coin_i];
                    else
                    {
                        table_dp[i][j]=0;
                    }

                }
                else
                {
                    table_dp[i][j]=table_dp[i-1][j];
                    if(table_dp[i][j-coin_i]!=0)
                        table_dp[i][j]=min(table_dp[i][j],1+table_dp[i][j-coin_i]);

                }
            }
        }
    }

    return ;

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

    coinChange_Table();

    for(int i=-1; i<N; i++)
    {

        if(i<0)
        {
            printf("%3d ",i);


            for(int j=1; j<=make; j++)
            {
                printf("%3d ",j);
            }
            printf("\n\n");

        }
        else
        {
            printf("%3d ",coins[i]);
            for(int j=1; j<=make; j++)
            {
                printf("%3d ",table_dp[i][j]);
            }
            printf("\n\n");

        }
    }



    return 0;
}
