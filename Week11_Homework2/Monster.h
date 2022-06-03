#pragma once
#include "Canvas.h"
#include "Point.h"

class Monster {
public:
	string name, icon; 	// ���� �̸��� ȭ�� ��¿� ������
	int nItem;		// ���� ������ ��
	Point q, p;		// �߰�: ���� ��ġ(q)�� ���� ��ġ(p)
	int nSleep;		// �߰�: ����� �ϴ� Ƚ��
	double dist;		// �߰�: ���� �� ���� ������ �Ÿ�
	double total;		// �߰�: �� ������ �Ÿ�

	void clip(int maxx, int maxy) { p(maxx, maxy); }
	void eat(int** map) {
		if (map[p.y][p.x] == 1) {
			map[p.y][p.x] = 0;
			nItem++;
		}
		dist += (double)(p - q);
		total += (double)(p - q);
		q = p;
		if (dist > 20) {
			dist = 0;
			nSleep = 10;
		}
	}
	bool isSleep() {
		if (nSleep > 0) {
			nSleep--;
			return true;
		}
		else return false;
	}
public:
	Monster(string n = "������", string i = "��", int x = 0, int y = 0)
		: name(n), icon(i), nItem(0),
		p(x, y), q(x, y), nSleep(0), dist(0.0), total(0.0) {}
	virtual ~Monster() { cout << icon << nItem << "�Ÿ�:" << total << endl; }

	void draw(Canvas& canvas) { canvas.draw(p, icon); }
	virtual void move(int** map, int maxx, int maxy) {
		if (!isSleep()) {
			int num = rand() % 9 + 1;	// 1 ~ 9
			p =+ Point(num % 3 - 1, num / 3 - 1);
			clip(maxx, maxy);
			eat(map);
		}
	}
	void print() { cout << "\t" << name << icon << ":" << nItem << ":" << nSleep << endl; }
};