#include "MineSweeper.h"
void main()
{
	int width,heigh,total;
	printf("MIne Sweeper");
	printf("매설할 총 지뢰의 개수 입력 : ");
	scanf_s("%d", &total);
	playMineSweeper(total);
	
}