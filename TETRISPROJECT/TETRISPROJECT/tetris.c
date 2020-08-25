/*
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

#define L 75 //����
#define R 77 //������
#define U 72 //ȸ��

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
}; //blocks[���][ȸ������][][]

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE; //Ŀ������� �Լ��� ���Ǵ� ������ 
void setcursortype(CURSOR_TYPE c) { //Ŀ������� �Լ� 
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

int x = 7, y = 7;//���Ƿ� ��ǥ ����
int type = 4; //���Ƿ� ��� ���� (0 ~ 6)
int rota; //ȸ��
int key; //Ű��

void move_block(int keynum) {
    int i, j;

    setcursortype(NOCURSOR);

    switch (keynum) {
    case L: //����
        for (i = 0; i < 4; i++) { //����
            for (j = 0; j < 4; j++) {
                if (block[type][rota][i][j] == 1) Background[y + i][x + j] = 0;
            }
        }
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (block[type][rota][i][j] == 1) Background[y + i][x + j - 1] = 1;
            }
        }
        x--; //�̵�
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
    case U: //���� 
        for (i = 0; i < 4; i++) { //����  
            for (j = 0; j < 4; j++) {
                if (block[type][rota][i][j] == 1) Background[y + i][x + j] = 0;
            }
        }
        rota = (rota + 1) % 4; //ȸ������ 1����
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
                    printf("��");
                    break;
                case 3:
                    printf("��");
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
            if (key == 224) { //����Ű
                do { key = getch(); } while (key == 224);//����Ű���ð� ���� 
                switch (key) {
                case L: //����Ű ��������  
                    move_block(L);
                    break;
                case R: //������ ����Ű ��������
                    move_block(R);
                    break;
                case U: //���� ����Ű �������� 
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

void reset(); //������ �ʱ�ȭ 
void reset_main(); //���� ������
void reset_main_cpy(); //copy ������
void draw_map(); //���� ���� ǥ�� 
void draw_main(); //�������� �׸� 
void new_block(); //���ο� ����� �ϳ� ���� 
void keep_block(); //��� �ϳ��� ŵ��
void check_key(); //Ű����� Ű�� �Է¹��� 
void drop_block(); //����� �Ʒ��� ����Ʈ�� 
int check_crush(int bx, int by, int rotation); //bx, by��ġ�� rotationȸ������ ���� ��� �浹 �Ǵ� 
void move_block(int dir); //dir�������� ����� ������ 
void check_line(); //�� �Ͷ߸�
void check_game_over(); //���ӿ���

enum {
#define LEFT 75 // ���� Ű
#define RIGHT 77 // ������ Ű
#define UP 72 // ȸ�� Ű
#define DOWN 80 // soft drop
#define SPACE 32 // hard drop
#define c 99 // ŵ
#define C 67
#define ESC 27 //�������� 
#define false 0
#define true 1
#define ACTIVE_BLOCK -2 // �����̴� ���
#define CEILLING -1 // õ�� 
#define EMPTY 0 // ����� �̵��� �� ���� ������ ����� ǥ�� 
#define WALL 1 //��
#define INACTIVE_BLOCK 2 // �̵��Ϸ� ���
#define XSIZE 13 // ����ũ�� (��2 ����)
#define YSIZE 21 // ����ũ�� (��1 ����)
#define MAIN_X_ADJ 1 // ������ ���� ����
#define MAIN_Y_ADJ 1 // ������ ���� ����
#define STATUS_X_ADJ MAIN_X_ADJ + XSIZE + 1 //���� �������� = ������ ���� ���� + ������ ������ + 1
};

int STATUS_Y_GOAL; //GOAL ����ǥ����ġY ��ǥ ����
int STATUS_Y_SCORE; //SCORE ����ǥ����ġY ��ǥ ����

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

int type; //��� ������ ���� 
int rotation; //��� ȸ���� ���� 
int next_type; //���� ��ϰ� ����
int keep_type; //ŵ�� ��ϰ� ����

int main_org[YSIZE][XSIZE]; // ������ ���� ���� �� main_cpy�� ���� 
int main_cpy[YSIZE][XSIZE]; // main_cpy�� �迭�� ���ؼ� �޶��� �� ����
int bx, by; // ��� ��ǥ
int key; // Ű�� ���� 
int speed = 10; //��������ӵ� 
int cnt; // ������ �� ��
int score; // ���� ���� 
int last_score = 0; //�������������� 
int best_score = 0; //�ְ��������
int keep_max;

int new_block_type = 0; // new block �ʿ� ����
int crush_on = 0; // �̵� ����� �浹 ����
int space_key_on = 0; // hard drop ����

void gotoxy(int x, int y) { //���۸����� ������ ã�� Ŀ�� �̵��ϴ� �Լ�
    COORD pos = { 2 * x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //Ŀ�� �̵��ϴ°�
}

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE; //Ŀ������� �Լ��� ���Ǵ� ������ (�̺κ��� ���� ���� �޾Ƽ� ���� ������...)
void setcursortype(CURSOR_TYPE cc) { //Ŀ������� �Լ� 
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

    srand((unsigned)time(NULL)); //����ǥ���� 
    setcursortype(NOCURSOR); //Ŀ�� ����
    reset(); //������ ���� 

    while (1) {
        for (i = 0; i < 5; i++) { // ����� ��ĭ�������µ��� 5�� Ű�Է¹��� �� ���� 
            check_key(); //Ű�Է�Ȯ�� 
            draw_main(); //ȭ���� �׸� 
            Sleep(speed); //���Ӽӵ����� 
            if (crush_on && check_crush(bx, by + 1, rotation) == false) Sleep(100);
            //����� �浹���ΰ�� �߰��� �̵��� ȸ���� �ð��� ���� 
            if (space_key_on == 1) { //�����̽��ٸ� �������(hard drop) �߰��� �̵��� ȸ���Ҽ� ���� break; 
                space_key_on = 0;
                break;
            }
        }
        drop_block(); // ����� ��ĭ ���� 
        check_game_over(); //���ӿ����� üũ 
        if (new_block_type == 1) {
            new_block();
            keep_max = 0; // ŵ �� ����� �ٲܼ� �ִ��� ���� �ʱ�ȭ
        }
    }
}

void reset() {

    FILE* file = fopen("score.dat", "rt");
    if (file == 0) { best_score = 0; }
        fscanf(file, "%d", &best_score); // ������ ������ �ְ������� �ҷ��� 
    fclose(file); //���� ���� 

    score = 0;
    key = 0;
    crush_on = 0;
    speed = 100;

    system("cls"); //ȭ������ 
    reset_main(); // main_org�� �ʱ�ȭ 
    draw_map(); // ���� ���� ǥ��
    draw_main(); // �������� �׸� 

    next_type = rand() % 7; // next block �����ϰ� ����
    new_block(); //���ο� ����� �ϳ� ����  

}

void reset_main() { // �������� �׸� 
    int i, j;

    for (i = 0; i < YSIZE; i++) { // �������� 0���� �ʱ�ȭ  
        for (j = 0; j < XSIZE; j++) {
            main_org[i][j] = 0;
            main_cpy[i][j] = 100; // �����ǿ� ������ �ʴ� ��
        }
    }
    for (j = 1; j < XSIZE; j++) { //y���� 3�� ��ġ�� õ���� ���� 
        main_org[3][j] = CEILLING;
    }
    for (i = 1; i < YSIZE - 1; i++) { //�¿� ���� ����   
        main_org[i][0] = WALL;
        main_org[i][XSIZE - 1] = WALL;
    }
    for (j = 0; j < XSIZE; j++) { //�ٴں��� ���� 
        main_org[YSIZE - 1][j] = WALL;
    }
}

void reset_main_cpy() { // main_cpy�� �ʱ�ȭ 
    int i, j;

    for (i = 0; i < YSIZE; i++) { 
        for (j = 0; j < XSIZE; j++) {
            main_cpy[i][j] = 100; // �����ǿ� ������ �ʴ� ��
        }
    }
}

void draw_map() { // ���� ���� ǥ��
    int y = 3;
    gotoxy(STATUS_X_ADJ, STATUS_Y_GOAL = y); printf(" GOAL  : %5d", cnt); //GOAL ��ġ ���� �� �ѱ�
    gotoxy(STATUS_X_ADJ, y + 1); printf("+-  N E X T  -+ ");
    gotoxy(STATUS_X_ADJ, y + 2); printf("|             | ");
    gotoxy(STATUS_X_ADJ, y + 3); printf("|             | ");
    gotoxy(STATUS_X_ADJ, y + 4); printf("|             | ");
    gotoxy(STATUS_X_ADJ, y + 5); printf("|             | ");
    gotoxy(STATUS_X_ADJ, y + 6); printf("+-- -- - -- --+ ");
    gotoxy(STATUS_X_ADJ, y + 7); printf(" YOUR SCORE :");
    gotoxy(STATUS_X_ADJ, STATUS_Y_SCORE = y + 8); printf("        %6d", score); //SCORE ��ġ ���� �� �ѱ�
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

void draw_main() { // ������ �׸��� �Լ� 
    int i, j;

    for (j = 1; j < XSIZE - 1; j++) { //õ���� ��� ���ο���� �������� �������� ���� �׷��� 
        if (main_org[3][j] == EMPTY) main_org[3][j] = CEILLING;
    }
    for (i = 0; i < YSIZE; i++) {
        for (j = 0; j < XSIZE; j++) {
            if (main_cpy[i][j] != main_org[i][j]) { // cpy�� �� �� ������ ����
                gotoxy(MAIN_X_ADJ + j, MAIN_Y_ADJ + i);
                switch (main_org[i][j]) {
                case EMPTY: // ��ĭ
                    printf("  ");
                    break;
                case CEILLING: // õ��
                    printf(". ");
                    break;
                case WALL: // ��
                    printf("��");
                    break;
                case INACTIVE_BLOCK: // ���� ���
                    printf("��");
                    break;
                case ACTIVE_BLOCK: // �����̴� ���
                    printf("��");
                    break;
                }
            }
        }
    }
    for (i = 0; i < YSIZE; i++) { // main_cpy�� ����
        for (j = 0; j < XSIZE; j++) {
            main_cpy[i][j] = main_org[i][j];
        }
    }
}

void new_block() { //���ο� ��� ����  
    int i, j;

    bx = (XSIZE / 2) - 1; //��� ���� ��ġx��ǥ(�������� ���) 
    by = 0;  //��� ������ġ y��ǥ(���� ��) 
    type = next_type; //���������� ������ 
    next_type = rand() % 7; //���� ���� ���� 
    rotation = 0;  //ȸ���� 0������ ������ 

    new_block_type = 0; //new_block flag�� ��  

    for (i = 0; i < 4; i++) { //������ bx, by��ġ�� ������  
        for (j = 0; j < 4; j++) {
            if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j] = ACTIVE_BLOCK;
        }
    }
    for (i = 1; i < 3; i++) { //���ӻ���ǥ�ÿ� ������ ���ú��� �׸� 
        for (j = 0; j < 4; j++) {
            if (blocks[next_type][0][i][j] == 1) {
                gotoxy(STATUS_X_ADJ + 2 + j, i + 5);
                printf("��");
            }
            else {
                gotoxy(STATUS_X_ADJ + 2 + j, i + 5);
                printf("  ");
            }
        }
    }
}

void keep_block() { //��� ŵ�ϱ� 
    int i, j, t;

    keep_max = 1;

    while (1) {
        if (keep_type == 7) {
            keep_type = type;
            for (i = 0; i < 4; i++) { //������ bx, by��ġ�� ������  
                for (j = 0; j < 4; j++) {
                    if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
                }
            }
            for (i = 1; i < 3; i++) { //���ӻ���ǥ�ÿ� ������ ���ú��� �׸� 
                for (j = 0; j < 4; j++) {
                    if (blocks[keep_type][0][i][j] == 1) {
                        gotoxy(STATUS_X_ADJ + 2 + j, i + 17);
                        printf("��");
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

        for (i = 0; i < 4; i++) { //������ bx, by��ġ�� ������  
            for (j = 0; j < 4; j++) {
                if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
            }
        }

        bx = (XSIZE / 2) - 1; //��� ���� ��ġx��ǥ(�������� ���) 
        by = 0;  //��� ������ġ y��ǥ(���� ��) 
        t = type;
        type = keep_type;
        keep_type = t;
        rotation = 0;

        for (i = 0; i < 4; i++) { //������ bx, by��ġ�� ������  
            for (j = 0; j < 4; j++) {
                if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j] = ACTIVE_BLOCK;
            }
        }
        for (i = 1; i < 3; i++) { //���ӻ���ǥ�ÿ� ������ ���ú��� �׸� 
            for (j = 0; j < 4; j++) {
                if (blocks[keep_type][0][i][j] == 1) {
                    gotoxy(STATUS_X_ADJ + 2 + j, i + 17);
                    printf("��");
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
    key = 0; //Ű�� �ʱ�ȭ  

    if (kbhit()) { //Ű�Է��� �ִ� ���  
        key = getch(); //Ű���� ����
        if (key == 224) { //����Ű�ΰ�� 
            do { key = getch(); } while (key == 224);// ����Ű���ð� ���� 
            switch (key) {
            case LEFT: //����Ű ��������  
                if (check_crush(bx - 1, by, rotation) == true) move_block(LEFT);
                break;                            //�������� �� �� �ִ��� üũ �� �����ϸ� �̵�
            case RIGHT: //������ ����Ű ��������- ���� �����ϰ� ó���� 
                if (check_crush(bx + 1, by, rotation) == true) move_block(RIGHT);
                break;
            case DOWN: //�Ʒ��� ����Ű ��������-���� �����ϰ� ó���� 
                if (check_crush(bx, by + 1, rotation) == true) move_block(DOWN);
                break;
            case UP: //���� ����Ű �������� 
                if (check_crush(bx, by, (rotation + 1) % 4) == true) move_block(UP);
                //ȸ�� ���� üũ �� �����ϸ� ȸ��
                else if (crush_on == 1 && check_crush(bx, by - 1, (rotation + 1) % 4) == true) move_block(100); // �ٴڿ� ���� ��� ��ĭ ������ ȸ��
            }
        }
        else {
            switch (key) {
            case SPACE: //�����̽�Ű �������� 
                space_key_on = 1; //�����̽�Ű flag�� ��� 
                while (crush_on == 0) { //�ٴڿ� ���������� �̵���Ŵ 
                    drop_block();
                    score += 3; // hard drop ���ʽ�
                    gotoxy(STATUS_X_ADJ, STATUS_Y_SCORE); printf("        %6d", score); //���� ǥ��  
                }
                // �̺κп� ����ȿ�� �߰� ����
                break;
            case C:
            case c:
                if(keep_max==0) keep_block();
                break;
            case ESC: //ESC�������� 
                system("cls"); //ȭ���� ����� 
                exit(0); //�������� 
            }
        }
    }
    while (kbhit()) getch(); //Ű���۸� ��� 
}

void drop_block() {
    int i, j;

    if (crush_on && check_crush(bx, by + 1, rotation) == true) crush_on = 0; //���� ��������� crush flag �� 
    if (crush_on && check_crush(bx, by + 1, rotation) == false) { //���� ��������ʰ� crush flag�� ���������� 
        for (i = 0; i < YSIZE; i++) { //���� �������� ���� ���� 
            for (j = 0; j < XSIZE; j++) {
                if (main_org[i][j] == ACTIVE_BLOCK) main_org[i][j] = INACTIVE_BLOCK;
            }
        }
        crush_on = 0; //flag�� �� 
        check_line(); //����üũ�� �� 
        new_block_type = 1; //���ο� ������ flag�� ��    
        return; //�Լ� ���� 
    }
    if (check_crush(bx, by + 1, rotation) == true) move_block(DOWN); //���� ��������� ������ ��ĭ �̵� 
    if (check_crush(bx, by + 1, rotation) == false) crush_on++; //������ �̵��� �ȵǸ�  crush flag�� ��
}

int check_crush(int bx, int by, int b_rotation) { //������ ��ǥ�� ȸ�������� �浹�� �ִ��� �˻� 
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) { //������ ��ġ�� �����ǰ� ������� ���ؼ� ��ġ�� false�� ���� 
            if (blocks[type][b_rotation][i][j] == 1 && main_org[by + i][bx + j] > 0) return false;
        }
    }
    return true; //�ϳ��� �Ȱ�ġ�� true���� 
};

void move_block(int dir) { //����� �̵���Ŵ 
    int i, j;

    switch (dir) {
    case LEFT: //���ʹ��� 
        for (i = 0; i < 4; i++) { //������ǥ�� ���� ���� 
            for (j = 0; j < 4; j++) {
                if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
            }
        }
        for (i = 0; i < 4; i++) { //�������� ��ĭ���� active block�� ���� 
            for (j = 0; j < 4; j++) {
                if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j - 1] = ACTIVE_BLOCK;
            }
        }
        bx--; //��ǥ�� �̵� 
        break;

    case RIGHT:    //������ ����. ���ʹ����̶� ���� ������ ���� 
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

    case DOWN:    //�Ʒ��� ����. ���ʹ����̶� ���� ������ ����
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

    case UP: //Ű���� ���� �������� ȸ����Ŵ. 
        for (i = 0; i < 4; i++) { //������ǥ�� ���� ����  
            for (j = 0; j < 4; j++) {
                if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
            }
        }
        rotation = (rotation + 1) % 4; //ȸ������ 1������Ŵ(3���� 4�� �Ǵ� ���� 0���� �ǵ���) 
        for (i = 0; i < 4; i++) { //ȸ���� ����� ���� 
            for (j = 0; j < 4; j++) {
                if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j] = ACTIVE_BLOCK;
            }
        }
        break;

    case 100: //����� �ٴ�, Ȥ�� �ٸ� ��ϰ� ���� ���¿��� ��ĭ���� �÷� ȸ���� ������ ��� 
              //�̸� ���۽�Ű�� Ư������ 
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

    int    block_amount; //������ ��ϰ����� �����ϴ� ���� 
    int combo = 0; //�޺����� �����ϴ� ���� ������ �ʱ�ȭ 

    for (i = YSIZE - 2; i > 3;) { //i=MAIN_Y-2 : ���ʺ��� ��ĭ����,  i>3 : õ��(3)�Ʒ����� �˻� 
        block_amount = 0; //��ϰ��� ���� ���� �ʱ�ȭ 
        for (j = 1; j < XSIZE - 1; j++) { //���� �������� ��ϰ����� �� 
            if (main_org[i][j] > 0) block_amount++;
        }
        if (block_amount == XSIZE - 2) { //����� ���� �� ���
            cnt++; //���� �� ���� ī��Ʈ ���� 
            combo++; //�޺��� ����
            for (l = 1; l < XSIZE - 1; l++) { //������ ��ĭ�� ��� ����(������ õ���� �ƴ� ��쿡��) 
                for (k = i; k > 1; k--) {
                    if (main_org[k - 1][l] != CEILLING) main_org[k][l] = main_org[k - 1][l]; //�� ĭ ������
                    if (main_org[k - 1][l] == CEILLING) main_org[k][l] = EMPTY; //õ�� �ؿ� ��ĭ�� �־���
                }
            }
        }
        else i--;
    }
    score += 100; //�����߰� 
    if (combo) { //�� ������ �ִ� ��� ������ ���� ��ǥ�� ���� ǥ����  
        if (combo > 1) { //2�޺��̻��� ��� ��� ���ʽ��� �޼����� �����ǿ� ����ٰ� ���� 
            gotoxy(MAIN_X_ADJ + (XSIZE / 2) - 1, MAIN_Y_ADJ + by - 1); printf("%d COMBO!", combo);
            Sleep(500);
            score += (combo * 100);
            reset_main_cpy(); //�ؽ�Ʈ�� ����� ���� main_cpy�� �ʱ�ȭ.
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
        if (main_org[3][i] > 0) { //õ��(������ ����° ��)�� inactive�� �����Ǹ� ���� ���� 
            gotoxy(x, y + 0); printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�"); //���ӿ��� �޼��� 
            gotoxy(x, y + 1); printf("��                              ��");
            gotoxy(x, y + 2); printf("��  +-----------------------+   ��");
            gotoxy(x, y + 3); printf("��  |  G A M E  O V E R..   |   ��");
            gotoxy(x, y + 4); printf("��  +-----------------------+   ��");
            gotoxy(x, y + 5); printf("��   YOUR SCORE: %6d         ��", score);
            gotoxy(x, y + 6); printf("��                              ��");
            gotoxy(x, y + 7); printf("��  Press any key to restart..  ��");
            gotoxy(x, y + 8); printf("��                              ��");
            gotoxy(x, y + 9); printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�");
            last_score = score; //���������� �ű� 

            if (score > best_score) { //�ְ��� ���Ž� 
                FILE* file = fopen("score.dat", "wt"); //score.dat�� ���� ����                

                gotoxy(x, y + 6); printf("��  �ڡڡ� BEST SCORE! �ڡڡ�   ��  ");

                if (file == 0) { //���� �����޼���  
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