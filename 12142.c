#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(char* a,char* b);
int main(){
    int a,i=0,n;
    char num[200][2000]={0};//count,size
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;++i){
            scanf("%s",num[i]);
        }
        qsort(num,n,sizeof(num[0]),cmp);//void qsort(*array,count_length,size,cmp)
        for(i=n-1;i>=0;--i){
            printf("%s",num[i]);
        }
        printf("\n");
    }
    return 0;
}
int cmp(char* a,char* b){//must have this function for qsort
    char as[2005]={0};
    char bs[2005]={0};
    strcpy(as,a);
    strcat(as,b);
    strcpy(bs,b);
    strcat(bs,a);
    return strcmp(as,bs);
}

