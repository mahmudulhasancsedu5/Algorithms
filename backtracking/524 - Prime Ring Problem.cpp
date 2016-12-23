#include<bits/stdc++.h>


using namespace std;

int primeList[100]= {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1};


int flag[30];
void adj_prime_ring(int arr[],int poss,int n)
{

    if(poss==n)
    {
        for(int i=0; i<n; i++)
            cout <<arr[i]<<" ";
        cout<<endl;
        return;

    }

    for(int i=2; i<=n; i++)
    {

        if(flag[i]==0)
        {
            if(poss>0)
            {

                if(poss==n-1)
                {
                    int num1=arr[poss-1]+i;
                    int num2=i+arr[0];
                    if(primeList[num1]==1 && primeList[num2]==1)
                    {
                        arr[poss]=i;
                        flag[i]=1;
                        adj_prime_ring(arr,poss+1,n);
                        flag[i]=0;





                    }


                }
                else
                {
                    int num=arr[poss-1]+i;
                    if(primeList[num]==1)
                    {



                        arr[poss]=i;
                        flag[i]=1;
                        adj_prime_ring(arr,poss+1,n);
                        flag[i]=0;


                    }

                }




            }
            else
            {
                arr[poss]=i;
                flag[i]=1;
                adj_prime_ring(arr,poss+1,n);
                flag[i]=0;

            }



        }

    }

    return;

}


int main()
{

    for(int i=0; i<40; i++)
    {
        if(primeList[i]==1)
        {
            cout <<i<< " ";
        }
    }
    cout<<endl;
    int n;
    cin>>n;

    int arr[n];
    memset(arr,0,sizeof(arr));
    arr[0]=1;
    adj_prime_ring(arr,1,n);





    return 0;
}
