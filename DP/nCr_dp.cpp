#include<bits/stdc++.h>

using namespace std;


long long int ncr_arr[1000][1000];
long long int nCr(int n,int r)
{
    if(r==1) return ncr_arr[n][1]=n;
    if(n==r) return ncr_arr[n][r]=1;

    if(ncr_arr[n][r] != -1) return ncr_arr[n][r];
    else
    {
        ncr_arr[n][r]=nCr(n-1,r)+nCr(n-1,r-1);
        return ncr_arr[n][r];
    }

    return 0;
}

int main()
{
    memset(ncr_arr,-1,sizeof(ncr_arr));

    int n,r;
    cin>>n>>r;
    cout<<n<<"C"<<r<<" is ="<<nCr(n,r)<<endl;



    return 0;
}
