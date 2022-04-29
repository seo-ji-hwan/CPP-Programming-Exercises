#include "Hangman.h"
#include "MyDic.h"
void main()
{
	Hangman   game;
	MyDic   dic;

	srand((unsigned int)time(NULL));
	dic.load("tmp.dic");
	int i = rand() % dic.count();
	game.play(dic.getEng(i), dic.getKor(i));
}