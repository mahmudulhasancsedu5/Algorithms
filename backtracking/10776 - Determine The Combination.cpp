/*

//produce permutation of any input string



*/

#include<bits/stdc++.h>
using namespace std;


string pattern;
bool flags[1000000];
int total_permutations=0;
vector<string>ans;
void permutation(string str,int poss,int r)
{
    if(poss==r)
    {
        total_permutations++;
        ans.push_back(str);
        cout<< str<<endl;
        return;
    }

    int arr[256];
    memset(arr,0,sizeof(arr));
    for(int i=0; i<pattern.size(); i++)
    {

        if(flags[i]==0 && arr[pattern[i]]==0)
        {

            if(poss>0)
            {
                if(str[poss-1]<=pattern[i])
                {
                    arr[pattern[i]]=1;


                    flags[i]=1;

                    string tempStr=str+pattern[i];

                    permutation(tempStr,poss+1,r);

                    flags[i]=0;

                }
            }
            else
            {
                arr[pattern[i]]=1;


                flags[i]=1;

                string tempStr=str+pattern[i];

                permutation(tempStr,poss+1,r);

                flags[i]=0;



            }





        }

    }

    return;





}

int main()
{
    cin>>pattern;
    int r;
    cin>>r;




    permutation("",0,r);
    cout<<"Total Permutations = "<<total_permutations<<endl;

    int ans_num=ans.size();
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans_num;i++)
    {
        cout << ans[i]<<endl;
    }





    return 0;
}

