#include<stdio.h>
int gcd(int a,int b);
int main(){
    int n,temp=0;//temp�n�k�s
    int i=0,j;
    int a[1005];
    scanf("%d",&n);
    for(i=0;i<n;++i){
       scanf("%d",&a[i]);
    }
    //�Q�Ψ�Ӱj��h����n���Ʀr��m
    for(i=0;i<n;++i){
        for(j=i+1;j<n;++j){
           if(gcd(a[i],a[j])>temp){
            temp=gcd(a[i],a[j]);
           }
        }
    }
    printf("%d\n",temp);
    return 0;
}

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    else{
        gcd(b,a%b);
    }
}
