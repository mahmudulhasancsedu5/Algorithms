#include<bits/stdc++.h>

using namespace std;

long long int fibonacci_arr[100000];
long long int fibonacci_dp(int n)
{
    if(n<2) return 1;
    else
    {
        if(fibonacci_arr[n]>-1) return fibonacci_arr[n];
        fibonacci_arr[n-1]=fibonacci_dp(n-1);
        fibonacci_arr[n-2]=fibonacci_dp(n-2);

        return fibonacci_arr[n-1]+fibonacci_arr[n-2];
    }




}

int main()
{
    memset(fibonacci_arr,-1,sizeof(fibonacci_arr));
    fibonacci_arr[0]=1;
    fibonacci_arr[1]=1;
    int n;
    cin>>n;
    cout<<n<<"th fibonacci number = "<<fibonacci_dp(n)<<endl;



    return 0;
}
