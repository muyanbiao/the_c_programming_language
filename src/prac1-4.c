#include <stdio.h>
/* 当celsius = -17, -6, ....., 148时，打印摄氏温度与华氏温度对照表，整数版本 */
int main(){
	int fahr, celsius;
	int lower, upper, step;
	
	lower = -17;	/* 温度表下限 */
	upper = 148;	/* 温度表上限 */
	step = 11;	/* 步长 */

	printf("celsius\tfahr\n");
	celsius = lower;
	while (celsius <= upper){
		fahr = 9 * (celsius + 32) / 5;
		printf("%7d\t%4d\n", celsius, fahr);
		celsius += 11;
	}
	
	return 0;
}
