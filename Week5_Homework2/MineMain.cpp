#include "MineSweeper.cpp"
void playMineSweeper(int width, int height, int total) {      // 지뢰 찾기 주 함수
    int x, y, status;
    init(width, height, total);               // 지뢰 맵과 마스크 초기화
    do {
        print();
        bool isBomb = getPos(x, y);   // 위치 입력
        if (isBomb) mark(x, y);      // 깃발 위치이면 ==> mark()호출
        else        dig(x, y);         // 아니면 ==> dig()호출
        status = checkDone();      // 게임 종료 상황 검사
    } while (status == 0);         // 진행중이면 반복
    print();
    if (status < 0)             // 실패/성공 출력
        printf("\n실패: 지뢰 폭발!!!\n\n");
    else   printf("\n성공: 탐색 성공!!!\n\n");
}

void main()
{
    int width, height, total;
    printf(" <Mine Sweeper>\n");
    printf(" 지뢰맵의 크기 입력(가로 세로) : ");
    scanf_s("%d%d", &width, &height);
    printf(" 매설할 총 지뢰의 개수 입력 : ");
    scanf_s("%d", &total);

    playMineSweeper(width, height, total);
}