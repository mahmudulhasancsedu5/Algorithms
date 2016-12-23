#include<bits/stdc++.h>
using namespace std;

vector<int>primeList;
int marks[1000000];

void sievePrime(int n)
{

    for(int i=0;i<=n;i++)
    {

        marks[i]=0;
        if(i<=1) marks[i]=1;
        if(i%2==0 && i!=2) marks[i]=1;
        if(i==2) primeList.push_back(i);
    }

    for(int i=3;i<=n;i+=2 )
    {
        if(marks[i]==0)
        {
            primeList.push_back(i);

            for(int j=i*i;j<=n;j+=i)
            {
                marks[j]=1;
            }
        }
    }

//    int prime_len=primeList.size();
//    for(int i=0;i<prime_len;i++)
//    {
//        printf("%d ",primeList[i]);
//    }
}

int factors_count[100000];
void PrimeFactorization(int num)
{

    int temp=num;
    int p_len=primeList.size();
    for(int i=0;i<p_len;i++)
    {
        int prime=primeList[i];

        while(num%prime==0)
        {
            cout << endl<<prime<<endl;
            factors_count[prime]++;
            num=num/prime;

        }

    }

    num=temp;
    for(int i=2;i<=num;i++)
    {
        if(factors_count[i])
        {
            printf("%d^%d ",i,factors_count[i]);
        }
    }



}

int main()
{

    int num;
    cin>>num;
    sievePrime(num);
    PrimeFactorization(num);




    return 0;
}
