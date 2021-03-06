#include <stdio.h>
long get(long,long);
void formatPrint(long,long);
const char options[] = {'+','-','*','/'};
/*
  Author:zoe(tudouzi)
  Date: 2019/12/16 22:32:36
*/

int main()
{
	long a1,a2,b1,b2;
	int i;
	scanf("%ld/%ld %ld/%ld",&a1,&b1,&a2,&b2);
	
	for(i = 0;i < 4;i ++){
		formatPrint(a1,b1);
		printf(" %c ",options[i]);
		formatPrint(a2,b2);
		printf(" = ");
		if(options[i] == '+'){
			formatPrint(a1 * b2 + a2 * b1,b1 * b2);
		}else if(options[i] == '-'){
			formatPrint(a1 * b2 - a2 * b1,b1 * b2);
		}else if(options[i] == '*'){
			formatPrint(a1 * a2,b1 * b2);
		}else if(options[i] == '/'){
			formatPrint(a1 * b2, a2 * b1);
		}
		printf("\n");
	}
	
    return 0;
}

long get(long a, long b){
	return b == 0? a : get(b,a % b);
}

void formatPrint(long a,long b){
	
	if(b == 0){
		printf("Inf");
		return;
	}
	int isNavigate = 0;
	if(a < 0){
		a = -a;
		isNavigate = !isNavigate;
	}
	if(b < 0){
		b = -b;
		isNavigate = !isNavigate;
	}
	
	long dem = get(a,b);
	a /= dem;
	b /= dem;
	
	if(isNavigate){
		printf("(-");
	}
		
	if(a/b && a%b){
		printf("%ld %ld/%ld",a/b,a%b,b);
	}else if(a%b){
		printf("%ld/%ld",a%b,b);
	}else{
		printf("%ld",a/b);
	}
		
	if(isNavigate){
		printf(")");
	}
}

