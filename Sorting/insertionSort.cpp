#include<bits/stdc++.h>

using namespace std;

void insertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {

        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
            else
            {
                break;
            }

        }
    }

}


int main()
{
    int n=10;
    int arr[]={10,2,6,4,5,8,7,9,3,0};

    insertionSort(arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl;



    return 0;
}
