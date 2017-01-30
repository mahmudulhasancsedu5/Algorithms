#include<bits/stdc++.h>

using namespace std;

int solution[1000][1000];

void SubSetSum(int arr[],int n,int sum)
{

    memset(solution,0,sizeof(solution));
    for(int i=0;i<n;i++)
    {
        solution[i][0]=1;
    }


    solution[0][arr[0]]=1;

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i]==j)
            {
                solution[i][j]=1;
            }
            else
            {
                if(j<arr[i])
                {
                    solution[i][j]=solution[i-1][j];
                }
                else
                {
                    if(j-arr[i]>=0)
                    {
                        solution[i][j]=max(solution[i-1][j],solution[i-1][j-arr[i]]);
                    }
                    else
                    {
                        solution[i][j]=solution[i-1][j];
                    }

                }
            }

        }
    }


    return;


}



int main()
{

    FILE* fp=fopen("in.txt","r");

    int n;
    fscanf(fp,"%d",&n);
    int item_set[n];

    int i=0;

    while(i<n)
    {
        fscanf(fp,"%d",&item_set[i]);

        i++;
    }
    int sum;
    fscanf(fp,"%d",&sum);
    SubSetSum(item_set,n,sum);
    for(int i=-1;i<n;i++)
    {
        if(i<0)
        {
            printf("%3d",i);
        }
        else
        {
            //cout<<item_set[i]<<" ";
            printf("%3d",item_set[i]);
        }

        for(int j=0;j<=sum;j++)
        {
            if(i<0)
            {
                //cout<<j<<" ";
                printf("%3d",j);
            }
            else
            {
                //cout<<solution[i][j]<<" ";
                printf("%3d",solution[i][j]);
            }

        }
        cout<<endl<<endl;
    }






    return 0;
}
