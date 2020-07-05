#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1)

int main()
{
    int l,w,h,t;
    double pi,d,v;
    
    while(scanf("%d %d %d %d",&l,&w,&h,&t) == 4)
    {
        d=l*tan(t*PI/180.0);

        if(d <= h)
            v=l*w*((h)-(d*0.5)); 
        else 
            v=0.5*h*h*l*w/d;
            
        printf("%.3lf mL\n", v);
    }
    return 0;
}