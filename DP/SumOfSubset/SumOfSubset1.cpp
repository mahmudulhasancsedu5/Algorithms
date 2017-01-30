#include<bits/stdc++.h>

using namespace std;

int SumOfSubset(int arr[],int n,int sum,int poss,int res[])
{
    if(poss>=n)
    {
        if(sum==0)
        {
            cout<<"Sum is possible = "<<endl;
            for(int i=0;i<n;i++)
            {
                if(res[i]==1)
                {
                    cout<<arr[i]<<" ";
                }
            }
            cout<<endl;

        }
        return 0;
    }
    res[poss]=1;
    SumOfSubset(arr,n,sum-arr[poss],poss+1,res);
    res[poss]=0;
    SumOfSubset(arr,n,sum,poss+1,res);





}

int main()
{
    freopen("in.txt","r",stdin);

    int n;
    cin>>n;
    int arr[n];
    int i=0;
    while(i<n)
    {
        cin>>arr[i];

        i++;
    }

    int sum;
    cin>>sum;

    int res[n];
    memset(res,0,sizeof(res));
    SumOfSubset(arr,n,sum,0,res);




    return 0;
}
