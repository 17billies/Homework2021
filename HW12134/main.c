#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,x,y;
    scanf("%d.%d %d.%d",&a,&b,&c,&d);
    x=a*100+b;
    y=c*100+d;
    printf("%d.%04d\n",x*y/10000,x*y%10000);
    return 0;
}
