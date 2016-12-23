#include<bits/stdc++.h>
using namespace std;



double mysqrt(double val,double low,double heigh,double precision)
{
    if(heigh-low<=precision)
    {
        cout <<heigh << "   "<<low<<endl;
        return low;
    }
    else
    {
        double mid=(low+heigh)/2.0;
        cout <<mid<< "  "<< val<<" low = "<<low <<"  high = "<< heigh <<endl;
        if(mid*mid>val) return mysqrt(val,low,mid,precision);
        else if(mid*mid<val) return mysqrt(val,mid,heigh,precision);

    }



}
int main()
{

    double val=mysqrt(11.0,0.0,11.0,0.00000000001);

    printf("%f",val);

    return 0;
}
