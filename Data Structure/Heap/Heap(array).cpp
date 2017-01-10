#include<bits/stdc++.h>

using namespace std;


int heap_list[1000];
int current_ind=1;




void print_heap(int u)
{
    if(u<current_ind)
    {
        cout <<heap_list[u]<<"["<< u <<"]"<<endl;
        print_heap(2*u);
        print_heap(2*u+1);
    }

    return;



}

void push(int val)
{

    heap_list[current_ind]=val;

    cout<<current_ind<<endl;

    int current_temp=current_ind;
    while(true)
    {
        if(current_temp==1)
        {
            break;
        }
        cout<<val<<"   "<<current_temp<<endl;
        int parent_temp=current_temp/2;
        if(heap_list[parent_temp]<heap_list[current_temp])
        {
            swap(heap_list[parent_temp],heap_list[current_temp]);


        }


        current_temp=parent_temp;


    }

    current_ind++;

    return;


}

int pop()
{


    int last_item_ind=current_ind-1;
    if(last_item_ind==1)
    {
        int top_val=heap_list[1];
        current_ind--;

        return top_val;

    }
    else if(last_item_ind>1)
    {

        int top_val=heap_list[1];
        heap_list[1]=heap_list[current_ind-1];
        current_ind--;

        int temp=1;
        while(temp<current_ind)
        {

            cout<<current_ind<<"-->"<<temp<<endl;
            if(2*temp<current_ind)
            {
                int left=heap_list[2*temp];
                if(2*temp+1<current_ind)
                {
                    int right=heap_list[2*temp+1];
                    if(left>right)
                    {
                        swap(heap_list[temp],heap_list[2*temp]);
                        temp=2*temp;
                    }
                    else
                    {
                        swap(heap_list[temp],heap_list[2*temp+1]);
                        temp=2*temp+1;
                    }

                }
                else
                {
                    if(heap_list[temp]<heap_list[2*temp])
                    {
                        swap(heap_list[temp],heap_list[2*temp]);


                    }
                    temp=current_ind;


                }


            }
            else
            {
                break;
            }


        }

        return top_val;

    }
    else
    {
        cout<<"Heap is empty."<<endl;;
        return 0;
    }

}

int main()
{


    while(true)
    {
        int command;
        cout<<"----------------------------------"<<endl;
        cout<<"PUSH press 1"<<endl;
        cout<<"Pop press 3"<<endl;
        cout<<"exit press 6"<<endl;
        cout<<"Print press 2"<<endl;
        cin>>command;

        if(command==6)
        {
            break;
        }
        else if(command==1)
        {
            int val;
            cout<<"Insert a Value = ";
            cin>>val;
            push(val);


        }
        else if(command==2)
        {
            print_heap(1);
        }
        else if(command==3)
        {
            int top=pop();
            cout<<top<<endl;
        }
    }

    print_heap(1);


    return 0;
}
