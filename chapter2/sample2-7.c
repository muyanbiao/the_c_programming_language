#include <stdio.h>
/* atoi函数，lower函数，rand函数，srand函数 */
int atoi(char s[]);
int lower(int c);
int rand(void);
void srand(unsigned int seed);

unsigned long int next = 1;

int main(){
	return 0;
}

/* atoi函数：将字符串s转换成相应的整数值 */
int atoi(char s[]){
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i){
		n = 10 * n + (s[i] - '0');
	}
	return n;
}

/* lower函数：把字符c转换为小写形式，只对ASCII字符集有效 */
int lower(int c){
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

/* rand函数：返回取值在0～32767之间的伪随机数 */
int rand(void){
	next = 1103515245 + 12345;
	return (unsigned int)(next/65536) % 32768;
}

/* srand函数：为rand()函数设置种子数 */
void srand(unsigned int seed){
	next = seed;
}
