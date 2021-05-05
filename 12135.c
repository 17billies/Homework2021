#include<stdio.h>
long long int pre[10000],input[10000];
int main(){
    //使用double精準度才高
    double a,b,c,t,temp=0;
    int n,k;
    int i=0,j=0;

    //輸入
    scanf("%d %d",&n,&k);
    for(i=0;i<n;++i){
        scanf("%lld",&input[i]);
    }

    //prefix sum
    pre[0]=0;
    for(i=0;i<=n;++i){
        pre[i+1]=pre[i]+input[i];
    }

    //利用j夾i的方式窮舉所有average可能性，由大範圍夾到小範圍(k)
    for(j=n;j>0;--j){
        for(i=0;j-i>=k;++i){
            //將int轉換成double，因為int運算不出小數點
            a=(double)i;
            b=(double)j;
            c=(double)pre[j]-pre[i];
            t=c/(b-a);

            //如果運算到較大的average，則以temp紀錄
            if(t>temp){
                temp=t;
           }
        }
    }
    printf("%1.3lf\n",temp);
    return 0;
}


