
#include<bits/stdc++.h>

using namespace std;

void selectionSort(int arr[],int n)
{

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
    }

}

int main()
{
    int n=10;
    int arr[]={10,2,6,4,5,8,7,9,3,0};

    selectionSort(arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl;



    return 0;
}
