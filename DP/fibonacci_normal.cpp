#include<bits/stdc++.h>

using namespace std;

long long int fibonacci(int n)
{
    if(n<2) return 1;

    return fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
    int n;
    cin>>n;
    cout<<n<<"th fibonacci number = "<<fibonacci(n)<<endl;



    return 0;
}
