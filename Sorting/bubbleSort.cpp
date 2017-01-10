#include<bits/stdc++.h>

#define N 10


using namespace std;


int arr[]={2,1,51,44,7,6,8,10,9,3};
void bubbleSort(int items[])
{

    for(int i=0;i<N;i++)
    {
        int flag=0;
        for(int j=0;j<N-1-i;j++)
        {
            if(items[j]>items[j+1])
            {
                swap(items[j],items[j+1]);
                flag=1;
            }
        }
        if(flag==0) break;

    }

}
int main()
{


    bubbleSort(arr);
    for(int i=0;i<N;i++)
        cout<<arr[i]<<endl;


}
