#include <stdio.h>
/* 打印输入中各个字符出现品读的直方图 */
int main(){
	int c;
	int ndigit[10];		/* 统计数字的数量 */
	int nlower[26];		/* 统计小写字母的数量 */
	int nupper[26];		/* 统计大写字母的数量 */
	for (int i = 0; i < 26; ++i){
		if (i < 10) ndigit[i] = 0;
		nlower[i] = 0;
		nupper[i] = 0;
	}
	while ((c = getchar()) != EOF){
		if (c >= '0' && c <= '9'){
			++ndigit['9' - c];
		}

		if (c >= 'a' && c <= 'z'){
			++nlower['z' - c];
		}

		if (c >= 'A' && c <= 'Z'){
			++nupper['Z' - c];
		}
	}

	for (int i = 0; i < 10; ++i){
		if (ndigit[i] > 0){
			putchar(i + '0');
			printf(" | ");
			for (int j = 0; j < ndigit[i]; ++j){
				printf("*");
			}
			printf("\n");
		}
	}

	printf("\n");

	for (int i = 0; i < 26; ++i){
		if (nlower[i] > 0){
			putchar(i + 'a');
			printf(" | ");
			for (int j = 0; j < nlower[i]; ++j){
				printf("*");
			}
			printf("\n");
		}
	}
	
	printf("\n");

	for (int i = 0; i < 26; ++i){
		if (nupper[i] > 0){
			putchar(i + 'A');
			printf(" | ");
			for (int j = 0; j < nupper[i]; ++j){
				printf("*");
			}
			printf("\n");
		}	
	}

	printf("\n");

	return 0;
}
