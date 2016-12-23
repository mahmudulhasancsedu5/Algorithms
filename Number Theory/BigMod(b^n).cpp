#include<bits/stdc++.h>


using namespace std;



int bigMod(int base,int power,int mod)
{
    if(power==1) return base;
    if(power==0) return 1;

    int a=bigMod(base,power/2,mod);

    a=(a*a)%mod;
    if(power%2==1)
    {
        a=(a*base)%mod;
    }

    return a;






}

int main()
{

    int base,power,mod;

    cin>>base>>power>>mod;

    cout<<bigMod(base,power,mod)<<endl;


    return 0;
}
