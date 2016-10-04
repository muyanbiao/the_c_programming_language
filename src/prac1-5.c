#include <stdio.h>
/* 当fahr = 300, 280, ..., 20, 0时，打印华氏温度与摄氏温度对照表 */
int main(){
	int fahr;
	printf("fahr\tcelsius\n");
	for (fahr = 300; fahr >=0; fahr = fahr - 20)
		printf("%4d\t%7d\n", fahr, 5 * (fahr - 32) / 9);

	return 0;
}
