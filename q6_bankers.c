#include <stdio.h>
#define P 5
#define R 3
int avail[R]={3,3,2};
int maxm[P][R]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
int alloc[P][R]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};

int is_safe(int seq[P]) {
    int work[R],finish[P]={0},count=0;
    for(int r=0;r<R;r++) work[r]=avail[r];
    while(count<P) {
        int found=0;
        for(int p=0;p<P;p++) if(!finish[p]) {
            int possible=1;
            for(int r=0;r<R;r++)
                if(maxm[p][r]-alloc[p][r]>work[r]) possible=0;
            if(possible) {
                for(int r=0;r<R;r++) work[r]+=alloc[p][r];
                finish[p]=1; seq[count++]=p; found=1;
            }
        }
        if(!found) return 0;
    }
    return 1;
}
void request_resources(int p,int req[R]) {
    for(int r=0;r<R;r++) {
        if(req[r]>maxm[p][r]-alloc[p][r] || req[r]>avail[r]) {
            printf("P%d request: must wait (not available/claim)\n",p); return;
        }
    }
    for(int r=0;r<R;r++){avail[r]-=req[r];alloc[p][r]+=req[r];}
    int seq[P];
    if(is_safe(seq)) {
        printf("P%d request: granted; safe sequence",p);
        for(int i=0;i<P;i++) printf(" P%d",seq[i]);
        puts("");
    } else {
        for(int r=0;r<R;r++){avail[r]+=req[r];alloc[p][r]-=req[r];}
        printf("P%d request: denied (unsafe)\n",p);
    }
}
int main(void) {
    int seq[P];
    if(is_safe(seq)) {
        printf("Initial state safe:");
        for(int i=0;i<P;i++) printf(" P%d",seq[i]);
        puts("");
    } else puts("Initial state unsafe");
    int q1[R]={1,0,2}; request_resources(1,q1);
    int q2[R]={3,3,0}; request_resources(4,q2);
    int q3[R]={0,2,0}; request_resources(0,q3);
    return 0;
}
