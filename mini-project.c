#include <stdio.h>
#define MAX 5000

char fib1[MAX];
char fib2[MAX];
char result[MAX];

void addition(char num1[], char num2[], char result[])
{
  int carry = 0;
  for (int i = MAX - 1; i >= 0; i--)
  {
    int digit = (num1[i]-'0')+(num2[i]-'0')+carry;
    result[i] = (digit % 10) + '0';
    carry=digit/10;
  }
}

void copy2_1(char num1[], char num2[])
{
  for (int i = MAX - 1; i >= 0; i--)
    num1[i] = num2[i];
}

int main()
{

  for (int i=0;i<MAX;i++)
  {
    fib1[i]=fib2[i]=result[i]='0';
  }
  fib2[MAX - 1]='1';

  int n;
  scanf("%d", &n);

  if(n==0 || n==1)
  {
    printf("%c", n + '0');
  }
  else
  {
    for(int i=2;i<=n;i++)
    {
      addition(fib1, fib2, result);
      copy2_1(fib1, fib2);
      copy2_1(fib2, result);
    }

    int Start=0;
    for (int i=0;i<MAX;i++)
    {
      if (Start==0 && result[i]=='0')
        continue;

      if (Start==0 && result[i]!='0')
        Start=1;
      printf("%c", result[i]);
    }
    printf("\n");
  }
  return 0;
}