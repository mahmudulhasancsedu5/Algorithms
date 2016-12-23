/*

//produce permutation of any input string



*/

#include<bits/stdc++.h>
using namespace std;


string pattern;
bool flags[1000000];
int total_permutations=0;
void permutation(string str,int poss)
{
    if(poss==pattern.size())
    {
        total_permutations++;
        cout<< str<<endl;
        return;
    }

    int arr[256];
    memset(arr,0,sizeof(arr));
    for(int i=0;i<pattern.size();i++)
    {

        if(flags[i]==0 && arr[pattern[i]]==0)
        {

            arr[pattern[i]]=1;


            flags[i]=1;

            string tempStr=str+pattern[i];

            permutation(tempStr,poss+1);

            flags[i]=0;



        }

    }

    return;





}

int main()
{
    cin>>pattern;


    permutation("",0);
    cout<<"Total Permutations = "<<total_permutations<<endl;





    return 0;
}

