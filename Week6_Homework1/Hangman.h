#pragma once
#include <iostream>      // cout ���
#include <fstream>      // ���� �Է��� ���� ���
#include <string>      // string Ŭ���� ���
#include <conio.h>      // getch() ���
using namespace std;      // std �̸� ���� ���

class Hangman {
    string   progress[64];   // ��� ���� ���� ��� �׸�
    string   problem;      // ���� �ܾ�
    string   answer;      // ���� ���� ���� �ܾ�
    string   guessed;      // ��ü ���ĺ��� ������� ���� ��Ȳ
    int   nTries;      // ������� Ʋ�� Ƚ��
    const int maxTries = 7;   // �ִ� ��� �õ� Ƚ�� ����

    void load(const char* progName = "HangmanProgress.txt") {
        ifstream fs(progName);
        if (fs) {
            getline(fs, progress[0]);   // ù ��° ���� �ּ�
            for (int i = 0; i < 64; i++)
                getline(fs, progress[i]);
        }
    }
    void print() {
        system("cls");
        cout << "<Hangman Game>\n";
        for (int i = 0; i < 8; i++)
            cout << '\t' << progress[nTries * 8 + i] << endl;
        cout << "\n\t" << answer;
        cout << "\n\n " << guessed;
    }
    int countMatched(char ch) {
        int nMatched = 0;
        for (int pos = -1; ; ) {
            pos = problem.find(ch, pos + 1);
            if (pos < 0) break;
            answer[pos] = ch;   // ���� �ܾ ����(���� ���� ����)
            nMatched++;
        }
        return nMatched;
    }
    void guess() {
        char ch = _getch();
        if (ch >= 'a' && ch <= 'z') {
            int pos = guessed.find(ch);
            if (pos < 0) {         // ���� �������� ���� ����
                guessed[ch - 'a'] = ch;   // ������ ���� �ش� ��ġ ����
                if (countMatched(ch) == 0) nTries++; // ���� Ƚ�� ����
            }
        }
    }
public:
    void play(string prob) {
        load();
        problem = prob;
        answer = string(problem.length(), '-');   // ������ ���(7��)
        guessed = string(24, '.');         // ������ ���(7��)
        nTries = 0;
        while (nTries < maxTries && answer != problem) {
            print();
            guess();
        }
        print();
        cout << "\n\t" << ((nTries == maxTries) ? "����" : "����") << endl << endl;

        cout << "����: " << prob << endl;
    }
};