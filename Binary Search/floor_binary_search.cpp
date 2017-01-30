#include<bits/stdc++.h>

using namespace std;

int floor_binary_search(int arr[],int val,int low,int high)
{
    if(low>high) return -1;

    int mid=(low+high)/2;
    //cout<<mid<<endl;
    if(arr[mid]==val) return mid;
    if(arr[mid]<val)
    {
        while(arr[mid]<=val && mid<high)
        {
            mid++;
        }

        return mid-1;
    }
    else
    {

        return floor_binary_search(arr,val,low,mid-1);


    }


}

int main()
{
    int n;
    cin>>n;

    int arr[n];


    int i=0;
    while(i<n)
    {

        cin>>arr[i];

        i++;

    }

    sort(arr,arr+n);
    int poss=floor_binary_search(arr,10,0,n);
    cout<<poss<<endl;



    return 0;
}
