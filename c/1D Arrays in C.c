#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n,s=0;

scanf("%d\n",&n);
int cd[n];
for(int i=0;i<n;i++)
{
    scanf("%d ",&cd[i]);
    s+=cd[i];
}
printf("%d",s);
   
    return 0;
}

