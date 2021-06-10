#include <stdio.h>
int cmp(const void *a, const void *b);
int a[300005]={0};
int pre[300005]={0};
int main(){
    int t,n,p;
    int k;
    scanf("%d",&t);
    for(int i=0;i<t;++i){
        int temp=0;
        scanf("%d %d %d",&n,&p,&k);
        for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        pre[0]=0;
        pre[1]=a[0];
        if(pre[1]>p){
            printf("0\n");
            continue;
        }
        for(int i=2;i<=n;++i){
            if(i-k<0){
                pre[i]=a[i-1]+pre[i-1];
            }
            else{
                pre[i]=pre[i-k]+a[i-1];
            }
            if(pre[i]>p && pre[i-1]<=p){
                temp=i-1;
            }
            else if(i==n && pre[i]<=p){//when the number is in the last order
                temp=i;
            }
        }
        if(temp==0)printf("%d\n",n);
        else printf("%d\n",temp);

    }






    return 0;
}

int cmp(const void *a, const void *b)//reminder:a pointer in the input
{
      int c = *(int *)a;
      int d = *(int *)b;
      if(c < d) {return -1;}
      else if (c == d) {return 0;}
      else return 1;
}
