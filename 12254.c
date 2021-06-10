#include<stdio.h>
#include<stdlib.h>
#define Mod 1000000007

typedef struct Mat{
    long long int a[3][3];
}Mat;
Mat matmul(Mat A,Mat B,int mod);
Mat fpw(Mat A,long long int n);

Mat matmul(Mat A,Mat B,int mod){
    int i=0,j=0,k=0;
    Mat res;
    for(i=0;i<3;++i){for(j=0;j<3;++j){res.a[i][j]=0;}}
    for(i=0;i<3;++i){
        for(j=0;j<3;++j){
            for(k=0;k<3;++k){
                res.a[j][i]+=(A.a[k][i]*B.a[j][k])%mod;//matrix multiply:(0,0)*(0,0)+(1,0)*(0,1)+(2,0)*(0,2)=>(k,i)*(j,k)
            }
            res.a[j][i]=res.a[j][i]%Mod;
        }
    }
    return res;
}

Mat fpw(Mat A,long long int n){
    int i=0,j=0;
    Mat res;
    if(n==1){
        return A;
    }
    res=fpw(A,n/2);
    if(n%2==0){
        return matmul(res,res,Mod);
    }
    if(n%2==1){
        return matmul(A,matmul(res,res,Mod),Mod);
    }
}

int main(){
    Mat A,B;
    int i=0,j=0;
    int t;
    long long int k;//10^18
    for(i=0;i<3;++i){
        for(j=0;j<3;++j){
            A.a[i][j]=0;
            B.a[i][j]=0;
        }
    }
    A.a[0][0]=1;
    A.a[1][0]=2;
    A.a[2][0]=1;
    A.a[0][1]=1;
    A.a[1][2]=1;
    B.a[0][0]=13;
    B.a[0][1]=12;
    B.a[0][2]=1;
    scanf("%d",&t);
    for(int i=0;i<t;++i){
        scanf("%lld",&k);
        if(k<=3){
            printf("%lld\n",B.a[0][3-k]);//because k-3 would be negative
        }
        else{
            printf("%lld\n",matmul(fpw(A,k-3),B,Mod).a[0][0]);
        }
    }
    return 0;
}



