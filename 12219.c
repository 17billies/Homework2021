#include <stdio.h>
long long int fpw(long long int a,long long int b, long long int n);
int main(){
    long long int a,b,n;
    scanf("%lld %lld %lld",&a,&b,&n);
    printf("%lld\n",fpw(a,b,n));
    return 0;
}
long long int fpw(long long int a,long long int b, long long int n){
    long long int res;
    if(b==0){
        return 1%n;
    }
    res=fpw(a,b/2,n);
    res=((res%n)*(res%n))%n;
    if(b%2==1){
        res=((res%n)*(a%n))%n;
    }
    return res;
}
