#include<stdio.h>
#include<string.h>
int num=0,size;
char str1[2005],str3[2002];
char* reverse(char str2[2002]);
int mission(char str1[2005]);
//主程式
int main(){
    while(scanf("%s",&str1)!=EOF){
         printf("%d\n",mission(str1));
    }
    return 0;
}


//去判斷有幾個equisite substring
int mission(char str1[2005]){
    int num=0;
    int i=0,j=0;
    //紀錄字串長度
    size=strlen(str1);
    for(j=0;j<size-1;++j){//j=選擇字串的起始點
        for(i=size-j;i>=2;--i){//i=取的substring長度
            char str2[2002]={0};//清空字串
            strncat(str2,str1+j,i);//將substring放入新的陣列中
            str2[i]='\0';
            //ex: ababa判斷ab和ba，如果把ba倒過來=ab(function reverse),就表示這個字串是substring
            if(strncmp(str2,reverse(str2),i/2)==0){
                num+=1;
            }
        }
    }
    return num;
}

//一定要加*，好像是指標的用法
char* reverse(char str2[2002]){
    int count=strlen(str2);
    int t;
    //ex:str2=ababa,要把後面ba倒過來
    if (count%2==1){
        //t起始是陣列的最後一個index，t只需要做到總字串數的一半加一
        for(t=count-1;t>=count/2+1;--t){
            //把最後一個字放到新陣列的第一個位子，以此類推
            str3[count-1-t]=str2[t];
        }
    }
    else{
        //偶數t需做到總字串數的一半
        for(t=count-1;t>=count/2;--t){
            str3[count-1-t]=str2[t];
        }
    }
    str3[count]='\0';
    return str3;
}
