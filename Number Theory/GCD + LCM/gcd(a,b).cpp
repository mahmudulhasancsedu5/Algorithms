#include<bits/stdc++.h>


using namespace std;

int gcd(int a,int b)
{
    if(a<b) swap(a,b);
    return b==0?a:gcd(b,a%b);
}


int gcd_array(int arr[],int n)
{
    int g=gcd(arr[0],arr[1]);
    for(int i=2;i<n;i++)
    {
        g=gcd(g,arr[i]);
    }

    return g;

}


int LCM(int a,int b)
{

    int g=gcd(a,b);

    if(g==0) return  0;

    return (a*b)/g;



}
int LCM_array(int arr[],int n)
{

    int l=LCM(arr[0],arr[1]);
    for(int i=2;i<n;i++)
    {

        l=LCM(l,arr[i]);


    }

    return l;

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

    cout<<"GCD = " << gcd_array(arr,n)<<endl;

    return 0;
}
