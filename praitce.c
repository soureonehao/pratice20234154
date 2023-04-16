#include <stdio.h>

#define MAXSTU 10
int inputscore(int stu_score[])
{
	int i;
	printf("��¼��ѧ���ɼ�\n");
	for (i = 0; i < MAXSTU; i++) {
		scanf_s("%d", &stu_score[i]);
	}
}

void displayscore(int stu_score[])
{
	int i;
	printf("��ʾѧ���ɼ�\n");
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
	printf("�ܷ�Ϊ��%d ƽ����Ϊ��%0.2f", sum, pin);
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
	printf("��߷�Ϊ%d,��ͷ�Ϊ��%d\n", stu_score[MAXSTU - 1], stu_score[0]);

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
	printf("�ֶ���0-60 ����%d�ˣ� �ֶ���60-80����%d�ˣ� �ֶ���80-100����%d��\n", n0_60, n60_80, n80_100);
}

void password()
{
	int pass = 123, passs ,i = 0;
	while (1) {
		printf("���������룺");
		scanf_s("%d", &passs);
		if (passs == pass) {
			printf("������ȷ����ӭ���ˣ�");
			getch();
			break;
		}
		else {
			printf("��������������������룡");
			i++;	
			if (i == 5)
			{
				printf("���Ѿ����5�Σ�ллʹ�ã�");
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
	printf("\t\t|          ѧ���ɼ�ͳ��ϵͳ        |\n");
	printf("\t\t|----------------------------------|\n");
	printf("\t\t|          1--¼��ѧ���ɼ�         |\n");
	printf("\t\t|          2--��ʾѧ���ɼ�         |\n");
	printf("\t\t|          3--ͳ���ֺܷ�ƽ����     |\n");
	printf("\t\t|          4--ͳ����߷ֺ���ͷ�   |\n");
	printf("\t\t|          5--ͳ�Ƹ�����������     |\n");
	printf("\t\t|          0--�˳�                 |\n");
	printf("\t\t|----------------------------------|\n");
}

void main()
{
	int stu_score[MAXSTU];
	int stu_count = 0;
	int choose;
	password();   //����������ܽ���ϵͳ
	while (1)
	{

		mainmenu();
		printf("\t\t ��ѡ�����˵����(0~5):");
		scanf_s("%d", &choose);
		switch (choose)
		{
		case 1:stu_count = inputscore(stu_score); break;
		case 2:displayscore(stu_score); break;
		case 3:sumavgscore(stu_score); break;
		case 4:maxminscore(stu_score); break;
		case 5:gradescore(stu_score); break;
		case 0: printf("ллʹ�ã�"); return;
		default:printf("\n\t\t ������Ч��������ѡ��!\n");
		}
		printf("\n\n\t\t ��������������˵�");
		getch();
	}
}