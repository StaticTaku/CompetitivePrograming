#include <bits/stdc++.h>
#define PI acos(-1)

using namespace std;

int main()
{
    double a,b,c,S,p,r,R,S1,S2,S3;
    
    while(cin >> a >> b >> c)
    {
        p = 0.5*(a+b+c);
        S = sqrt(p*(p-a)*(p-b)*(p-c));        
        R = a*b*c/4/S;        
        r = sqrt((p-a)*(p-b)*(p-c)/p);
        
        S1 = PI*R*R-S;
        S3 = PI*r*r;
        S2 = S-S3;
        
        printf("%.4f %.4f %.4f\n",S1,S2,S3);
    }
}