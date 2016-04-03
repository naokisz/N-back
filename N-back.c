#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int newpage() {

	int i;

	for(i = 0; i < 1000; i++) {
		printf("\n");
	}

	return 0;
}

int main(int argc, char *argv[]) {

	int player, back, question1, question2;
	int *answer;
	FILE *fp;

	srand(time(NULL));

	if((fp = fopen(back.txt, "a+")) == NULL) {
		fprintf(stderr, "%sのオープンに失敗しました.\n", filename);
		exit(1);
	}

	if(fscanf(fp, "%d", &back) == EOF) {
		back = 0;
	}

	if((answer = malloc(sizeof(int) * (back + 1))) == NULL) {
		fprintf(stderr, "メモリ確保に失敗しました。\n");
		exit(1);
	}

	printf("%d-バック\n", back);
	printf("始めるにはreturnキーを押してください。＞");
	rewind(stdin);
	getchar();

	for(i = back;;i--) {

		if(i == 0) { break; }
		question1 = (int)(((double)rand() / RAND_MAX) * 10);
		question2 = (int)(((double)rand() / RAND_MAX) * 10);
		answer[i] = question1 + question2;

		printf("%d + %d\n", question1, question2);
		sleep(2);
		newpage();
	}


