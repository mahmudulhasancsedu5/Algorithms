#include<bits/stdc++.h>


using namespace std;

int n=10;
int arr[]={122,2,6,4,5,8,7,9,3,11};
int temp[100];
void margeSort(int l,int h)
{
    if(l==h) return ;

    int mid=(l+h)/2;

    margeSort(l,mid);
    margeSort(mid+1,h);

    int i,j,k;
    for(i=l,j=mid+1,k=l;k<=h;k++)
    {
        if(i==mid+1)
        {
            temp[k]=arr[j++];
        }
        else if(j==h+1)
        {
            temp[k]=arr[i++];
        }
        else if(arr[i]<arr[j])
        {
            temp[k]=arr[i++];
        }
        else if(arr[i]>arr[j])
        {
            temp[k]=arr[j++];
        }



    }

    for(int i=l;i<=h;i++)
    {
        arr[i]=temp[i];
    }



}

int main()
{



    margeSort(0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl;



    return 0;
}
