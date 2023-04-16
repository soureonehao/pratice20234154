#include <stdio.h>

#define MAXSTU 10
int inputscore(int stu_score[])
{
	int i;
	printf("请录入学生成绩\n");
	for (i = 0; i < MAXSTU; i++) {
		scanf_s("%d", &stu_score[i]);
	}
}

void displayscore(int stu_score[])
{
	int i;
	printf("显示学生成绩\n");
	for (i = 0; i < MAXSTU; i++) {
		printf("%d ", stu_score[i]);
	}
}

void sumavgscore(int stu_score[])
{
	int i, sum = 0;
	float pin = 0;
	for (i = 0; i < MAXSTU; i++) {
		sum += stu_score[i];
	}
	pin = sum / MAXSTU * 1.0;
	printf("总分为：%d 平均分为：%0.2f", sum, pin);
}

void maxminscore(int stu_score[])
{
	int i,j, box = 0;
	for (j = 0; j < MAXSTU - 1; j++) {
		for (i = 0; i < MAXSTU - 1; i++) {
			if (stu_score[i] > stu_score[i + 1]) {
				box = stu_score[i];
				stu_score[i] = stu_score[i + 1];
				stu_score[i + 1] = box;
			}
		}
	}
	printf("最高分为%d,最低分为：%d\n", stu_score[MAXSTU - 1], stu_score[0]);

}

void gradescore(int stu_score[])
{
	int i, n0_60 = 0, n60_80 = 0, n80_100 = 0;
	for (i = 0; i < MAXSTU; i++) {
		if (stu_score[i] >= 0 && stu_score[i] < 60)
			n0_60++;
		else if (stu_score[i] >= 60 && stu_score[i] < 80)
			n60_80++;
		else if (stu_score[i] >= 80 && stu_score[i] <= 100)
			n80_100++;
	}
	printf("分段在0-60 的有%d人， 分段在60-80的有%d人， 分段在80-100的有%d人\n", n0_60, n60_80, n80_100);
}

void password()
{
	int pass = 123, passs ,i = 0;
	while (1) {
		printf("请输入密码：");
		scanf_s("%d", &passs);
		if (passs == pass) {
			printf("密码正确！欢迎主人！");
			getch();
			break;
		}
		else {
			printf("输入密码错误，请重新输入！");
			i++;	
			if (i == 5)
			{
				printf("您已经输错5次，谢谢使用！");
				exit();
			}
			continue;
		}	
	}
}
void mainmenu()
{
	system("cls");
	printf("\n\n");
	printf("\t\t|----------------------------------|\n");
	printf("\t\t|          学生成绩统计系统        |\n");
	printf("\t\t|----------------------------------|\n");
	printf("\t\t|          1--录入学生成绩         |\n");
	printf("\t\t|          2--显示学生成绩         |\n");
	printf("\t\t|          3--统计总分和平均分     |\n");
	printf("\t\t|          4--统计最高分和最低分   |\n");
	printf("\t\t|          5--统计各分数段人数     |\n");
	printf("\t\t|          0--退出                 |\n");
	printf("\t\t|----------------------------------|\n");
}

void main()
{
	int stu_score[MAXSTU];
	int stu_count = 0;
	int choose;
	password();   //输入密码才能进入系统
	while (1)
	{

		mainmenu();
		printf("\t\t 请选择主菜单序号(0~5):");
		scanf_s("%d", &choose);
		switch (choose)
		{
		case 1:stu_count = inputscore(stu_score); break;
		case 2:displayscore(stu_score); break;
		case 3:sumavgscore(stu_score); break;
		case 4:maxminscore(stu_score); break;
		case 5:gradescore(stu_score); break;
		case 0: printf("谢谢使用！"); return;
		default:printf("\n\t\t 输入无效，请重新选择!\n");
		}
		printf("\n\n\t\t 按任意键返回主菜单");
		getch();
	}
}