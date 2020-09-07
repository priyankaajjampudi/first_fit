#include<stdio.h>
int memlayout[10];
int firstfit(int m, int r)
{
     int i,flag=0;
     for(i=0;i<m;i++)
     {
           if(r<memlayout[i])
          {
               memlayout[i]=memlayout[i]-r;
               printf("%d is allocated in  %d segment\n",r,i+1);
               flag=1;
               break;
          }
     }
if(flag==0)
       printf("memory is not allocated for this %d request",r);
if(flag==1)
       return 1;
else
      return 0;
}
int main()
{
     int request[10],i,c=0,m,n,check;
     printf("enter no of memory partitions and requests");
     scanf("%d%d",&m,&n);
     printf("read memeory layout");
     for(i=0;i<m;i++)
          scanf("%d",&memlayout[i]);
     printf("read request");
     for(i=0;i<n;i++)
          scanf("%d",&request[i]);
     for(i=0;i<n;i++)
     {
            check=firstfit(m,request[i]);
            if(check==1)
                 c++;
      }
    printf("%d are requests are serviced",c); 
}

