#include <stdio.h>
#define N 4
int main(void) {
    const char *name[N]={"P1","P2","P3","P4"};
    int arrival[N]={0,1,2,3}, burst[N]={8,4,9,5};
    int quantum=3, left[N], finish[N]={0};
    int queue[100], head=0, tail=0, added[N]={0};
    int time=0, done=0, dispatches=0;
    for(int i=0;i<N;i++) left[i]=burst[i];
    queue[tail++]=0; added[0]=1;
    printf("Gantt: ");
    while(done<N) {
        if(head==tail) {
            time++;
            for(int i=0;i<N;i++)
                if(!added[i] && arrival[i]<=time) { queue[tail++]=i; added[i]=1; }
            continue;
        }
        int p=queue[head++];
        int run=left[p]<quantum?left[p]:quantum;
        printf("%s(%d-%d) ",name[p],time,time+run);
        time+=run; left[p]-=run; dispatches++;
        for(int i=0;i<N;i++)
            if(!added[i] && arrival[i]<=time) { queue[tail++]=i; added[i]=1; }
        if(left[p]>0) queue[tail++]=p;
        else { finish[p]=time; done++; }
    }
    double sum_tat=0,sum_wt=0;
    printf("\nProcess TAT WT\n");
    for(int i=0;i<N;i++) {
        int tat=finish[i]-arrival[i], wt=tat-burst[i];
        sum_tat+=tat; sum_wt+=wt;
        printf("%s %d %d\n",name[i],tat,wt);
    }
    printf("Average TAT=%.2f, Average WT=%.2f\n",sum_tat/N,sum_wt/N);
    printf("Dispatches=%d\n",dispatches);
    return 0;
}
