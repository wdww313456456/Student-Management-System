#include"management.h"
struct student stu[MAX_STU];
int stu_count = 0;
void menu()
{
	printf("****************************************\n");
	printf("***1.添加学生	      2.删除学生**********\n");
	printf("***3.查找学生	      4.修改学生信息*******\n");
	printf("***5.显示学生信息     0.退出**************\n");
	printf("****************************************\n");
}
void add_stu()
{
    if (stu_count >= MAX_STU)
    {
        printf("学生数量已达上限，无法添加！\n");
        return;
    }

    char id[20];
    printf("请输入学号：");
    scanf("%s", id);
    for (int i = 0; i < stu_count; i++)
    {
        if (strcmp(id, stu[i].id) == 0)
        {
            printf("该学号已存在！\n");
            return;
        }
    }

    strcpy(stu[stu_count].id, id);
    printf("请输入姓名：");
    scanf("%s", stu[stu_count].name);
    printf("请输入数学成绩：");
    scanf("%f", &stu[stu_count].score[0]);
    printf("请输入英语成绩：");
    scanf("%f", &stu[stu_count].score[1]);
    stu_count++;
    printf("添加成功！\n");
}
void search_stu()
{
    if (stu_count == 0)
    {
        printf("暂无学生信息！\n");
        return;
    }

    char id[20];
    printf("请输入要查找的学生学号：");
    scanf("%s", id);

    for (int i = 0; i < stu_count; i++)
    {
        if (strcmp(id, stu[i].id) == 0)
        {
            printf("找到学生：\n");
            printf("学号：%s\n姓名：%s\n数学：%.1f\n英语：%.1f\n",
                   stu[i].id, stu[i].name, stu[i].score[0], stu[i].score[1]);
            return;
        }
    }
    printf("未找到该学生！\n");
}
void show_stu()
{
	if(stu_count==0)
	{
		printf("系统为空\n");
		return;
	}
	printf("%21s%21s%10s%10s\n", "姓名", "学号", "数学成绩", "英语成绩");
	for(int i = 0;i<stu_count;i++)
	{
		printf("%21s%21s%10f%10f\n",stu[i].name, stu[i].id, stu[i].score[0], stu[i].score[1]);
	}
}
void del_stu()
{
    if (stu_count == 0)
    {
        printf("暂无学生信息，无法删除！\n");
        return;
    }

    show_all();
    char id[20];
    printf("请输入要删除的学生学号：");
    scanf("%s", id);

    for (int i = 0; i < stu_count; i++)
    {
        if (strcmp(id, stu[i].id) == 0)
        
            for (int j = i; j < stu_count - 1; j++)
            {
                stu[j] = stu[j + 1];
            }
            stu_count--;
            printf("删除成功！\n");
            return;
        }
    }
    printf("未找到该学生！\n");
}

int main()
{
	int x = 0;
	do 
	{
		menu();
		printf("请输入想执行的操作：");
		scanf("%d", &x);
		switch (x)
		{
			case 1:
			{
				add_stu();
				break;
			}
			case 2:
			{	
				del_stu();
				break;
			}
			case 3:
			{
				search_stu();
				break;
			}
			case 4:
			{
				modify_stu();
				break;
			}
			case 5:
			{
				show_stu();
				break;
			}
			case 0:
			{
				
				printf("已退出管理系统\n");
				break;
		        }
			default:
			{
				printf("输入错误，请重新输入\n");
				break;
			}
		}
	}while(x!=0);
}
