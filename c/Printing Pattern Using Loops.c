#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
    int start,end,i,j;
    end=2*n-1;
    start=0;
    int m=n;
    int ar[end][end];
    while(n!=0)
    {
  	// Complete the code to print the pattern.
      for (int i=start; i<end;i++) {
          for (int j=start; j<end; j++) {
              ar[i][j]=n;
          }
      }start++;end--;n--;
    }
    m=2*m-1;
    for(i=0;i<m;i++)
{for(j=0;j<m;j++)
    printf("%d ",ar[i][j]);
    printf("\n");
}    return 0;
}

