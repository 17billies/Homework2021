#include<stdio.h>
typedef struct{
    int idx;
    int al;
    int ln;
} ST;
ST a[100005];
int cmp(const void * a,const void* b){
    ST A=*(ST*)a;
    ST B=*(ST*)b;
    if(A.al>B.al)return 1;
    else if(A.al<B.al)return-1;
    else if(A.ln>B.ln)return 1;
    else if(A.ln<B.ln)return -1;
    else if(A.idx<B.idx)return -1;
    else if(A.idx>B.idx)return 1;
    }
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        a[i].idx=i;
        scanf("%d %d",&a[i].al,&a[i].ln);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(int i=0;i<n;++i){
        printf("%d",a[i].idx+1);
        if(i!=n-1)printf(" ");
        else printf("\n");
    }
    return 0;
}
