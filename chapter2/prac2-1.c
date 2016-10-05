#include <stdio.h>
#include <limits.h>
/* 确定分别由signed及unsigned限定的char, short, int, long类型变量的取值范围。采用打印标准头文件中的相应值以及直接计算两种方式实现 */
int main(){
	printf("signed char range: %d ~ %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("unsigned char MAX: %u\n",  UCHAR_MAX);
	printf("signed short range: %d ~ %d\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short MAX: %u\n",  USHRT_MAX);
	printf("signed int range: %d ~ %d\n", INT_MIN, INT_MAX);
	printf("unsigned int MAX: %u\n", UINT_MAX);
	printf("signed long range: %ld ~ %ld\n", LONG_MIN, LONG_MAX);
	printf("unsigned long MAX: %lu\n",  ULONG_MAX);
}
