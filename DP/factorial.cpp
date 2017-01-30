#include<bits/stdc++.h>

using namespace std;

long long int factorial(int n)
{
    if(n<2) return 1;
    return n*factorial(n-1);

}

int main()
{
    int n;
    cin>>n;
    cout<<n<<"! is = "<<factorial(n)<<endl;



    return 0;
}
