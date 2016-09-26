#include <stdio.h>
/* 统计各个数字，空白符以及其他字符出现的次数 */
int main(){
	int c, i, nwhite, nother;
	int ndigit[10];
	nwhite = nother = 0;
	for (i = 0; i < 10; ++i){
		ndigit[i] = 0;
	}

	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\t' || c == '\n'){
			++nwhite;	
		} else if (c >= '0' && c <= '9'){
			++ndigit[c-'0'];
		} else {
			++nother;
		}
	}
	printf("ndigit:");
	for (i = 0; i < 10; ++i){
		printf(" %d", ndigit[i]);
	}
	printf("\nnwhite: %d", nwhite);
	printf("\nnother: %d\n", nother);
	return 0;
}