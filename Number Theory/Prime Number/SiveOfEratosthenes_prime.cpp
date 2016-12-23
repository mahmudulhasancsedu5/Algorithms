#include<bits/stdc++.h>
using namespace std;

vector<long long int>prime;
int marks[1000000];

int sieve_prime(long long int n)
{
    // marks 0 means prime and marks 1 means not prime
    memset(marks,0,sizeof(marks));
    marks[1]=1;
    for(int i=2;i*i<=n;i++)
    {
        if(marks[i]==0)
        {
            prime.push_back(i);
            for(int j=i*2;j<=n;j+=i)
            {
                marks[j]=1;

            }
        }
    }

    cout<<marks[n]<<endl;
    return marks[n];


}

int main()
{
    cout<<"Enter a number = "<<endl;
    long long int n;
    cin>>n;

    return 0;
}
