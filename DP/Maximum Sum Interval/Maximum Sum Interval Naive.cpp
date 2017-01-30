#include<bits/stdc++.h>

using namespace std;

int arr[1000];
int N;
int low,heigh,max_val=-1000;
int solutions[1000][1000];
void MaximumSumInterval()
{
    memset(solutions,0,sizeof(solutions));


    for(int i=0; i<N; i++)
    {
        int j=0;
        for(j=i; j<N; j++)
        {

            for(int k=i; k<=j; k++)
            {

                solutions[i][j]+=arr[k];

            }
            if(solutions[i][j]>max_val)
            {
                max_val=solutions[i][j];
                low=i;
                heigh=j;
            }


        }


    }

    cout<<endl<<endl<<low <<"  "<<heigh<<"-->"<<max_val<<endl<<endl<<endl;

}

void print_res_mat()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            //cout<<solutions[i][j]<<" ";
            printf("%3d ",solutions[i][j]);
        }
        cout<<endl;
    }
}

int main()
{
    FILE* fp=fopen("in.txt","r");

    fscanf(fp,"%d",&N);

    int i=0;
    while(i<N)
    {
        fscanf(fp,"%d",&arr[i]);
        cout<<arr[i]<<endl;
        i++;
    }

    MaximumSumInterval();
    print_res_mat();




    return 0;
}
