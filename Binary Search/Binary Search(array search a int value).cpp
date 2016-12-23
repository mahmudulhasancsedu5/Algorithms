#include<bits/stdc++.h>
using namespace std;

int arr[100];



int b_search(int key,int low,int high)
{
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(key>arr[mid]) b_search(key,mid+1,high);
    else if(key<arr[mid]) b_search(key,low,mid-1);
    else
    {
        return mid;
    }
}

int b_search_lowerbound(int key,int low,int high)
{
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(key>arr[mid]) b_search_lowerbound(key,mid+1,high);
    else if(key<arr[mid]) b_search_lowerbound(key,low,mid-1);
    else
    {
        //find the left of repetade value
        int ind=mid;
        while(mid--)
        {
            if(arr[mid]==key)
            {
                ind=mid;
            }
        }
        return ind;
    }
}

int b_search_upperbound(int key,int low,int high,int high_end)
{
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(key>arr[mid]) b_search_upperbound(key,mid+1,high,high_end);
    else if(key<arr[mid]) b_search_upperbound(key,low,mid-1,high_end);
    else
    {
        //find the left of repetade value

        while(mid<=high)
        {
            if(arr[mid]>key)
            {
                break;

            }
            mid++;
        }
        return mid;
    }
}

int main()
{

    freopen("in.txt","r",stdin);

    int val;
    int i=0;
    while(scanf("%d",&val)!=EOF)
    {
        cout <<val<<endl;
        arr[i]=val;
        i++;

    }

    int ind=b_search_upperbound(100,0,i-1,i-1);
    //int ind1 = b_search_lowerbound(100,0,i-1)

    cout << ind<<endl;


    return 0;
}
