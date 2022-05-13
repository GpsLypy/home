#include<stdio.h>
#include <string.h>
#define MAX 100
int main()
{

    int s[]={0,1,1,2,3,5,8,13,21,34};
    printf("%d\n",sizeof(s)/sizeof(int));
    int n=sizeof(s)/sizeof(int);
    printf("%d\n",n); 
    int j;
    int ii=0;
    
    scanf("%d",&j);
    for(ii=0;ii<n;ii++){
        if(j==(s[ii])){
            printf("%d\n",ii+1); 
            break;
        }
    }

    if(ii==n) printf("-1");
    
    return 0;
}


