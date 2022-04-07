#include "Ranking.h"
extern int playFifteenPuzzle();
int main()
{
	loadRanking("ranking.txt");
	int rank = playFifteenPuzzle();
	printRanking();
	storeRanking("ranking.txt");
}