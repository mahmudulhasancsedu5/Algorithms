#include<bits/stdc++.h>
using namespace std;

int graph[21][21];
int nodes=20;


int level[21];
int bfs(int source,int dest)
{
    memset(level,-1,sizeof(level));
    cout<< level[2]<<endl;
    level[source]=0;
    queue<int>q;
    q.push(source);
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();

        for(int i=1;i<=nodes;i++)
        {
            int v=i;
            if(graph[u][v]==1)
            {
                if(level[v]==-1)
                {
                    level[v]=level[u]+1;
                    if(v==dest) return level[v];
                    q.push(v);
                }
            }

        }


    }
    return -1;


}
int graph_input()
{


    memset(graph,0,sizeof(graph));
    int e=20;
    int val;
    char ch;
    char pre_ch_flag=1;

    int u,v;
    int t_case;
    int source,dest;

    while(true)
    {


        if(scanf("%d%c",&val,&ch)==EOF) break;;
        printf("%d %c",val,ch);



        if(e<0)
        {

            int rem=abs(e)%2;
            if(rem==0) source=val;
            else
            {
                if(source==0)
                {

                }
                else
                {
                    dest=val;
                    cout << endl;
                    for(int i=1;i<=nodes;i++)
                    {
                        for(int j=1;j<=nodes;j++)
                        {
                            cout <<graph[i][j]<<" ";
                        }
                        cout << endl;
                    }
                    cout <<" source and dest  = "<<source <<" "<<dest <<endl;

                    cout<<"------------->"<<bfs(source,dest)<<endl;


                }
            }
            e++;
            if(e==0)
            {
                e=21;
            }

        }

        cout <<endl<<"e = "<<e<<endl;
        if(e==1)
        {
            t_case=val;
            cout <<"test case = "<< t_case<<endl;
            e=-(val+val);
        }



        if(ch==' ' && e<=20 && e>1)
        {
            if(pre_ch_flag==1)
            {
                u=val;
                pre_ch_flag=0;
            }
            else
            {
                v=val;
                graph[u][v]=1;
                graph[v][u]=1;
                cout <<" u and v  = "<<u <<" "<<v <<endl;
            }

        }

        if(ch=='\n' && e>1 && e<21)
        {
            if(val==0)
            {

            }
            else
            {
                v=val;
                graph[u][v]=1;
                graph[v][u]=1;
                cout <<" u and v  = "<<u <<" "<<v <<endl;

            }
             pre_ch_flag=1;
            e--;

        }

        if(e==21)
        {
            e=20;
            memset(graph,0,sizeof(graph));
        }


    }



}

int main()
{

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    graph_input();




    return 0;
}
