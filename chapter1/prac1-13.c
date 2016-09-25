#include <stdio.h>
/* 打印输入中单词长度的水平直方图 */
#define MAX_WORD_NUM 100
#define IN 1
#define OUT 0
int main(){
	int c, lwtemp, state, nw;
	int lw[MAX_WORD_NUM]; 		/* 单词的长度数组 */
	state = OUT;
	lwtemp = 0; 			/* 读取到的单词的临时长度 */
	nw = 0;				/* 单词数量 */	
	for (int i = 0; i < 100; ++i)
		lw[i] = 0;

	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\t' || c == 'n'){
			state = OUT;
			if (state == IN){
				lw[nw++] = lwtemp;
				lwtemp = 0;
			}
		} else {
			state = IN;
			++lwtemp;
		}
	}

	for (int i = 0; i < nw; ++i){
		printf("lw: %d", lw[i]);
	}
	printf("\n");

	return 0;
}
