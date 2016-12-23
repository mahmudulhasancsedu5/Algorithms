#include<bits/stdc++.h>

using namespace std;



void combination_pattern(int arr[],int flags[],int n,int r,int poss,int next)
{

    if(poss==r)
    {
        for(int i=0;i<r;i++)
        {
            cout << arr[i]<<" ";
        }
        cout << endl;

        return;
    }


    for(int i=next;i<=n;i++)
    {
        if(flags[i]==0)
        {
            flags[i]=1;
            arr[poss]=i;

            combination_pattern(arr,flags,n,r,poss+1,i+1);

            flags[i]=0;
        }



    }


    return;
}


int main()
{

    int n;
    int r;

    cin>>n>>r;


    int arr[r+1];
    int flags[n+1];

    memset(arr,0,sizeof(arr));
    memset(flags,0,sizeof(flags));

    combination_pattern(arr,flags,n,r,0,1);



    return 0;
}
