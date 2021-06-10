#include<stdio.h>
int cmp(const void *a, const void *b);
typedef struct Pro{
    int past;
    int now;
    int dif;
}Pro;

int main(){
    int n,k;
    long long int total=0;
    Pro product[100005];
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d",&product[i].past);
    }
    for(int i=0;i<n;++i){
        scanf("%d",&product[i].now);
        product[i].dif=product[i].past-product[i].now;
    }
    qsort(product,n,sizeof(product[0]),cmp);
    for(int i=0;i<n;++i){
        if(i<k){
            total+=product[i].past;
        }
        else if(product[i].dif<0){
            total+=product[i].past;
        }
        else{
            total+=product[i].now;
        }
    }
    printf("%lld\n",total);
    return 0;
}
int cmp(const void *a, const void *b)//reminder:a pointer in the input
{
      struct Pro c = *(struct Pro*)a;
      struct Pro d = *(struct Pro*)b;

      if(c.dif < d.dif) {return -1;}
      else if (c.dif == d.dif) {return 0;}
      else return 1;
}
