#include<bits/stdc++.h>



using namespace std;



int pattern[1000000];
int counts_pattern=0;
void permutation(int arr[],int poss,int n)
{
   //cout<<"-->"<<poss<<endl;
    if(poss==n)
    {
        counts_pattern+=1;
//        for(int i=0;i<n;i++){
//                cout<<" "<<pattern[i]<<" ";
//
//        }
//        cout <<endl;

        return;

    }

    for(int i=0;i<n;i++)
    {

        if(arr[i]==0)
        {
            arr[i]=i+1;
            pattern[poss]=i;

            permutation(arr,poss+1,n);

            arr[i]=0;
        }
    }

    return;

}

int main()
{

    int n;
    cin>>n;
    int arr[n];
    memset(arr,0,sizeof(arr));
    permutation(arr,0,n);

    cout <<"Total permutations = "<<counts_pattern<<endl;






    return 0;
}
