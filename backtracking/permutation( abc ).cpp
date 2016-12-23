/*

//produce permutation of any input string



*/

#include<bits/stdc++.h>
using namespace std;


string pattern;
bool flags[1000000];
void permutation(string str,int counts)
{
    if(counts==pattern.size())
    {
        cout<< str<<endl;
        return;
    }

    for(int i=0;i<pattern.size();i++)
    {

        if(flags[i]==0)
        {

            flags[i]=1;
            string tempStr=str+pattern[i];
            permutation(tempStr,counts+1);
            flags[i]=0;
        }

    }

    return;





}

int main()
{
    cin>>pattern;


    permutation("",0);





    return 0;
}
