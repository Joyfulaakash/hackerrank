#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
    int p=0,q=0,r=0,i,j;
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if((i&j) < k && p < (i&j))
            {
                p=i&j;
            }
            if((i|j) < k && q < (i|j))
            {
                q=i|j;
            }
            if((i^j) < k && r < (i^j))
            {
                r=i^j;
            }    
        }
           
    }
    printf("%d\n%d\n%d\n",p,q,r) ;
  //Write your code here.
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}


