/*
���ۿ��� ���� �κ� or ��Ʈ
- ������
- Ŀ�� �Լ�
- �������� �������� �ʵ��� �κ������� �����ϴ� ���
- �̸� ���� x, y��ǥ�� �̿��Ͽ� ������ �����ϴ� ���
- �ʿ��� �Լ�, ���� ������� �Լ�, ���� �̸� �Ϻ� ����
*/
/*
0 = ������
1 = �Ķ���
2 = �ʷϻ�
3 = ����
4 = ������
5 = ���ֻ�
6 = �����
7 = ��� //���� ���
8 = ȸ�� //��&õ��
9 = ���� �Ķ���
10 = ���� �ʷϻ�
11 = ���� ����
12 = ���� ������
13 = ���� ���ֻ�
14 = ���� �����
15 = ���� ��� //�����̴� ���
*/
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

void reset(int*,int*, int*); //������ �ʱ�ȭ 
void reset_main(); //���� ������
void reset_cpy(); //copy ������
void draw_state(int*,int*, int*); //���� ���� ǥ�� 
void draw_main(); //�������� �׸� 
void new_block(); //���ο� ����� �ϳ� ���� 
void keep_block(); //��� �ϳ��� ŵ��
void check_key(int*,int*, int*); //Ű����� Ű�� �Է¹��� 
void drop_block(int*,int*, int*); //����� �Ʒ��� ����Ʈ�� 
int check_crush(int bx, int by, int rotation); //bx, by��ġ�� rotationȸ������ ���� ��� �浹 �Ǵ� 
void move_block(int dir); //dir�������� ����� ������ 
void check_line(int*, int*, int*); //�� �Ͷ߸�
void check_game_over(int*, int*, int*); //���ӿ���

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
#define SPEED 50 // ���� �ӵ� (���� �������� ������)
};
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
int b_type_arr[7] = { 7,7,7,7,7,7,7 };

int type; //��� ������ ���� 
int rotation; //��� ȸ���� ���� 
int next_type; //���� ��ϰ� ����
int keep_type = 7; //ŵ�� ��ϰ� ����

int main_org[YSIZE][XSIZE]; // ������ ���� ���� �� main_cpy�� ���� 
int main_cpy[YSIZE][XSIZE]; // main_cpy�� �迭�� ���ؼ� �޶��� �� ����
int bx, by; // ��� ��ǥ
int key; // Ű�� ����
int score; // ���� ����
int best_score = 0; //�ְ��������
int keep_max;

int new_block_type = 6; // new block �ʿ� ����
int new_block_on = 0;
int crush_on = 0; // �̵� ����� �浹 ����
int space_key_on = 0; // hard drop ����

void gotoxy(int x, int y) { //���۸����� ������ ã�� Ŀ�� �̵��ϴ� �Լ�
    COORD pos = { 2 * x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //Ŀ�� �̵��ϴ°�
}

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE; //Ŀ������� �Լ��� ���Ǵ� ������ (���� ������� �����)
void setcursortype(CURSOR_TYPE cc) { //Ŀ������� �Լ� 
    CONSOLE_CURSOR_INFO CurInfo;

    switch (cc) {
    case NOCURSOR:
        CurInfo.dwSize = 1;//�β�
        CurInfo.bVisible = FALSE;//���⿩��
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
    int STATUS_Y_GOAL, STATUS_Y_SCORE, cnt;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    srand((unsigned)time(NULL)); //����ǥ���� 
    setcursortype(NOCURSOR); //Ŀ�� ����
    reset(&STATUS_Y_GOAL, &STATUS_Y_SCORE, &cnt); //������ ���� 

    while (1) {
        for (i = 0; i < 8; i++) { // ����� ��ĭ�������µ��� 5�� Ű�Է¹��� �� ���� 
            check_key(&STATUS_Y_GOAL, &STATUS_Y_SCORE, &cnt); //Ű�Է�Ȯ�� 
            draw_main(); //ȭ���� �׸� 
            Sleep(SPEED); //���Ӽӵ����� 
            if (crush_on && check_crush(bx, by + 1, rotation) == false) Sleep(100);
            //����� �浹���ΰ�� �߰��� �̵��� ȸ���� �ð��� ���� 
            if (space_key_on == 1) { //�����̽��ٸ� �������(hard drop) �߰��� �̵��� ȸ���Ҽ� ���� break; 
                space_key_on = 0;
                break;
            }
        }
        drop_block(&STATUS_Y_GOAL, &STATUS_Y_SCORE, &cnt); // ����� ��ĭ ���� 
        check_game_over(&STATUS_Y_GOAL, &STATUS_Y_SCORE, &cnt); //���ӿ����� üũ 
        if (new_block_on) {
            new_block();
            keep_max = 0; // ŵ �� ����� �ٲܼ� �ִ��� ���� �ʱ�ȭ
        }
    }
}

void reset(int* STATUS_Y_GOAL, int* STATUS_Y_SCORE, int* cnt) {

    FILE* file = fopen("score.dat", "rt");
    if (file == 0) { best_score = 0; }
        fscanf(file, "%d", &best_score); // ������ ������ �ְ������� �ҷ��� 
    fclose(file); //���� ���� 

    *cnt = 0;
    score = 0;
    key = 0;
    crush_on = 0;
    new_block_type = 6;
    next_type = rand() % 7;
    keep_type = 7;
    for (int i = 0; i < 7; i++) b_type_arr[i] = 7;

    system("cls"); //ȭ������ 
    reset_main(); // main_org�� �ʱ�ȭ 
    draw_state(STATUS_Y_GOAL, STATUS_Y_SCORE, cnt); // ���� ���� ǥ��
    draw_main(); // �������� �׸� 
    next_type = rand() % 7;
    new_block(); //���ο� ����� �ϳ� ����  

}

void reset_main() { // �������� �׸� 
    int i, j;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
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

void reset_cpy() { // main_cpy�� �ʱ�ȭ 
    int i, j;

    for (i = 0; i < YSIZE; i++) { 
        for (j = 0; j < XSIZE; j++) {
            main_cpy[i][j] = 100; // �����ǿ� ������ �ʴ� ��
        }
    }
}

void draw_state(int* STATUS_Y_GOAL, int* STATUS_Y_SCORE, int* cnt) { // ���� ���� ǥ��
    int y = 3;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    
    gotoxy(STATUS_X_ADJ, y    ); printf("��������  ���� �������� ");
    gotoxy(STATUS_X_ADJ, y + 1); printf("��             �� ");
    gotoxy(STATUS_X_ADJ, y + 2); printf("��             �� ");
    gotoxy(STATUS_X_ADJ, y + 3); printf("��             �� ");
    gotoxy(STATUS_X_ADJ, y + 4); printf("��             �� ");
    gotoxy(STATUS_X_ADJ, y + 5); printf("������������������������������ ");
    gotoxy(STATUS_X_ADJ, *STATUS_Y_GOAL = y + 7); printf(" ���� �� \t: %7d", *cnt);
    gotoxy(STATUS_X_ADJ, *STATUS_Y_SCORE = y + 8); printf(" �� ���� \t: %7d", score);
    gotoxy(STATUS_X_ADJ, y + 9); printf(" �ְ� ����: %7d", best_score);
    gotoxy(STATUS_X_ADJ, y + 11); printf("��������  ���� �������� ");
    gotoxy(STATUS_X_ADJ, y + 12); printf("��             �� ");
    gotoxy(STATUS_X_ADJ, y + 13); printf("��             �� ");
    gotoxy(STATUS_X_ADJ, y + 14); printf("��             �� ");
    gotoxy(STATUS_X_ADJ, y + 15); printf("��             �� ");
    gotoxy(STATUS_X_ADJ, y + 16); printf("������������������������������ ");
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
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
                    printf("--");
                    break;
                case WALL: // ��
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
                    printf("��");
                    break;
                case INACTIVE_BLOCK: // ���� ���
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    printf("��");
                    break;
                case ACTIVE_BLOCK: // �����̴� ���
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
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
    int i, j, random_type, avoid_overlapping;

    new_block_on = 0;
    new_block_type++;

    if (new_block_type == 7) {
        new_block_type = 0;
        b_type_arr[0] = rand() % 7;
        for (i = 1; i < 7; i++) {
            while (1) {
                avoid_overlapping = 0;
                random_type = rand() % 7;
                for (j = 0; j < i; j++) {
                    avoid_overlapping += random_type == b_type_arr[j];
                }
                if (avoid_overlapping == 0) {
                    b_type_arr[i] = random_type;
                    break;
                }
            }
        }
    }

    

    bx = (XSIZE / 2) - 1; //��� ���� ��ġx��ǥ(�������� ���) 
    by = 0;  //��� ������ġ y��ǥ(���� ��)
    type = next_type; //���������� ������
    next_type = b_type_arr[new_block_type]; //���� ���� ����
    rotation = 0;  //ȸ���� 0������ ������

    for (i = 0; i < 4; i++) { //������ bx, by��ġ�� ������  
        for (j = 0; j < 4; j++) {
            if (blocks[type][rotation][i][j] == 1) main_org[by + i][bx + j] = ACTIVE_BLOCK;
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    for (i = 1; i < 3; i++) { //���ӻ���ǥ�ÿ� ������ ���ú��� �׸� 
        for (j = 0; j < 4; j++) {
            if (blocks[next_type][0][i][j] == 1) {
                gotoxy(STATUS_X_ADJ + 2 + j, i + 4);
                printf("��");
            }
            else {
                gotoxy(STATUS_X_ADJ + 2 + j, i + 4);
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
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            for (i = 1; i < 3; i++) {
                for (j = 0; j < 4; j++) {
                    if (blocks[keep_type][0][i][j] == 1) {
                        gotoxy(STATUS_X_ADJ + 2 + j, i + 15);
                        printf("��");
                    }
                    else {
                        gotoxy(STATUS_X_ADJ + 3 + j, i + 15);
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
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        for (i = 1; i < 3; i++) { //���ӻ���ǥ�ÿ� ������ ���ú��� �׸� 
            for (j = 0; j < 4; j++) {
                if (blocks[keep_type][0][i][j] == 1) {
                    gotoxy(STATUS_X_ADJ + 2 + j, i + 15);
                    printf("��");
                }
                else {
                    gotoxy(STATUS_X_ADJ + 2 + j, i + 15);
                    printf("  ");
                }
            }
        }
        break;
    }
}

void check_key(int* STATUS_Y_GOAL, int* STATUS_Y_SCORE, int* cnt) {
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
                    drop_block(STATUS_Y_GOAL, STATUS_Y_SCORE, cnt);
                    score += 3; // hard drop ���ʽ�
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    gotoxy(STATUS_X_ADJ, *STATUS_Y_SCORE); printf(" �� ���� \t: %7d", score); //���� ǥ��  
                }
                // �̺κп� ����ȿ�� �߰� ����
                break;
            case C:
            case c:
                if(keep_max==0) keep_block();
                break;
            case ESC: //ESC�������� 
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                system("cls"); //ȭ���� ����� 
                exit(0); //�������� 
            }
        }
    }
    while (kbhit()) getch(); //Ű���۸� ��� 
}

void drop_block(int* STATUS_Y_GOAL, int* STATUS_Y_SCORE, int* cnt) {
    int i, j;

    if (crush_on && check_crush(bx, by + 1, rotation) == true) crush_on = 0; //���� ��������� crush flag �� 
    if (crush_on && check_crush(bx, by + 1, rotation) == false) { //���� ��������ʰ� crush flag�� ���������� 
        for (i = 0; i < YSIZE; i++) { //���� �������� ���� ���� 
            for (j = 0; j < XSIZE; j++) {
                if (main_org[i][j] == ACTIVE_BLOCK) main_org[i][j] = INACTIVE_BLOCK;
            }
        }
        crush_on = 0; //flag�� �� 
        check_line(STATUS_Y_GOAL, STATUS_Y_SCORE, cnt); //����üũ�� �� 
        new_block_on = 1;
        //new_block_type += 1; //���ο� ������ flag�� ��    
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

void check_line(int *STATUS_Y_GOAL, int *STATUS_Y_SCORE, int *cnt) {
    int i, j, k, l;

    int block_amount; //������ ��ϰ����� �����ϴ� ���� 
    int combo = 0; //�޺����� �����ϴ� ���� ������ �ʱ�ȭ 

    for (i = YSIZE - 2; i > 3;) { //i=MAIN_Y-2 : ���ʺ��� ��ĭ����,  i>3 : õ��(3)�Ʒ����� �˻� 
        block_amount = 0; //��ϰ��� ���� ���� �ʱ�ȭ 
        for (j = 1; j < XSIZE - 1; j++) { //���� �������� ��ϰ����� �� 
            if (main_org[i][j] > 0) block_amount++;
        }

        if (block_amount == XSIZE - 2) { //����� ���� �� ���
            *cnt += 1; //���� �� ���� ī��Ʈ ���� 
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
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        switch (combo) {
        case 1:
            gotoxy(MAIN_X_ADJ + (XSIZE / 2) - 1, MAIN_Y_ADJ + by - 1); printf("�̱�!");
            Sleep(500);
            score += (combo * 100);
            reset_cpy();
            break;
        case 2:
            gotoxy(MAIN_X_ADJ + (XSIZE / 2) - 1, MAIN_Y_ADJ + by - 1); printf("����!");
            Sleep(500);
            score += (combo * 100);
            reset_cpy();
            break;
        case 3:
            gotoxy(MAIN_X_ADJ + (XSIZE / 2) - 1, MAIN_Y_ADJ + by - 1); printf("Ʈ����!");
            Sleep(500);
            score += (combo * 100);
            reset_cpy();
            break;
        case 4:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            gotoxy(MAIN_X_ADJ + (XSIZE / 2) - 1, MAIN_Y_ADJ + by - 1); printf("��Ʈ����!");
            Sleep(500);
            score += (combo * 100);
            reset_cpy();
            break;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        gotoxy(STATUS_X_ADJ, *STATUS_Y_GOAL); printf(" ���� �� \t: %7d", *cnt);
        gotoxy(STATUS_X_ADJ, *STATUS_Y_SCORE); printf(" �� ���� \t: %7d", score);
    }
}

void check_game_over(int* STATUS_Y_GOAL, int* STATUS_Y_SCORE, int* cnt) {
    int i;
    int x = 5;
    int y = 5;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    for (i = 1; i < XSIZE - 2; i++) {
        if (main_org[3][i] > 0) { //õ��(������ ����° ��)�� inactive�� �����Ǹ� ���� ����
            gotoxy(x, y + 2); printf(" ��������������������������������������������������  ");
            gotoxy(x, y + 3); printf(" ��    G A M E  O V E R   ��  ");
            gotoxy(x, y + 4); printf(" ��������������������������������������������������  ");
            gotoxy(x, y + 5); printf("     �� ���� : %7d      ", score);
            gotoxy(x, y + 6); printf("     ���� �� : %7d      ", *cnt);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            if (score > best_score) { 
                FILE* file = fopen("score.dat", "wt"); //score.dat�� ���� ����                

                gotoxy(x, y + 1); printf("          �ְ�����!          ");

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
            reset(STATUS_Y_GOAL, STATUS_Y_SCORE, cnt);
        }
    }
}