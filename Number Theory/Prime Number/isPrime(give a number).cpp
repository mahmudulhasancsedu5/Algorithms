#include<bits/stdc++.h>
using namespace std;

int isPrime_O_N(long long int n)
{
    int start_c=clock();
    if(n<=1) return 0;
    for(long long int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            cout <<"divisor = "<<i<<endl;
            return 0;
        }
    }
    int end_c=clock();
    cout << "Time Need in O(n) milliseconds = "<<end_c-start_c<<endl;
    return 1;

}
int isPrime_O_N_by_2(long long int n)
{
    int start_c=clock();
    if(n<=1) return 0;
    if(n>2 && n%2==0) return 0;
    for(long long int i=3;i<n;i+=2)
    {
        if(n%i==0)
        {
            cout <<"divisor = "<<i<<endl;
            return 0;
        }
    }
    int end_c=clock();
    cout <<"Time need in O(n/2) milliseconds = "<<end_c-start_c<<endl;
    return 1;

}
int isPrime_O_sqrt(long long int n)
{
    int start_c=clock();
    if(n<=1) return 0;
    if(n>2 && n%2==0) return 0;

    for(int i=3;i*i<n;i+=2)
    {
        if(n%i==0) {
                cout <<"divided by = "<<i<<endl;
                return 0;
        }

    }
    int end_c=clock();
    cout << "Time need in O(sqrt(n)) in milliseconds = "<<end_c-start_c<<endl;
    return 1;


}
//99999989
int main()
{

    long long int n;
    cout <<"Enter a number:";
    cin>>n;
    if(isPrime_O_N(n)==1) cout << n <<" is prime."<<endl;
    else cout << n <<" is not prime."<<endl;

    if(isPrime_O_N_by_2(n)==1) cout << n <<" is prime."<<endl;
    else cout << n <<" is not prime."<<endl;

    if(isPrime_O_sqrt(n)==1) cout << n <<" is prime."<<endl;
    else cout << n <<" is not prime."<<endl;

    return 0;
}
