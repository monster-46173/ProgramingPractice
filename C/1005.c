#include <stdio.h>
long getCommonDivisor(long n1, long n2);
long getCommonMultiple(long n1, long n2);
typedef struct {
	long numerator;
	long denominator;
} number;
int main(void)
{
	int i, n;
	long commonDivisor, integer;
	number result;
	result.numerator = 0;
	result.denominator = 1;
	scanf("%d", &n);
	number num[n];
	
	for(i = 0; i < n; i++)
	{
		scanf("%ld/%ld", &num[i].numerator, &num[i].denominator);
		commonDivisor = getCommonDivisor(num[i].numerator, num[i].denominator);
		//������ķ�ʽ����Լ�� 
		if(commonDivisor != 1)
		{
			num[i].numerator /= commonDivisor;
			num[i].denominator /= commonDivisor;
		}
		if(num[i].denominator != 0) 
			result.denominator = getCommonMultiple(result.denominator, num[i].denominator);
	}
	//��� 
	for(i = 0; i < n; i++)
		if(num[i].denominator == 0)
			result.numerator += num[i].numerator * result.denominator;
		else
			result.numerator += num[i].numerator * (result.denominator / num[i].denominator);
	//Լ�� 
	commonDivisor = getCommonDivisor(result.numerator, result.denominator);
	result.numerator /= commonDivisor;
	result.denominator /= commonDivisor;
	
	if(result.denominator == 1)
		printf("%ld", result.numerator);
	else if(result.numerator < result.denominator)
		printf("%ld/%ld", result.numerator, result.denominator);
	else
	{
		integer = result.numerator / result.denominator;
		printf("%ld %ld/%ld", integer, result.numerator - integer * result.denominator, result.denominator);
	}
	return 0;
}

long getCommonDivisor(long n1, long n2)
{
	long temp;
	if(n1 < 0)
		n1 = -n1;
	do
	{
		//��֤n1 >= n2 
		if(n1 < n2)
		{
			temp = n1;
			n1 = n2;
			n2 = temp;
		}
		temp = n2;
		n2 = n1 % n2;
		n1 = temp;
	} while(n2 != 0);
	return n1;
}

long getCommonMultiple(long n1, long n2)
{
	n1 /= getCommonDivisor(n1, n2);
	return n1 * n2;
}
