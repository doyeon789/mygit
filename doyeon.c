#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char name[20];
    int score;
} Student;

int compare(const void *a, const void *b)
{
    Student first = *(Student *)a;
    Student second = *(Student *)b;
    if (first.score > second.score)
    {
        return -1;
    }
    else if (first.score < second.score)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char *solution(char *name[], int names_len, int scores[], int score_len[], int K)
{
    int len = names_len;
    Student *students = (Student *)malloc(sizeof(Student) * len);
    int i;
    for (i = 0; i < len; i++)
    {
        strcpy_s(students[i], sizeof(students) / sizeof(students[0]), name[i]);
        len = names_len;
    }
    qsort(students, len, sizeof(Student), compare);

    return students[K - 1].name;
}
