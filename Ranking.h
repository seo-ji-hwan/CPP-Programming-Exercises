#include <cstdio>

struct PlayInfo {
	char	name[200];	// 선수의 이름
	int	nMove;		// 퍼즐 조각을 움직인 횟수
	double	tElapsed;	// 경기 소요 시간
};
extern void loadRanking(const char* filename);
extern void storeRanking(const char* filename);
extern void printRanking();
extern int addRanking(int nMove, double tElap);
