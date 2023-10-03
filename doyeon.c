#include <stdio.h>

// 윈도우 크기
#define WIDTH 61
#define HEIGHT 31

// 최대 프로그램 개수
#define MAX_PROGRAMS 10

// 프로그램 구조체 정의
typedef struct {
    char name[61];
    int x1, y1, x2, y2;
} Program;

int main() {
    int n;
    scanf("%d", &n);

    int i, j;

    // 바탕화면 초기화
    char desktop[HEIGHT][WIDTH];
    for (i = 0; i <HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            desktop[i][j] = '.';
        }
    }

    // 프로그램 정보 입력 및 출력
    Program programs[MAX_PROGRAMS];

    for (i = 0; i < n; i++) {
        scanf("%s %d %d %d %d", programs[i].name, &programs[i].x1, &programs[i].y1, &programs[i].x2, &programs[i].y2);

        for (int fill_i = programs[i].x1; fill_i <= programs[i].x2; fill_i++) {
            for (int fill_j = programs[i].y1; fill_j <= programs[i].y2; fill_j++) {
                desktop[fill_j][fill_i] = ' ';
            }
        }
        // 프로그램 윈도우 테두리 그리기
        for (int x = programs[i].x1; x <= programs[i].x2; x++) {
            desktop[programs[i].y1][x] = '-';
            desktop[programs[i].y2][x] = '-';
        }
        for (int y = programs[i].y1; y <= programs[i].y2; y++) {
            desktop[y][programs[i].x1] = '|';
            desktop[y][programs[i].x2] = '|';
        }

        // 프로그램명 출력
        int nameLength = programs[i].x2 - programs[i].x1 - 1;
        if (nameLength >= 1) {
            for (int j = 0; j < nameLength; j++) {
                if (programs[i].name[j] == '\0') break;
                desktop[programs[i].y1][programs[i].x1 + 1 + j] = programs[i].name[j];
            }
        }

        // '+' 출력
        desktop[programs[i].y1][programs[i].x1] = '+';
        desktop[programs[i].y2][programs[i].x1] = '+';
        desktop[programs[i].y1][programs[i].x2] = '+';
        desktop[programs[i].y2][programs[i].x2] = '+';
    }

    // 바탕화면 출력
    for (i = 1; i < HEIGHT; i++) {
        for (j = 1; j < WIDTH; j++) {
            printf("%c", desktop[i][j]);
        }
        printf("\n");
    }

    return 0;
}
