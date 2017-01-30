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
int smallest_score(int i,int j)
{
    int min_val=1000000;

    if(i==0)
        return grid[i][j];

    if(i-1>=0)
    {
        if(min_val>grid[i][j]+solutions[i-1][j])
        {
            min_val=grid[i][j]+solutions[i-1][j];

        }
        if(j-1>=0)
        {
            if(min_val>grid[i][j]+solutions[i-1][j-1])
            {
                min_val=grid[i][j]+solutions[i-1][j-1];

            }

        }
        if(j+1<clm)
        {
            if(min_val>grid[i][j]+solutions[i-1][j+1])
            {
                min_val=grid[i][j]+solutions[i-1][j+1];

            }

        }
    }
    return min_val;
}
void rock_climbing_table()
{

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<clm; j++)
        {


            solutions[i][j]=smallest_score(i,j);


        }

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
int min_clm;
int find_min_poss()
{
    int min_val=100000000;
    for(int i=0; i<clm; i++)
    {
        if(solutions[row-1][i]<min_val)
        {
            min_val=solutions[row-1][i];
            min_clm=i;
        }
    }
    return min_clm;
}


void path(int row,int cl)
{
    //cout<<endl<<"-->"<<row<<" "<<cl<<endl;

    if(row-1<0){

            cout<<grid[row][cl]<<" ";
            return ;


    }

    if(cl>=0 && cl<clm)
    {

        if(solutions[row][cl]-grid[row][cl]==solutions[row-1][cl])
        {

            path(row-1,cl);

        }
        if(cl-1>=0)
        {

            if(solutions[row][cl]-grid[row][cl]==solutions[row-1][cl-1])
            {

                path(row-1,cl-1);

            }

        }
        if(cl+1<clm)
        {
            if(solutions[row][cl]-grid[row][cl]==solutions[row-1][cl+1])
            {

                path(row-1,cl+1);

            }
        }


    }
    cout<<grid[row][cl]<<" ";
    return;

}

int main()
{

    grid_input();
    rock_climbing_table();
    print_table();

    int min_poss=find_min_poss();

    cout<<solutions[row-1][min_poss]<<endl;
    path(row-1,min_poss);









    return 0;
}
