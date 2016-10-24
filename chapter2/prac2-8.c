#include <stdio.h>
/* rightrot(x, n)函数，返回将x循环右移n位后所得的值 */
unsigned rightrot(unsigned x, int n);

int wordlength(void); /* 计算出运行程序的计算机所使用的子长 */
int main(){
	unsigned x;
	int n;
	x = 100;
	n = 10;
	printf("%u\n", rightrot(x, n));

	return 0;
} 

unsigned rightrot(unsigned x, int n){
	int rbit;	/* rightmost bit */

	while(n-- > 0){
		rbit = (x & 1) << (wordlength() - 1);
		x = x >> 1;
		x = x | rbit;
	}
	return x;
}

int wordlength(){
	int i;
	unsigned v = (unsigned) ~0;

	for (i = 1; (v = v >> 1) > 0; i++)
		;
	return i;
}
