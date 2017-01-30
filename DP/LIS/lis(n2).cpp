#include<bits/stdc++.h>


using namespace std;

int arr[1000];
int parent[1000];
int length[1000];


void print_lis(int poss)
{
    if(poss==-1) return;

    print_lis(parent[poss]);
    printf("%d ",arr[poss]);

}

int lis(int n)
{

    memset(length,1,sizeof(length));
    memset(parent,-1,sizeof(parent));

    int max_poss=0;
    int max_len=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]<arr[i])
            {
                if(length[j]+1>length[i])
                {
                    length[i]=length[j]+1;
                    parent[i]=j;
                }
            }
        }

        if(length[i]>max_len)
        {
            max_len=length[i];
            max_poss=i;
        }

    }

    return max_poss;

}

int main()
{

    int n;
    cin>>n;
    int i=0;
    while(i<n)
    {
        cin>>arr[i];

        i++;
    }

    int poss=lis(n);

    print_lis(poss);



    return 0;
}
