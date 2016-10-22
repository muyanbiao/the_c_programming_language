#include <stdio.h>
/* invert(x, p, n)函数：将x中第p位开始的n个(二进制)位求反(即，1变成0,0变成1)，x的其余各位保持不变 */
unsigned invert(unsigned x, int p, int n);

int main(){
	unsigned x;
	int p, n;
	x = 10;
	p = 2;
	n = 3;

	printf("%u\n", invert(x, p, n));
	return 0;
} 

unsigned invert(unsigned x, int p, int n){
	return x ^ (~(~0 << n) << (p+1-n));	
}
