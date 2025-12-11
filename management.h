#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#define MAX_STU 20
struct student
{
	char id[MAX_STU];
	char name[MAX_STU];
	float score[2];
};
void add_stu();
void del_stu();
void search_stu();
void modify_stu();
void show_stu();
