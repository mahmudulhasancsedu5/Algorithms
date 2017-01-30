#include<bits/stdc++.h>

using namespace std;

struct node
{

    int key;
    node* p;
    node* next;

    node()
    {
        p=NULL;
        next=NULL;
    }
    node(int key)
    {
        this->key=key;
        this->p=NULL;
        this->next=NULL;
    }



};

node* head=NULL;

void list_insert(node* root,int val)
{
    node* temp=new node(val);
    if(root==NULL)
    {
        head=temp;
    }
    else
    {
        node* current=root;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        temp->p=current;
        current->next=temp;

    }

    return;


}

void list_print(node* root)
{
    node* current=root;
    while(current!=NULL)
    {
        cout<<current->key<<"  ";
        current=current->next;
    }

}

node* list_search(node* root,int val)
{
    node*current=root;

    while(current!=NULL && current->key!=val)
    {
        current=current->next;
    }
    return current;
}

int find_mid_value_linklist(node* root)
{
    node* current=root;
    int arr[1000];

    int i=0;
    while(current!=NULL)
    {
        arr[i++]=current->key;
        current=current->next;

    }

    int mid=i/2;

    return arr[mid];


}
int main()
{
    list_insert(head,10);
    list_insert(head,40);
    list_insert(head,30);
    list_insert(head,50);
    list_insert(head,80);
    list_insert(head,5);
    list_insert(head,20);

    list_print(head);


    int sc_val=55;
    node* sc_node=list_search(head,sc_val);
    if(sc_node!=NULL)
    {
        cout<<endl<<sc_node->key<<" found."<<endl;
    }
    else
    {
        cout<<endl<<sc_val<< " Not Found."<<endl;
    }

    int mid_val=find_mid_value_linklist(head);
    cout<<"mid value is = "<<mid_val<<endl;



    return 0;
}
