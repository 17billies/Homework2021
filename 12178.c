#include<stdio.h>
int test1(int x, int y);
int test2(int x, int y);
void queen(int row,int a);
void castle(int row,int b);
int col[81]={0}, cnt1[81]={0}, cnt2[81]={0};
int n,r;
int x,y,row,ans=0;
int cnt_ca=0,cnt_qu=0;
int main(){
    scanf("%d %d",&n,&r);
    cnt_ca=r;
    cnt_qu=n;
    queen(0,n);
    castle(0,r);
    printf("%d\n",ans);
    return 0;
}
int test1(int x, int y){//test queen(diag cannot have castle or queen)
    if(col[y]==1 | cnt1[x-y+35]>=1 | cnt2[x+y]>=1){
        return 0;
    }
    else{
        return 1;
    }
}
int test2(int x, int y){//test castle
    if(col[y]==1 | cnt1[x-y+35]==1 | cnt2[x+y]==1){
        return 0;
    }
    else{
        return 1;
    }
}
void queen(int row,int a){
    int y=0,temp;
    if(a==0)return;//if there is no chess left then return
    else{
        for(y=0;y<n+r;++y){
            if(test1(row,y)==1){
                col[y]=1;
                cnt1[row-y+35]=1;
                cnt2[row+y]=1;
                temp=cnt_qu;//to record the amount of the queen left
                cnt_qu--;
                if(row==n+r-1)ans++;//when row to the end
                queen(row+1,cnt_qu);
                castle(row+1,cnt_ca);
                cnt_qu=temp;//return to the previous senario
                col[y]=0;
                cnt1[row-y+35]=0;
                cnt2[row+y]=0;
            }
        }
    }
}
void castle(int row,int b){
    int y=0,temp;
    if(b==0)return;
    else{
        for(y=0;y<n+r;++y){
            if(test2(row,y)==1){
                col[y]=1;
                if(cnt1[row-y+35]!=1)cnt1[row-y+35]+=2;//unless the cnt has a queen in it,we have to know how many castle in it
                if(cnt2[row+y]!=1)cnt2[row+y]+=2;
                temp=cnt_ca;
                cnt_ca--;
                if(row==n+r-1)ans++;
                queen(row+1,cnt_qu);
                castle(row+1,cnt_ca);
                cnt_ca=temp;
                col[y]=0;
                if(cnt1[row-y+35]!=1)cnt1[row-y+35]-=2;//when one of the castle finish the loop, delete the mark which doesn't impact the other marks from the other castle
                if(cnt2[row+y]!=1)cnt2[row+y]-=2;
            }
        }
    }
}

