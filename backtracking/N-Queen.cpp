#include<bits/stdc++.h>


using namespace std;


int greed[1000][1000];

void print_greed(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout <<greed[i][j]<<" ";

        }
        cout << endl;
    }

}

bool isSafe(int row,int clm,int n)
{


    int i,j;
    for(i=clm-1; i>=0; i--)
    {
        if(greed[row][i]==1)
        {
            return false;

        }
    }

    for(i=row-1,j=clm-1; i>=0 && j>=0; i--,j--)
    {
        if(greed[i][j]==1) return false;

    }


    for(i=row+1,j=clm-1; i<n && j>=0; i++,j--)
    {
        if(greed[i][j]==1) return false;

    }


    return true;

}
bool NQueen(int n,int clm)
{
    if(n==clm)
    {
        print_greed(n);
        return true;
    }


    for(int i=0; i<n; i++)
    {
        if(isSafe(i,clm,n)==true)
        {
            greed[i][clm]=1;
            bool NoNeedToChange=NQueen(n,clm+1);
            if(NoNeedToChange==false)
            {
                greed[i][clm]=0;

            }
            else
            {
                return true;
            }
        }
    }


    return false;





}





int main()
{

    int n;
    cin>>n;

    NQueen(n,0);







}
