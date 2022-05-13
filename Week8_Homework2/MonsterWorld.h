#pragma once
#include "Canvas.h"
#include "Monster.h"
#include "Matrix.h"
#include <windows.h>
#define MAXMONS 8

class MonsterWorld {
	Matrix world;
	int xMax, yMax, nMon, nMove;
	Monster* pMon[MAXMONS];
	Canvas	canvas;

	int& Map(int x, int y) { return world.elem(x, y); }
	bool isDone() { return countItems() == 0 || nMon == 0; }
	int countItems() {
		int nItems = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) nItems++;
		return nItems;
	}
	void print() {
		canvas.clear();
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) canvas.draw(x, y, "��");
		for (int i = 0; i < nMon; i++)
			pMon[i]->draw(canvas);
		canvas.print("[ Monster World (�����Ǵ� ����) ]");

		cerr << " ��ü �̵� Ƚ�� = " << nMove << endl;
		cerr << " ���� ������ �� = " << countItems() << endl;
		for (int i = 0; i < nMon; i++)
			pMon[i]->print();

		cerr << " ��ü ������ �� : " << Monster::nMonster << endl;
	}
	void checkEnergy() {
		for (int i = 0; i < nMon; i++) {
			if (pMon[i]->getEnergy() == 0) {
				delete pMon[i];
				pMon[i] = pMon[nMon - 1];
				nMon--;
				cerr << "Monster �ϳ��� �����׽��ϴ�." << endl;
				//getchar();
			}
		}
	}

public:
	MonsterWorld(int w, int h) : world(h, w), canvas(w, h), xMax(w), yMax(h) {
		nMon = 0;
		nMove = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++) Map(x, y) = 1;
	}
	~MonsterWorld() {
		for (int i = 0; i < nMon; i++)
			delete pMon[i];
	}
	void add(Monster* m) {
		if (nMon < MAXMONS)
			pMon[nMon++] = m;
	}
	void play(int maxwalk, int wait) {
		print();
		cerr << " ���͸� ��������...";
		getchar();
		for (int i = 0; i < maxwalk; i++) {
			for (int k = 0; k < nMon; k++)
				pMon[k]->move(world.Data(), xMax, yMax);
			nMove++;
			print();
			checkEnergy();
			if (isDone()) break;
			Sleep(wait);
		}
	}
};