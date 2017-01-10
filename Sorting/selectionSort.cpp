#include<bits/stdc++.h>

using namespace std;

#define N 10


int arr[]={2,1,51,44,7,6,8,10,9,3};


void selectionSort(int items[],int itemCount)
{

    for(int i=0;i<itemCount;i++)
    {
        int max_val=(int)numeric_limits<int>::max();

        int max_ind=i;

        for(int j=i;j<itemCount;j++)
        {
            if(items[j]<max_val)
            {
                max_val=items[j];
                max_ind=j;
            }
        }

        swap(items[i],items[max_ind]);
    }

    return;
}


int main()
{

    selectionSort(arr,N);
    for(int i=0;i<N;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
