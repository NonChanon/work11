#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct _team {
	char name[50];
	int score = 0;
	int A = 0;
	int D = 0;
};

void swap(_team* A, _team* B) {
	_team temp;
	temp = *A;
	*A = *B;
	*B = temp;
}

int main()
{
	int a[4][4];
	_team team[4];
	for (int i = 0; i < 4; i++)
	{
		scanf("%s", &team[i].name);
	}
	/*for(int i=0;i<4;i++)
	{
		printf("%s",team[i].name);
	}*/
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &a[i][j]);

			team[i].A += a[i][j];
			team[j].D += a[i][j];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = i; j < 4; j++)
		{
			if (i == j)
			{
				continue;
			}
			//	printf("%d:%d -> %d:%d\n",i,j,a[i][j],a[j][i]);
			if (a[i][j] == a[j][i])
			{
				team[i].score += 1;
				team[j].score += 1;
			}
			else if (a[i][j] > a[j][i])
			{
				team[i].score += 3;
			}
			else if (a[j][i] > a[i][j])
			{
				team[j].score += 3;

			}
		}
	}
	/*for(int i=0;i<4;i++)
	{
		printf("%s %d %d %d\n",team[i].name,team[i].score,team[i].A,team[i].D);
	}*/
	for (int i = 0; i < 4; i++)
	{
		for (int j = i; j < 4; j++)
		{
			if (i == j)
			{
				continue;
			}
			if (team[i].score < team[j].score)
			{
				//printf("before swap %s %s\n",team[i].name,team[j].name);
				swap(&team[i], &team[j]);
				//printf("after swap %s %s\n",team[i].name,team[j].name);
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (team[i].score == team[i + 1].score)
		{
			if (team[i].A - team[i].D < team[i + 1].A - team[i + 1].D)
				swap(&team[i], &team[i + 1]);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (team[i].A - team[i].D == team[i + 1].A - team[i + 1].D)
		{
			if (team[i].A < team[i + 1].A)
				swap(&team[i], &team[i + 1]);
		}
	}





	for (int i = 0; i < 4; i++)
	{
		printf("%s %d\n", team[i].name, team[i].score);
	}
	return 0;
	/*
	0 0 2 1
	2 0 2 1
	1 1 0 0
	3 0 1 0

	00 01 02 03
	10 11 12 13
	20 21 22 23
	30 31 32 33
	*/
}
