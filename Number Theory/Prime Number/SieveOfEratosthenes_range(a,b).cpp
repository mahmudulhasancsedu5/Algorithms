#include<bits/stdc++.h>
using namespace std;

int marks[1000000];
vector<long long int >primeList;

void isPrimeRange(long long int a,long long int b)
{
    memset(marks,0,sizeof(marks));

    if(a>b) swap(a,b);


    for(long long int i=a;i<=b;i++)
    {
        if(i<=1) marks[i-a]=1;
        if(i%2==0 && i!=2) marks[i-a]=1;
    }
    //cout <<marks[1]<<endl;
    for(int i=3;i*i<=b;i+=2)
    {
        for(int j=i*i;j<=b;j+=i)
        {
            if(j>=a)
            {
                if(marks[j-a]==0)
                    marks[j-a]=1;
            }
        }
    }


    return;

}

int main()
{


    long long int a,b;
    cin>>a>>b;
    isPrimeRange(a,b);
    int ll=b-a+1;
    for(int i=0;i<ll;i++)
    {
        if(marks[i]==0)
        {
            cout <<a+i<<endl;
        }
    }





    return 0;
}
