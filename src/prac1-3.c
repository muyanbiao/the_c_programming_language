#include <stdio.h>
/* 当 fahr = 0, 20, ..., 300 时，分别打印华氏温度与摄氏温度对照表 */
int main(){
	int fahr, celsius;
	int lower, upper, step;
	
	lower = 0;		/* 温度表的下限 */
	upper = 300;	        /* 温度表的上限 */
	step = 20;		/* 步长 */
	
	fahr = lower;
	printf("fahr\tcelsius\n");	/* print the title */
	while (fahr <= upper){
		celsius = 5 * (fahr - 32) / 9;
		printf("%4d\t%7d\n", fahr, celsius);
		fahr += 20;
	}
	
	return 0;
	
}
