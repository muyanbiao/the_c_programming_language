#include <stdio.h>
/* 使用函数实现温度转换计算 */
void temperature_transform(int lower, int upper, int step);
int main(){
	int lower = 0;
	int upper = 300;
	int step = 20;

	temperature_transform(lower, upper, step);

	return 0;
}

void temperature_transform(int lower, int upper, int step){
	int fahr, celsius;
	printf("fahr\tcelsius\n");
	fahr = lower;
	while (fahr <= upper){
		celsius = 5 * (fahr - 32) / 9;
		printf("%4d\t%7d\n", fahr, celsius);
		fahr  = fahr + step;
	}
}
