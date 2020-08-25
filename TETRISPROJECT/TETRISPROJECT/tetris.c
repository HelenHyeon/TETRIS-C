/*
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

#define L 75 //왼쪽
#define R 77 //오른쪽
#define U 72 //회전

int Background[20][20] = {
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}
};

int block[7][4][4][4] = {
    {{{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}}},
    {{{0,0,0,0},{0,0,0,0},{1,1,1,1},{0,0,0,0}},
     {{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}},
     {{0,0,0,0},{0,0,0,0},{1,1,1,1},{0,0,0,0}},
     {{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}}},
    {{{0,0,0,0},{1,1,0,0},{0,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,0,1,0},{0,1,1,0},{0,1,0,0}},
     {{0,0,0,0},{1,1,0,0},{0,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,0,1,0},{0,1,1,0},{0,1,0,0}}},
    {{{0,0,0,0},{0,1,1,0},{1,1,0,0},{0,0,0,0}},
     {{0,0,0,0},{1,0,0,0},{1,1,0,0},{0,1,0,0}},
     {{0,0,0,0},{0,1,1,0},{1,1,0,0},{0,0,0,0}},
     {{0,0,0,0},{1,0,0,0},{1,1,0,0},{0,1,0,0}}},
    {{{0,0,0,0},{0,0,1,0},{1,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{1,1,0,0},{0,1,0,0},{0,1,0,0}},
     {{0,0,0,0},{0,0,0,0},{1,1,1,0},{1,0,0,0}},
     {{0,0,0,0},{0,1,0,0},{0,1,0,0},{0,1,1,0}}},
    {{{0,0,0,0},{1,0,0,0},{1,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,1,0,0},{0,1,0,0},{1,1,0,0}},
     {{0,0,0,0},{0,0,0,0},{1,1,1,0},{0,0,1,0}},
     {{0,0,0,0},{0,1,1,0},{0,1,0,0},{0,1,0,0}}},
    {{{0,0,0,0},{0,1,0,0},{1,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,1,0,0},{0,1,1,0},{0,1,0,0}},
     {{0,0,0,0},{0,0,0,0},{1,1,1,0},{0,1,0,0}},
     {{0,0,0,0},{0,1,0,0},{1,1,0,0},{0,1,0,0}}}
}; //blocks[모양][회전상태][][]

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE; //커서숨기는 함수에 사용되는 열거형 
void setcursortype(CURSOR_TYPE c) { //커서숨기는 함수 
    CONSOLE_CURSOR_INFO CurInfo;

    switch (c) {
    case NOCURSOR:
        CurInfo.dwSize = 1;
        CurInfo.bVisible = FALSE;
        break;
    case SOLIDCURSOR:
        CurInfo.dwSize = 100;
        CurInfo.bVisible = TRUE;
        break;
    case NORMALCURSOR:
        CurInfo.dwSize = 20;
        CurInfo.bVisible = TRUE;
        break;
    }
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

int x = 7, y = 7;//임의로 좌표 지정
int type = 4; //임의로 모양 지정 (0 ~ 6)
int rota; //회전
int key; //키값

void move_block(int keynum) {
    int i, j;

    setcursortype(NOCURSOR);

    switch (keynum) {
    case L: //왼쪽
        for (i = 0; i < 4; i++) { //삭제
            for (j = 0; j < 4; j++) {
                if (block[type][rota][i][j] == 1) Background[y + i][x + j] = 0;
            }
        }
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (block[type][rota][i][j] == 1) Background[y + i][x + j - 1] = 1;
            }
        }
        x--; //이동
        break;
    case R:
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (block[type][rota][i][j] == 1) Background[y + i][x + j] = 0;
            }
        }
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (block[type][rota][i][j] == 1) Background[y + i][x + j + 1] = 1;
            }
        }
        x++;
        break;
    case U: //위쪽 
        for (i = 0; i < 4; i++) { //삭제  
            for (j = 0; j < 4; j++) {
                if (block[type][rota][i][j] == 1) Background[y + i][x + j] = 0;
            }
        }
        rota = (rota + 1) % 4; //회전값을 1증가
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (block[type][rota][i][j] == 1) Background[y + i][x + j] = 1;
            }
        }
        break;
    }
}

int main() {
    while (1) {
        system("cls");
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                switch (Background[i][j])
                {
                case 1:
                    printf("■");
                    break;
                case 3:
                    printf("▩");
                    break;
                default:
                    printf("  ");
                    break;
                }
            }
            printf("\n");
        }
        if (kbhit()) {
            key = getch();
            if (key == 224) { //방향키
                do { key = getch(); } while (key == 224);//방향키지시값 버림 
                switch (key) {
                case L: //왼쪽키 눌렀을때  
                    move_block(L);
                    break;
                case R: //오른쪽 방향키 눌렀을때
                    move_block(R);
                    break;
                case U: //위쪽 방향키 눌렀을때 
                    move_block(U);
                    break;
                default:
                    break;
                }
            }
        }

    }
}
*/

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

void reset(); //게임판 초기화 
void reset_main(); //메인 게임판
void reset_main_cpy(); //copy 게임판
void draw_map(); //게임 상태 표시 
void draw_main(); //게임판을 그림 
void new_block(); //새로운 블록을 하나 만듦 
void keep_block(); //블록 하나를 킵함
void check_key(); //키보드로 키를 입력받음 
void drop_block(); //블록을 아래로 떨어트림 
int check_crush(int bx, int by, int rotation); //bx, by위치에 rotation회전값을 같는 경우 충돌 판단 
void move_block(int dir); //dir방향으로 블록을 움직임 
void check_line(); //줄 터뜨림
void check_game_over(); //게임오버

enum {
#define LEFT 75 // 왼쪽 키
#define RIGHT 77 // 오른쪽 키
#define UP 72 // 회전 키
#define DOWN 80 // soft drop
#define SPACE 32 // hard drop
#define c 99 // 킵
#define C 67
#define ESC 27 //게임종료 
#define false 0
#define true 1
#define ACTIVE_BLOCK -2 // 움직이는 블록
#define CEILLING -1 // 천장 
#define EMPTY 0 // 블록이 이동할 수 없는 공간은 양수로 표현 
#define WALL 1 //벽
#define INACTIVE_BLOCK 2 // 이동완료 블록
#define XSIZE 13 // 가로크기 (벽2 포함)
#define YSIZE 21 // 세로크기 (벽1 포함)
#define MAIN_X_ADJ 1 // 게임판 왼쪽 공백
#define MAIN_Y_ADJ 1 // 게임판 위쪽 공백
#define STATUS_X_ADJ MAIN_X_ADJ + XSIZE + 1 //우측 게임정보 = 게임판 왼쪽 공백 + 게임판 사이즈 + 1
};

int STATUS_Y_GOAL; //GOAL 정보표시위치Y 좌표 저장
int STATUS_Y_SCORE; //SCORE 정보표시위치Y 좌표 저장

int blocks[7][4][4][4] = {
    {{{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}}},
    {{{0,0,0,0},{0,0,0,0},{1,1,1,1},{0,0,0,0}},
     {{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}},
     {{0,0,0,0},{0,0,0,0},{1,1,1,1},{0,0,0,0}},
     {{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}}},
    {{{0,0,0,0},{1,1,0,0},{0,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,0,1,0},{0,1,1,0},{0,1,0,0}},
     {{0,0,0,0},{1,1,0,0},{0,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,0,1,0},{0,1,1,0},{0,1,0,0}}},
    {{{0,0,0,0},{0,1,1,0},{1,1,0,0},{0,0,0,0}},
     {{0,0,0,0},{1,0,0,0},{1,1,0,0},{0,1,0,0}},
     {{0,0,0,0},{0,1,1,0},{1,1,0,0},{0,0,0,0}},
     {{0,0,0,0},{1,0,0,0},{1,1,0,0},{0,1,0,0}}},
    {{{0,0,0,0},{0,0,1,0},{1,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{1,1,0,0},{0,1,0,0},{0,1,0,0}},
     {{0,0,0,0},{0,0,0,0},{1,1,1,0},{1,0,0,0}},
     {{0,0,0,0},{0,1,0,0},{0,1,0,0},{0,1,1,0}}},
    {{{0,0,0,0},{1,0,0,0},{1,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,1,0,0},{0,1,0,0},{1,1,0,0}},
     {{0,0,0,0},{0,0,0,0},{1,1,1,0},{0,0,1,0}},
     {{0,0,0,0},{0,1,1,0},{0,1,0,0},{0,1,0,0}}},
    {{{0,0,0,0},{0,1,0,0},{1,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,1,0,0},{0,1,1,0},{0,1,0,0}},
     {{0,0,0,0},{0,0,0,0},{1,1,1,0},{0,1,0,0}},
     {{0,0,0,0},{0,1,0,0},{1,1,0,0},{0,1,0,0}}}
};

int type; //블록 종류를 저장 
int rotation; //블록 회전값 저장 
int next_type; //다음 블록값 저장
int keep_type; //킵한 블록값 저장

int main_org[YSIZE][XSIZE]; // 게임판 정보 저장 후 main_cpy로 복사 
int main_cpy[YSIZE][XSIZE]; // main_cpy와 배열을 비교해서 달라진 곳 수정
int bx, by; // 블록 좌표
int key; // 키값 저장 
int speed = 10; //게임진행속도 
int cnt; // 제거한 줄 수
int score; // 현재 점수 
int last_score = 0; //마지막게임점수 
int best_score = 0; //최고게임점수
int keep_max;

int new_block_type = 0; // new block 필요 여부
int crush_on = 0; // 이동 블록의 충돌 여부
int space_key_on = 0; // hard drop 상태

void gotoxy(int x, int y) { //구글링으로 열심히 찾은 커서 이동하는 함수
    COORD pos = { 2 * x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //커서 이동하는거
}

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE; //커서숨기는 함수에 사용되는 열거형 (이부분은 구글 도움 받아서 아직 공부중...)
void setcursortype(CURSOR_TYPE cc) { //커서숨기는 함수 
    CONSOLE_CURSOR_INFO CurInfo;

    switch (cc) {
    case NOCURSOR:
        CurInfo.dwSize = 1;
        CurInfo.bVisible = FALSE;
        break;
    case SOLIDCURSOR:
        CurInfo.dwSize = 100;
        CurInfo.bVisible = TRUE;
        break;
    case NORMALCURSOR:
        CurInfo.dwSize = 20;
        CurInfo.bVisible = TRUE;
        break;
    }
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

int main() {
    int i;

    srand((unsigned)time(NULL)); //난수표생성 
    setcursortype(NOCURSOR); //커서 없앰
    reset(); //게임판 리셋 

    while (1) {
        for (i = 0; i < 5; i++) { // 블록이 한칸떨어지는동안 5번 키입력받을 수 있음 
            check_key(); //키입력확인 
            draw_main(); //화면을 그림 
            Sleep(speed); //게임속도조절 
            if (crush_on && check_crush(bx, by + 1, rotation) == false) Sleep(100);
            //블록이 충돌중인경우 추가로 이동및 회전할 시간을 갖음 
            if (space_key_on == 1) { //스페이스바를 누른경우(hard drop) 추가로 이동및 회전할수 없음 break; 
                space_key_on = 0;
                break;
            }
        }
        drop_block(); // 블록을 한칸 내림 
        check_game_over(); //게임오버를 체크 
        if (new_block_type == 1) {
            new_block();
            keep_max = 0; // 킵 한 블록을 바꿀수 있는지 여부 초기화
        }
    }
}

void reset() {

    FILE* file = fopen("score.dat", "rt");
    if (file == 0) { best_score = 0; }
        fscanf(file, "%d", &best_score); // 파일이 열리면 최고점수를 불러옴 
    fclose(file); //파일 닫음 

    score = 0;
    key = 0;
    crush_on = 0;
    speed = 100;

    system("cls"); //화면지움 
    reset_main(); // main_org를 초기화 
    draw_map(); // 게임 상태 표시
    draw_main(); // 게임판을 그림 

    next_type = rand() % 7; // next block 랜덤하게 설정
    new_block(); //새로운 블록을 하나 만듦  

}

void reset_main() { // 게임판을 그림 
    int i, j;

    for (i = 0; i < YSIZE; i++) { // 게임판을 0으로 초기화  
        for (j = 0; j < XSIZE; j++) {
            main_org[i][j] = 0;
            main_cpy[i][j] = 100; // 게임판에 사용되지 않는 수
        }
    }
    for (j = 1; j < XSIZE; j++) { //y값이 3인 위치에 천장을 만듦 
        main_org[3][j] = CEILLING;
    }
    for (i = 1; i < YSIZE - 1; i++) { //좌우 벽을 만듦   
        main_org[i][0] = WALL;
        main_org[i][XSIZE - 1] = WALL;
    }
    for (j = 0; j < XSIZE; j++) { //바닥벽을 만듦 
        main_org[YSIZE - 1][j] = WALL;
    }
}

void reset_main_cpy() { // main_cpy를 초기화 
    int i, j;

    for (i = 0; i < YSIZE; i++) { 
        for (j = 0; j < XSIZE; j++) {
            main_cpy[i][j] = 100; // 게임판에 사용되지 않는 수
        }
    }
}

void draw_map() { // 게임 상태 표시
    int y = 3;
    gotoxy(STATUS_X_ADJ, STATUS_Y_GOAL = y); printf(" GOAL  : %5d", cnt); //GOAL 위치 저장 후 넘김
    gotoxy(STATUS_X_ADJ, y + 1); printf("+-  N E X T  -+ ");
    gotoxy(STATUS_X_ADJ, y + 2); printf("|             | ");
    gotoxy(STATUS_X_ADJ, y + 3); printf("|             | ");
    gotoxy(STATUS_X_ADJ, y + 4); printf("|             | ");
    gotoxy(STATUS_X_ADJ, y + 5); printf("|             | ");
    gotoxy(STATUS_X_ADJ, y + 6); printf("+-- -- - -- --+ ");
    gotoxy(STATUS_X_ADJ, y + 7); printf(" YOUR SCORE :");
    gotoxy(STATUS_X_ADJ, STATUS_Y_SCORE = y + 8); printf("        %6d", score); //SCORE 위치 저장 후 넘김
    gotoxy(STATUS_X_ADJ, y + 9); printf(" LAST SCORE :");
    gotoxy(STATUS_X_ADJ, y + 10); printf("        %6d", last_score);
    gotoxy(STATUS_X_ADJ, y + 11); printf(" BEST SCORE :");
    gotoxy(STATUS_X_ADJ, y + 12); printf("        %6d", best_score);
    gotoxy(STATUS_X_ADJ, y + 13); printf("+-  K E E P  -+ ");
    gotoxy(STATUS_X_ADJ, y + 14); printf("|             | ");
    gotoxy(STATUS_X_ADJ, y + 15); printf("|             | ");
    gotoxy(STATUS_X_ADJ, y + 16); printf("|             | ");
    gotoxy(STATUS_X_ADJ, y + 17); printf("|             | ");
    gotoxy(STATUS_X_ADJ, y + 18); printf("+-- -- - -- --+ ");
}

void draw_main() { // 게임판 그리는 함수 
    int i, j;

    for (j = 1; j < XSIZE - 1; j++) { //천장은 계속 새로운블럭이 지나가서 지워지면 새로 그려줌 
        if (main_org[3][j] == EMPTY) main_org[3][j] = CEILLING;
    }
    for (i = 0; i < YSIZE; i++) {
        for (j = 0; j < XSIZE; j++) {
            if (main_cpy[i][j] != main_org[i][j]) { // cpy랑 비교 후 게임판 수정
                gotoxy(MAIN_X_ADJ + j, MAIN_Y_ADJ + i);
                switch (main_org[i][j]) {
                case EMPTY: // 빈칸
                    printf("  ");
                    break;
                case CEILLING: // 천장
                    printf(". ");
                    break;
                case WALL: // 벽
                    printf("▩");
                    break;
                case INACTIVE_BLOCK: // 고정 블록
                    printf("□");
                    break;
                case ACTIVE_BLOCK: // 움직이는 블록
                    printf("■");
                    break;
                }
            }
        }
    }
    for (i = 0; i < YSIZE; i++) { // main_cpy에 저장
        for (j = 0; j < XSIZE; j++) {
            main_cpy[i][j] = main_org[i][j];
        }
    }
}

void new_block() { //새로운 블록 생성  
    int i, j;

    bx = (XSIZE / 2) - 1; //블록 생성 위치x좌표(게임판의 가운데) 
    by = 0;  //블록 생성위치 y좌표(제일 위) 
    type = next_type; //다음블럭값을 가져옴 
    next_type = rand() % 7; //다음 블럭을 만듦 
    rotation = 0;  //회전은 0번으로 가져옴 

    new_block_type = 0; //new_block flag를 끔  

    for (i = 0; i < 4; i++) { //게임판 bx, by위치에 블럭생성  
        for (j = 0; j < 4; j++) {
            if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j] = ACTIVE_BLOCK;
        }
    }
    for (i = 1; i < 3; i++) { //게임상태표시에 다음에 나올블럭을 그림 
        for (j = 0; j < 4; j++) {
            if (blocks[next_type][0][i][j] == 1) {
                gotoxy(STATUS_X_ADJ + 2 + j, i + 5);
                printf("■");
            }
            else {
                gotoxy(STATUS_X_ADJ + 2 + j, i + 5);
                printf("  ");
            }
        }
    }
}

void keep_block() { //블록 킵하기 
    int i, j, t;

    keep_max = 1;

    while (1) {
        if (keep_type == 7) {
            keep_type = type;
            for (i = 0; i < 4; i++) { //게임판 bx, by위치에 블럭생성  
                for (j = 0; j < 4; j++) {
                    if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
                }
            }
            for (i = 1; i < 3; i++) { //게임상태표시에 다음에 나올블럭을 그림 
                for (j = 0; j < 4; j++) {
                    if (blocks[keep_type][0][i][j] == 1) {
                        gotoxy(STATUS_X_ADJ + 2 + j, i + 17);
                        printf("■");
                    }
                    else {
                        gotoxy(STATUS_X_ADJ + 2 + j, i + 17);
                        printf("  ");
                    }
                }
            }
            new_block();
            break;
        }

        for (i = 0; i < 4; i++) { //게임판 bx, by위치에 블럭생성  
            for (j = 0; j < 4; j++) {
                if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
            }
        }

        bx = (XSIZE / 2) - 1; //블록 생성 위치x좌표(게임판의 가운데) 
        by = 0;  //블록 생성위치 y좌표(제일 위) 
        t = type;
        type = keep_type;
        keep_type = t;
        rotation = 0;

        for (i = 0; i < 4; i++) { //게임판 bx, by위치에 블럭생성  
            for (j = 0; j < 4; j++) {
                if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j] = ACTIVE_BLOCK;
            }
        }
        for (i = 1; i < 3; i++) { //게임상태표시에 다음에 나올블럭을 그림 
            for (j = 0; j < 4; j++) {
                if (blocks[keep_type][0][i][j] == 1) {
                    gotoxy(STATUS_X_ADJ + 2 + j, i + 17);
                    printf("■");
                }
                else {
                    gotoxy(STATUS_X_ADJ + 2 + j, i + 17);
                    printf("  ");
                }
            }
        }
        break;
    }
}

void check_key() {
    key = 0; //키값 초기화  

    if (kbhit()) { //키입력이 있는 경우  
        key = getch(); //키값을 받음
        if (key == 224) { //방향키인경우 
            do { key = getch(); } while (key == 224);// 방향키지시값 제거 
            switch (key) {
            case LEFT: //왼쪽키 눌렀을때  
                if (check_crush(bx - 1, by, rotation) == true) move_block(LEFT);
                break;                            //왼쪽으로 갈 수 있는지 체크 후 가능하면 이동
            case RIGHT: //오른쪽 방향키 눌렀을때- 위와 동일하게 처리됨 
                if (check_crush(bx + 1, by, rotation) == true) move_block(RIGHT);
                break;
            case DOWN: //아래쪽 방향키 눌렀을때-위와 동일하게 처리됨 
                if (check_crush(bx, by + 1, rotation) == true) move_block(DOWN);
                break;
            case UP: //위쪽 방향키 눌렀을때 
                if (check_crush(bx, by, (rotation + 1) % 4) == true) move_block(UP);
                //회전 여부 체크 후 가능하면 회전
                else if (crush_on == 1 && check_crush(bx, by - 1, (rotation + 1) % 4) == true) move_block(100); // 바닥에 닿은 경우 한칸 위에서 회전
            }
        }
        else {
            switch (key) {
            case SPACE: //스페이스키 눌렀을때 
                space_key_on = 1; //스페이스키 flag를 띄움 
                while (crush_on == 0) { //바닥에 닿을때까지 이동시킴 
                    drop_block();
                    score += 3; // hard drop 보너스
                    gotoxy(STATUS_X_ADJ, STATUS_Y_SCORE); printf("        %6d", score); //점수 표시  
                }
                // 이부분에 음향효과 추가 예정
                break;
            case C:
            case c:
                if(keep_max==0) keep_block();
                break;
            case ESC: //ESC눌렀을때 
                system("cls"); //화면을 지우고 
                exit(0); //게임종료 
            }
        }
    }
    while (kbhit()) getch(); //키버퍼를 비움 
}

void drop_block() {
    int i, j;

    if (crush_on && check_crush(bx, by + 1, rotation) == true) crush_on = 0; //밑이 비어있으면 crush flag 끔 
    if (crush_on && check_crush(bx, by + 1, rotation) == false) { //밑이 비어있지않고 crush flag가 켜저있으면 
        for (i = 0; i < YSIZE; i++) { //현재 조작중인 블럭을 굳힘 
            for (j = 0; j < XSIZE; j++) {
                if (main_org[i][j] == ACTIVE_BLOCK) main_org[i][j] = INACTIVE_BLOCK;
            }
        }
        crush_on = 0; //flag를 끔 
        check_line(); //라인체크를 함 
        new_block_type = 1; //새로운 블럭생성 flag를 켬    
        return; //함수 종료 
    }
    if (check_crush(bx, by + 1, rotation) == true) move_block(DOWN); //밑이 비어있으면 밑으로 한칸 이동 
    if (check_crush(bx, by + 1, rotation) == false) crush_on++; //밑으로 이동이 안되면  crush flag를 켬
}

int check_crush(int bx, int by, int b_rotation) { //지정된 좌표와 회전값으로 충돌이 있는지 검사 
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) { //지정된 위치의 게임판과 블럭모양을 비교해서 겹치면 false를 리턴 
            if (blocks[type][b_rotation][i][j] == 1 && main_org[by + i][bx + j] > 0) return false;
        }
    }
    return true; //하나도 안겹치면 true리턴 
};

void move_block(int dir) { //블록을 이동시킴 
    int i, j;

    switch (dir) {
    case LEFT: //왼쪽방향 
        for (i = 0; i < 4; i++) { //현재좌표의 블럭을 지움 
            for (j = 0; j < 4; j++) {
                if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
            }
        }
        for (i = 0; i < 4; i++) { //왼쪽으로 한칸가서 active block을 찍음 
            for (j = 0; j < 4; j++) {
                if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j - 1] = ACTIVE_BLOCK;
            }
        }
        bx--; //좌표값 이동 
        break;

    case RIGHT:    //오른쪽 방향. 왼쪽방향이랑 같은 원리로 동작 
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
            }
        }
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j + 1] = ACTIVE_BLOCK;
            }
        }
        bx++;
        break;

    case DOWN:    //아래쪽 방향. 왼쪽방향이랑 같은 원리로 동작
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
            }
        }
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (blocks[type][rotation][i][j] == 1) main_org[by + i + 1][bx + j] = ACTIVE_BLOCK;
            }
        }
        by++;
        break;

    case UP: //키보드 위쪽 눌렀을때 회전시킴. 
        for (i = 0; i < 4; i++) { //현재좌표의 블럭을 지움  
            for (j = 0; j < 4; j++) {
                if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
            }
        }
        rotation = (rotation + 1) % 4; //회전값을 1증가시킴(3에서 4가 되는 경우는 0으로 되돌림) 
        for (i = 0; i < 4; i++) { //회전된 블록을 찍음 
            for (j = 0; j < 4; j++) {
                if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j] = ACTIVE_BLOCK;
            }
        }
        break;

    case 100: //블록이 바닥, 혹은 다른 블록과 닿은 상태에서 한칸위로 올려 회전이 가능한 경우 
              //이를 동작시키는 특수동작 
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
            }
        }
        rotation = (rotation + 1) % 4;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (blocks[type][rotation][i][j] == 1) main_org[by + i - 1][bx + j] = ACTIVE_BLOCK;
            }
        }
        by--;
        break;
    }
}

void check_line() {
    int i, j, k, l;

    int    block_amount; //한줄의 블록갯수를 저장하는 변수 
    int combo = 0; //콤보갯수 저장하는 변수 지정및 초기화 

    for (i = YSIZE - 2; i > 3;) { //i=MAIN_Y-2 : 밑쪽벽의 윗칸부터,  i>3 : 천장(3)아래까지 검사 
        block_amount = 0; //블록갯수 저장 변수 초기화 
        for (j = 1; j < XSIZE - 1; j++) { //벽과 벽사이의 블록갯수를 셈 
            if (main_org[i][j] > 0) block_amount++;
        }
        if (block_amount == XSIZE - 2) { //블록이 가득 찬 경우
            cnt++; //지운 줄 갯수 카운트 증가 
            combo++; //콤보수 증가
            for (l = 1; l < XSIZE - 1; l++) { //윗줄을 한칸씩 모두 내림(윗줄이 천장이 아닌 경우에만) 
                for (k = i; k > 1; k--) {
                    if (main_org[k - 1][l] != CEILLING) main_org[k][l] = main_org[k - 1][l]; //한 칸 내려줌
                    if (main_org[k - 1][l] == CEILLING) main_org[k][l] = EMPTY; //천장 밑에 빈칸을 넣어줌
                }
            }
        }
        else i--;
    }
    score += 100; //점수추가 
    if (combo) { //줄 삭제가 있는 경우 점수와 레벨 목표를 새로 표시함  
        if (combo > 1) { //2콤보이상인 경우 경우 보너스및 메세지를 게임판에 띄웠다가 지움 
            gotoxy(MAIN_X_ADJ + (XSIZE / 2) - 1, MAIN_Y_ADJ + by - 1); printf("%d COMBO!", combo);
            Sleep(500);
            score += (combo * 100);
            reset_main_cpy(); //텍스트를 지우기 위해 main_cpy을 초기화.
        }
        gotoxy(STATUS_X_ADJ, STATUS_Y_GOAL); printf(" GOAL  : %5d", cnt);
        gotoxy(STATUS_X_ADJ, STATUS_Y_SCORE); printf("        %6d", score);
    }
}

void check_game_over() {
    int i;

    int x = 5;
    int y = 5;

    for (i = 1; i < XSIZE - 2; i++) {
        if (main_org[3][i] > 0) { //천장(위에서 세번째 줄)에 inactive가 생성되면 게임 오버 
            gotoxy(x, y + 0); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤"); //게임오버 메세지 
            gotoxy(x, y + 1); printf("▤                              ▤");
            gotoxy(x, y + 2); printf("▤  +-----------------------+   ▤");
            gotoxy(x, y + 3); printf("▤  |  G A M E  O V E R..   |   ▤");
            gotoxy(x, y + 4); printf("▤  +-----------------------+   ▤");
            gotoxy(x, y + 5); printf("▤   YOUR SCORE: %6d         ▤", score);
            gotoxy(x, y + 6); printf("▤                              ▤");
            gotoxy(x, y + 7); printf("▤  Press any key to restart..  ▤");
            gotoxy(x, y + 8); printf("▤                              ▤");
            gotoxy(x, y + 9); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
            last_score = score; //게임점수를 옮김 

            if (score > best_score) { //최고기록 갱신시 
                FILE* file = fopen("score.dat", "wt"); //score.dat에 점수 저장                

                gotoxy(x, y + 6); printf("▤  ★★★ BEST SCORE! ★★★   ▤  ");

                if (file == 0) { //파일 에러메세지  
                    gotoxy(0, 0);
                    printf("FILE ERROR: SYSTEM CANNOT WRITE BEST SCORE ON \"SCORE.DAT\"");
                }
                else {
                    fprintf(file, "%d", score);
                    fclose(file);
                }
            }
            Sleep(1000);
            while (kbhit()) getch();
            key = getch();
            reset();
        }
    }
}