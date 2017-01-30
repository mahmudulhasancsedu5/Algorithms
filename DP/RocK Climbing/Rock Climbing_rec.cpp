#include<bits/stdc++.h>

using namespace std;
int row,clm;
int grid[1000][1000];
int solutions[1000][1000];
int grid_input()
{
    FILE* fp=fopen("in.txt","r");
    fscanf(fp,"%d %d",&row,&clm);

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<clm; j++)
        {
            fscanf(fp,"%d",&grid[i][j]);
            cout<<grid[i][j]<<" ";

        }
        cout<<endl;
    }


}

void print_table()
{
    cout<<endl<<endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<clm; j++)
        {

            //cout<<solutions[i][j]<<" ";
            printf("%4d ",solutions[i][j]);
        }
        cout<<endl;

    }

}
int dp[1000][1000];

int rockClimbing_rec(int r,int c)
{
    //cout<<r<<" ----> "<<c<<endl;

    if(c<0 || c>=clm) return 10000000;
    if(r==row) return 0;

    if(dp[r][c]<100000) return dp[r][c];

    int r1=grid[r][c]+rockClimbing_rec(r+1,c);
    int r2=grid[r][c]+rockClimbing_rec(r+1,c-1);
    int r3=grid[r][c]+rockClimbing_rec(r+1,c+1);
    int min_val=min(r1,min(r2,r3));
    if(min_val<dp[r][c])
    {
        dp[r][c]=min_val;
    }

    //cout<<r<<" ----> "<<c<<" "<<min_val<<endl;
    return dp[r][c];
}
void print_dp_memory()
{
    cout<<endl<<"dp memory:"<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<clm;j++)
        {
            cout<<setw(3)<<dp[i][j]<<" ";

        }
        cout<<endl;
    }
}
int main()
{

    memset(dp,126,sizeof(dp));
    cout <<dp[0][0]<<endl;

    grid_input();
    for(int i=0;i<clm;i++)
        cout<<rockClimbing_rec(0,i)<<endl;

    print_dp_memory();












    return 0;
}
