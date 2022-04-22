#include "MineSweeper.cpp"
void playMineSweeper(int width, int height, int total) {      // ���� ã�� �� �Լ�
    int x, y, status;
    init(width, height, total);               // ���� �ʰ� ����ũ �ʱ�ȭ
    do {
        print();
        bool isBomb = getPos(x, y);   // ��ġ �Է�
        if (isBomb) mark(x, y);      // ��� ��ġ�̸� ==> mark()ȣ��
        else        dig(x, y);         // �ƴϸ� ==> dig()ȣ��
        status = checkDone();      // ���� ���� ��Ȳ �˻�
    } while (status == 0);         // �������̸� �ݺ�
    print();
    if (status < 0)             // ����/���� ���
        printf("\n����: ���� ����!!!\n\n");
    else   printf("\n����: Ž�� ����!!!\n\n");
}

void main()
{
    int width, height, total;
    printf(" <Mine Sweeper>\n");
    printf(" ���ڸ��� ũ�� �Է�(���� ����) : ");
    scanf_s("%d%d", &width, &height);
    printf(" �ż��� �� ������ ���� �Է� : ");
    scanf_s("%d", &total);

    playMineSweeper(width, height, total);
}