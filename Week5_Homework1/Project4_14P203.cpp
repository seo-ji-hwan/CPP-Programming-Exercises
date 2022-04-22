﻿#include "MineSweeper.h"
#define DIM	9

enum LabelType { Empty = 0, Bomb = 9 };
enum MaskType { Hide = 0, Open, Flag };
static int	MineMapMask[DIM][DIM];		
static int	MineMapLabel[DIM][DIM];		
static int	nx = DIM, ny = DIM;
static int	nBomb = DIM;


inline int& mask(int x, int y) { return MineMapMask[y][x]; }
inline int& label(int x, int y) { return MineMapLabel[y][x]; }
inline bool	isValid(int x, int y) { return (x >= 0 && x < nx&& y >= 0 && y < ny); }
inline bool	isBomb(int x, int y) { return isValid(x, y) && label(x, y) == Bomb; }
inline bool	isEmpty(int x, int y) { return isValid(x, y) && label(x, y) == Empty; }

static void dig(int x, int y) {			
	if (isValid(x, y) && mask(x, y) != Open) {
		mask(x, y) = Open;
		if (label(x, y) == 0) {
			dig(x - 1, y - 1);
			dig(x - 1, y);
			dig(x - 1, y + 1);
			dig(x, y - 1);
			dig(x, y + 1);
			dig(x + 1, y - 1);
			dig(x + 1, y);
			dig(x + 1, y + 1);
		}
	}
}
static void mark(int x, int y) {			
	if (isValid(x, y) && mask(x, y) == Hide)
		mask(x, y) = Flag;
}
static int getBombCount() {				
	int count = 0;
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++)
			if (mask(x, y) == Flag) count++;
	return count;
}
static void print() {					
	system("cls");
	printf("   발견:%2d   전체:%2d\n", getBombCount(), nBomb);
	printf("   ①②③④⑤⑥⑦⑧⑨\n");
	for (int y = 0; y < ny; y++) {
		printf("%2c ", 'A' + y);
		for (int x = 0; x < nx; x++) {
			if (mask(x, y) == Hide)	printf("□");		
			else if (mask(x, y) == Flag) printf("¤");	
			else {									
				if (isBomb(x, y)) printf("※");		
				else if (isEmpty(x, y)) printf("  ");	
				else printf("%2d", label(x, y));		
			}
		}
		printf("\n");
	}
}
static int countNbrBombs(int x, int y) {	
	int count = 0;
	for (int yy = y - 1; yy <= y + 1; yy++)
		for (int xx = x - 1; xx <= x + 1; xx++)
			if (isValid(xx, yy) && label(xx, yy) == Bomb)
				count++;
	return count;
}
static void init(int total = 9) {
	srand((unsigned int)time(NULL));
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++) {			
			mask(x, y) = Hide;
			label(x, y) = 0;
		}
	nBomb = total;
	for (int i = 0; i < nBomb; i++) {		
		int x, y;
		do {
			x = rand() % nx;
			y = rand() % ny;
		} while (label(x, y) != Empty);
		label(x, y) = Bomb;
	}
	for (int y = 0; y < ny; y++)			
		for (int x = 0; x < nx; x++)
			if (label(x, y) == Empty)
				label(x, y) = countNbrBombs(x, y);
}
static bool getPos(int& x, int& y) {		 
	printf("\n지뢰(P)행(A-I)열(1-9)\n      입력 --> ");
	bool isBomb = false;
	y = toupper(_getch()) - 'A';			
	if (y == 'P' - 'A') {
		isBomb = true;
		y = toupper(_getche()) - 'A';		
	}
	x = _getch() - '1';					
	return isBomb;
}
static int checkDone() {				
	int count = 0;
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++) {
			if (mask(x, y) != Open) count++;
			else if (isBomb(x, y)) return -1;
		}
	return (count == nBomb) ? 1 : 0;
}
void playMineSweeper(int total) {	
	int x, y, status;
	init(total);					
	do {
		print();
		bool isBomb = getPos(x, y);	
		if (isBomb) mark(x, y);		
		else		  dig(x, y);			
		status = checkDone();		
	} while (status == 0);			
	print();
	if (status < 0) 				
		printf("\n실패: 지뢰 폭발!!!\n\n");
	else	printf("\n성공: 탐색 성공!!!\n\n");
}