#include<stdio.h>
long long int pre[10000],input[10000];
int main(){
    //�ϥ�double��ǫפ~��
    double a,b,c,t,temp=0;
    int n,k;
    int i=0,j=0;

    //��J
    scanf("%d %d",&n,&k);
    for(i=0;i<n;++i){
        scanf("%lld",&input[i]);
    }

    //prefix sum
    pre[0]=0;
    for(i=0;i<=n;++i){
        pre[i+1]=pre[i]+input[i];
    }

    //�Q��j��i���覡�a�|�Ҧ�average�i��ʡA�Ѥj�d�򧨨�p�d��(k)
    for(j=n;j>0;--j){
        for(i=0;j-i>=k;++i){
            //�Nint�ഫ��double�A�]��int�B�⤣�X�p���I
            a=(double)i;
            b=(double)j;
            c=(double)pre[j]-pre[i];
            t=c/(b-a);

            //�p�G�B�����j��average�A�h�Htemp����
            if(t>temp){
                temp=t;
           }
        }
    }
    printf("%1.3lf\n",temp);
    return 0;
}


