#include <stdio.h>
/* 统计空格，制表符与换行符的个数 */
int main(){
	int nwhite, ntab, nnext;
	nwhite = 0;	// 空格的个数
	ntab = 0;	// 制表符的个数
	nnext = 0;	// 换行符的个数

	int c;
	while ((c = getchar()) != EOF){
		if (c == ' '){
			nwhite = nwhite +1;
		} else if (c == '\t'){
			ntab = ntab + 1;
		} else if (c == '\n'){
			nnext = nnext + 1;
		}
	}
	printf("nwhite\tntab\tnnext\n");
	printf("%6d\t%4d\t%5d\n", nwhite, ntab, nnext);

	return 0;
}
