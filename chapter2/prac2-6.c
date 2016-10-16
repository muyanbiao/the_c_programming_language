#include <stdio.h>
/* 函数setbits(x, p, n, y)，该函数返回对x执行下列操作后的结果值：将x中从第p为开始的n个(二进制)位设置为y中最右边n位的值，x的其余各位保持不变*/

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(){
	unsigned int x, y;
	int p, n;
	unsigned int result;
	x = 12;
	p = 2;
	n = 2;
	y = 11;
	result = setbits(x, p, n, y);
	printf("%u\n", result);
	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y){
	return x & ~(~(~0 << n) << (p + 1 - n)) |
		(y & ~(~0 << n)) << (p + 1 - n);
}
