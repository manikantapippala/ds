
#include<stdio.h>
#include<stdlib.h>
int count=0;
char a[100];
char* radix_convert(int num,int radix);
  void main()
  {
      int b,n,i;
	char *p;

      printf("\nEnter the decimal number:\n");
      scanf("%d",&n);
      printf("\nEnter the base to be converted:\n");
      scanf("%d",&b);
	printf("\nbase %d equivalent of num %d is ",b,n);
	p=radix_convert(n,b); 
	for(i=count-1;i>=0;--i)
        printf("%c",p[i]);
   	 printf("\n");

}
char* radix_convert(int num,int radix)
{
	int p,r,digit;
	p=num;
     	 do
    	{
        r=p%radix;
        digit='0'+r;
        if(digit>'9')
            digit=digit+7;
        a[count]=digit;
        count++;
        p=p/radix;
         } while(p!=0);
return a;
}
