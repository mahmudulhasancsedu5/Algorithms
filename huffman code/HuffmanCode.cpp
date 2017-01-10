#include<bits/stdc++.h>
using namespace std;


map<string,int>str_to_int;
map<int,string>int_to_str;
map<string,string>code_mp;


int f[1000];
int f_2[1000];

int parent[1000];
int L[1000];
int R[1000];
int nodes;
int leafNode;
int root;


int select_min()
{
    int min_val=1000000;
    int ii=-1;
    cout<<"nodes = "<<nodes<<endl;
    for(int i=1; i<nodes; i++)
    {
        cout<<i<<"  "<<f[i]<<endl;
        if(f[i]!=-1)
        {
            if(min_val>f[i])
            {
                min_val=f[i];
                ii=i;
            }

        }
    }
    if(ii!=-1)
    {
        cout<<f[ii]<<endl;
        f_2[ii]=f[ii];
        return ii;
    }
    else
    {

        cout<<"Error"<<endl;
        return -1;
    }



}

void huffmanTree()
{
    memset(parent,-1,sizeof(parent));

    memset(L,-1,sizeof(L));
    memset(R,-1,sizeof(R));

    for(int i=1; i<leafNode; i++)
    {
        int a=select_min();
        int f_a=f[a];
        f[a]=100000;
        int b=select_min();
        int f_b=f[b];
        f[b]=100000;

        if(b==-1)
        {

            root=a;
            break;
        }

        cout<<a<<"<---node pair---->"<<b<<endl;
        cout <<f_a<<"<--fre--->"<<f_b<<endl;
        cout<<" next node = "<<nodes<<endl;

        int sum=f_a+f_b;
        int nn=nodes++;

        f[nn]=sum;
        L[nn]=a;
        R[nn]=b;
        parent[a]=nn;
        parent[b]=nn;
        cout <<a<<" parent ="<<parent[a]<<endl;
        cout <<b<<" parent ="<<parent[b]<<endl;
        cout <<nn<<endl;


    }



}

void gen_code()
{
    for(int i=1; i<=leafNode; i++)
    {
        int j=i;
        string path="";
        while(parent[j]!=-1)
        {
            int p=parent[j];
            if(L[p]==j)
            {
                path+='0';
            }
            else
            {
                path+='1';
            }
            j=p;

        }
        reverse(path.begin(),path.begin()+path.size());
        cout<<i<<"  "<<path<<endl;
        code_mp[int_to_str[i]]=path;
    }
}
void zipping()
{


}
void unzipping()
{

}
int main()
{
    freopen("uncompressed.txt","r",stdin);


    char ch;
    int arr[30];
    memset(arr,0,sizeof(arr));
    while(cin>>ch)
    {
        arr[ch-97]+=1;

    }


    int ff;
    string val;
    int cc=1;
    memset(f,-1,sizeof(f));
    memset(f_2,-1,sizeof(f_2));
    for(int i=0; i<30; i++)
    {
        if(arr[i]!=0)
        {
            val=i+'a';
            ff=arr[i];
            cout<<val<<" --- "<<ff<<endl;

            str_to_int[val]=cc++;
            int_to_str[cc-1]=val;

            f[str_to_int[val]]=ff;

        }
    }



    nodes=cc;
    leafNode=cc-1;
    huffmanTree();

    for(int i=1; i<nodes; i++)
    {
        if(i<=leafNode)
        {
            cout<<i<<" fre = "<<f_2[i]<<"  parent = "<<parent[i]<<endl;
        }
        else
        {
            cout<<"non leaf "<<i<<"  fre = "<<f_2[i]<<"  left = "<<L[i]<<"    right = "<<R[i]<<" parent"<<parent[i]<<endl;
        }
    }
    gen_code();


    return 0;
}
