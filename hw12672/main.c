#include <stdio.h>
#include <stdlib.h>

int main()
{   int A, B, C,sum;//A=a+b, B=b+c, C=c+a
    scanf("%d %d %d",&A,&B,&C);
    sum=(A+B+C)/2;
    printf("%d %d %d\n",sum-B,sum-C,sum-A);
    return 0;
}
