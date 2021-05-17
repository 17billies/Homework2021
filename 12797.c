#include<stdio.h>
int main(){
    int n,a,b,c,d;
    int i=0,j=0;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        long long int num[200005]={0};
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        scanf("%d",&d);
        for(j=a;j<=b;++j){
            num[j+b]+=1;
            num[j+c+1]-=1;
            //tag where the number has to start to +1,and tag where to finish(-1)
            //the range of x+y is (a+b)~(b+c)
        }
        for(j=a+b;j<=b+c;++j){
            num[j+1]+=num[j];
            //by prefix sum to complete the tagging
            // 1      1     1    1    -1       -1      -1   -1    => 1 2 3 4 3 2 1
            //(a+b)(a+1+b)     (b+b)(a+c+1)(a+1+c+1)      (b+c+1)
        }
        for(j=b+c;j>=c+1;--j){
           num[j-1]+=num[j];
           //from (b+c) add to (c+1) to know when z=j+1(x+y>z),how many scenerioes would fit
        }
        for(j=c+1;j<=d+1;++j){
            num[j+1]+=num[j];
            //calculate the sum of the triangles from z=c to z=d
        }
        printf("%lld\n",num[d+1]);
    }


    return 0;
}
