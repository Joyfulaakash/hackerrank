#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
    
    char str[11][6] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "even", "odd"};
    int s;
      for (int i=a; i<=b; i++) {
        s = i <= 9 ? i - 1 : 9 + i % 2;
        printf("%s\n", str[s]);
    }

    return 0;
}

