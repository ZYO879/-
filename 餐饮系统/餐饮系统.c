/*����ϵͳ*/ 
//1.��Ӳ�Ʒ����Ʒ�����۸����ͣ� 
//2.չʾ�˵� 
//3.ѡ���Ʒ���ಢ�鿴�Ӳ˵� �����ͷ�� 
//4.ɾ����Ʒ 
//5.��� 
//6.����
//7.�鿴��Ʒ 
//8.�޸Ĳ�Ʒ 
//9.���� 
 
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>

typedef struct dishes//�����Ʒ�ṹ��
{
	char kind[20]; 
	char name[30];
	float charge;
	int num;
	int n; 
	struct dishes *pNext;
} DISH;

DISH *Read(DISH *pHead);//��ȡ�ļ� 

void Show();//�������� 

void Function_Menu();//��ӡ���ܲ˵� 

DISH *Add(DISH *pHead);//��Ӳ�Ʒ 

DISH *Menu(DISH *pHead, DISH *pOrder);//��ӡ�˵� 

DISH *Delete(DISH *pHead);//ɾ����Ʒ

void Change(DISH *pHead);//�޸Ĳ�Ʒ 

void Sort_choose(DISH *pHead); //����ʽѡ��

void Name_sort(DISH *pHead);//���������� 

void Charge_sort(DISH *pHead, char c);//���۸����� 

DISH *Order(DISH *pOrder, DISH *pHead);//��� 

DISH *Bill(DISH *pOrder, DISH *pHead);//����

void Arrange(DISH *pOrder);//������ 

DISH *Bill_delete(DISH *pOrder, int n);//�˲� 

void Write(DISH *pHead);//д���ļ� 

int main()//������ 
{	
	system("title ����ϵͳV4.0");//����̨���� 
	char c;
	DISH *pHead = NULL;
	DISH *pOrder = NULL;
	pHead = Read(pHead); 
	Show(); 
	system("pause");
	system("cls");
	
	while(1)//����ѡ�� 
	{
		Function_Menu();
		c = getch();
		switch(c)
		{
			case '1': 
				pHead = Add(pHead); 
				break;
			case '2': 
				pHead = Delete(pHead); 
				break;
			case '3': 
				Change(pHead);
				break;
			case '4': 
				Sort_choose(pHead);
				break;
			case '5': 
				pOrder = Order(pOrder, pHead);
				break;
			case '6': 
				pOrder = Bill(pOrder, pHead);
				break;
			case '7':
				pOrder = Menu(pHead, pOrder);
				break;
			case '8': 
				system("cls"); 
				printf("�Ƿ񱣴汾�β�Ʒ�޸�(Y/N)\n");
				char cc = getch();
				if(cc == 'Y'||cc == 'y')
					Write(pHead);
				printf("��лʹ�ã�"); 
				usleep(500000);
				return 0; 
				break;
			default: system("cls"); break;	
		}
	}
	return 0;
}

void Show()//�������� 
{

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t��ӭʹ�ò���ϵͳ4.0~\n");
	sleep(1);
	system("cls");
	system("color 8E"); 
	printf("\n\n\n\t\t\t\t\t                    *\n");
	usleep(50000);
	printf("\t\t\t\t\t          *        *        *\n");
	usleep(50000);
	printf("\t\t\t\t\t         *        *        *\n");
	usleep(50000);
	printf("\t\t\t\t\t          *        *        *\n");
	usleep(50000);
	printf("\t\t\t\t\t           *        *        *\n");
	usleep(50000);
	printf("\t\t\t\t\t          *        *        *\n");
	usleep(50000);
	printf("\t\t\t\t\t         *        *        *\n");
	usleep(50000);
	printf("\t\t\t\t\t        *         *        *\n");
	usleep(50000);
	printf("\t\t\t\t\t         *         *        *\n");
	usleep(500000);
	printf("\t\t\t\t\t(***************************************)\n");
	printf("\t\t\t\t\t(\\    ZZZZZZZZ   Y    Y     OOO       /)\n");
	printf("\t\t\t\t\t (\\         Z     Y  Y    O     O    /)\n");
	printf("\t\t\t\t\t  (\\      Z         Y     O     O   /)\n");
	printf("\t\t\t\t\t   (\\   Z          Y      O     O  /)\n");
	printf("\t\t\t\t\t    (\\ZZZZZZZZ    Y         OOO   /)\n");
	printf("\t\t\t\t\t     (\\                          /)\n");
	printf("\t\t\t\t\t      (\\@@@@@@@@@@@@@@@@@@@@@@@@/)\n\n\n\n\t\t\t\t\t\t��");
}

void Function_Menu()//��ӡ���ܲ˵� 
{
	printf("\n\n\n\n");
	printf("\t\t\t\t                 �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r                 \n");
	printf("\t\t\t\t�q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g  ����ϵͳV4.0  �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r\n");
	printf("\t\t\t\t�U                �t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s                �U\n");
	printf("\t\t\t\t�U     ��1����Ӳ�Ʒ             ��2��ɾ����Ʒ      �U\n");
	printf("\t\t\t\t�U                                                  �U\n");
	printf("\t\t\t\t�U     ��3���޸Ĳ�Ʒ             ��4���˵�����      �U\n");
	printf("\t\t\t\t�U                                                  �U\n");
	printf("\t\t\t\t�U     ��5�����                 ��6���鿴����      �U\n");
	printf("\t\t\t\t�U                                                  �U\n");
	printf("\t\t\t\t�U     ��7��չʾ�˵�             ��8���˳�ϵͳ      �U\n");
	printf("\t\t\t\t�U                                                  �U\n");
	printf("\t\t\t\t�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
	printf("\t\t\t\t\t�������빦��ǰ�����ִ����Ӧ�Ĺ���:");
}


DISH *Add(DISH *pHead)//��Ӳ�Ʒ 
{
	system("cls"); 
	DISH *pNew = (DISH *)malloc(sizeof(DISH));
	if(pNew==NULL)
	{
		printf("�ڴ治�㣡");
		exit(0);
	 } 
	//ָ����һ��ָ���
	pNew->pNext = NULL;
	//���������β���
	DISH *p = pHead;
	while (pHead != NULL && p->pNext != NULL)
	{
		p = p->pNext;
	}
	//�ѽڵ�嵽�����β�ڵ�
	if (pHead == NULL) 
	{
		pHead = pNew;
	}
	else 
	{
		p->pNext = pNew;
	}

	//¼���Ʒ��Ϣ
	printf("�������Ʒ���\n");
	scanf("%s", &pNew->kind);
	printf("�����������\n");
	scanf("%s", &pNew->name);
	printf("������۸�\n");
	scanf("%f", &pNew->charge);
	pNew->n = 1; 
	getchar();
	printf("��Ʒ��Ϣ¼��ɹ���\n�Ƿ����¼�룿��Y/N��\n");
	char c = getch();
	if(c=='Y'||c=='y')
		Add(pHead);
	system("cls");
	return pHead;
}

DISH *Menu(DISH *pHead, DISH *pOrder)//��ӡ�˵� 
{
	int i = 0;
	system("cls");
	DISH *p = pHead;
	if (p == NULL) 
	{
		printf("ϵͳ�����޲�Ʒ��Ϣ����¼���������ӡ�鿴��\n\n");
	}
	else 
	{
		printf("\t\t\t\t*********************************************************\n");
		printf("\t\t\t\t*\t\t  ��ӭ����ŷ�ǲ���  \t\t\t*\n");
		printf("\t\t\t\t*********************************************************\n");
		printf("\t\t\t\t*\t����\t\t    ���\t�۸�\t\t*\n");
		printf("\t\t\t\t*********************************************************\n");
		while (p != NULL)
		{
			i++;
			p->num = i;
			printf("\t\t\t\t*\t%-5d%-15s%-6s\t��%-8.2f\t*\n", i, p->name, p->kind, p->charge);
			p = p->pNext;
			printf("\t\t\t\t*********************************************************\n");
		}
		printf("\n\t\t\t\t\t\t  һ����%d����\n\n\n\t\t\t\t\t\t  ����Ҫ�����(Y/N)\n", i);
		char c = getch();
		if(c=='Y'||c=='y')
			pOrder = Order(pOrder, pHead);
		else
			system("pause");
	}
	system("cls");
	return pOrder;
}

void Change(DISH *pHead)//�޸Ĳ�Ʒ 
{
	system("cls");
	DISH *p = pHead;
	if (p == NULL) 
	{
		printf("ϵͳ�����޲�Ʒ��Ϣ��\n\n");
	}
	printf("�������Ʒ��ţ��˵��в�Ʒ��Ӧ��ţ���");
	int n, i = 0;
	scanf("%d", &n);
	char c;
	while(p != NULL)//�����Ʒ���� 
	{
		i++;
		p = p->pNext;
	}
	if(i < n||n <=0)
		printf("������޶�Ӧ��Ʒ��\n");
	else
	{
		p = pHead;
		for(i = 1; i < n; i++)
		p = p->pNext;
step1:
		printf("��ѡ���޸Ķ���\n1������\n2���۸�\n3�����\n4��ȫ��\n");
		c = getch();
		switch(c)
		{
			case '1': 
				system("cls");
				printf("�������޸ĺ�Ĳ�����\n");
				scanf("%s", p->name);
				getchar();
				break;
			case '2': 
				system("cls");
				printf("�������޸ĺ�ļ۸�\n");
				scanf("%f", &p->charge);
				break;
			case '3':
				system("cls");
				printf("�������޸ĺ�����\n");
				scanf("%s", p->kind);
				getchar();
				break;
			case '4': 
				system("cls");
				printf("�������޸ĺ�����\n");
				scanf("%s", p->kind);
				getchar();
				printf("�������޸ĺ�Ĳ�����\n");
				scanf("%s", p->name);
				printf("�������޸ĺ�ļ۸�\n");
				scanf("%f", &p->charge);
				break;
			default: 
				system("cls");
				goto step1;
				break;
		}
		system("cls");
		printf("��Ʒ��Ϣ�޸ĳɹ���\n");
	}
	system("pause");
	system("cls");
}

DISH *Delete(DISH *pHead)//ɾ����Ʒ
{
	system("cls");
	DISH *p = pHead;
	if (p == NULL) 
	{
		printf("ϵͳ�����޲�Ʒ��Ϣ��\n\n");
	}
	else
	{
		printf("�������Ʒ��ţ�");
		int n, i = 0;
		scanf("%d", &n);
		DISH  *pr;
		while(p != NULL)//�����Ʒ���� 
		{
			i++;
			p = p->pNext;
		}
		p = pHead;
		if(i < n||n <=0)
			printf("������޶�Ӧ��Ʒ��\n");
		else
		{
			for(i = 1; i < n - 1; i++)
				p = p->pNext;
			if(n == 1)//ɾ��ͷ�ڵ� 
			{
				pHead = p->pNext;
				free(p);
			}
			else
			{
				pr = p->pNext;
				p->pNext = pr->pNext;
				free(pr);
			}
			printf("ɾ���ɹ���\n");
		}
	}
	system("pause");
	system("cls");
	return pHead;
}

void Sort_choose(DISH *pHead)//����ʽѡ�� 
{
step3:
	system("cls");
	DISH *p = pHead;
	if (p == NULL) 
	{
		printf("ϵͳ�����޲�Ʒ��Ϣ��\n\n");
		system("pause");
		system("cls"); 
	}
	else
	{ 
		printf("\n\n\n\n");
		printf("\t\t\t\t                 �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r                 \n");
		printf("\t\t\t\t�q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g    ����ʽ    �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r\n");
		printf("\t\t\t\t�U                �t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s                �U\n");
		printf("\t\t\t\t�U     ��1������������           ��2�����۸�����    �U\n");
		printf("\t\t\t\t�U                                                  �U\n");
		printf("\t\t\t\t�U     ��3�����۸���                              �U\n");
		printf("\t\t\t\t�U                                                  �U\n");
		printf("\t\t\t\t�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
		printf("\t\t\t\t\t�����������ѡ����Ӧ������ʽ:");   
		char c = getch();
		switch(c)
		{
			case '1': Name_sort(pHead); break;
			case '2': 
			case '3': Charge_sort(pHead, c); break;
			default: goto step3; break;
		}
		printf("����ɹ���\n��򿪲˵��鿴��");
		system("pause");
		system("cls"); 
	} 
}

void Name_sort(DISH *pHead)//���������� 
{
	system("cls");
	int n = 0, i, j;
	float t;
	DISH *p = pHead;
	char a[30], b[20];
	while(p != NULL)//�����Ʒ���� 
	{
		n++;
		p = p->pNext;
	}
	for(i = 1; i < n; i++)
	{
		p = pHead;
		for(j = 0; j < n - i; j++)
		{
			if(strcmp(p->name, p->pNext->name) > 0)
			{
				strcpy(a, p->name);
				strcpy(p->name, p->pNext->name);
				strcpy(p->pNext->name, a);
				strcpy(b, p->kind);
				strcpy(p->kind, p->pNext->kind);
				strcpy(p->pNext->kind, b);
				t = p->charge;
				p->charge = p->pNext->charge;
				p->pNext->charge = t;	
			}
			p = p->pNext;
		}
	}
}

void Charge_sort(DISH *pHead, char c)//���۸����� 
{
	DISH *p = pHead;
	int n = 0, i, j;
	float t;
	char a[30], b[20];
		while(p != NULL)//�����Ʒ���� 
	{
		n++;
		p = p->pNext;
	}
	if(c == '2')
	{
		for(i = 1; i < n; i++)
		{
			p = pHead;
			for(j = 0; j < n - i; j++)
			{
				if(p->charge > p->pNext->charge)
				{
					strcpy(a, p->name);
					strcpy(p->name, p->pNext->name);
					strcpy(p->pNext->name, a);
					strcpy(b, p->kind);
					strcpy(p->kind, p->pNext->kind);
					strcpy(p->pNext->kind, b);
					t = p->charge;
					p->charge = p->pNext->charge;
					p->pNext->charge = t;	
				}
				p = p->pNext;
			}
		}
	}
	else
	{
		for(i = 1; i < n; i++)
		{
			p = pHead;
			for(j = 0; j < n - i; j++)
			{
				if(p->charge < p->pNext->charge)
				{
					strcpy(a, p->name);
					strcpy(p->name, p->pNext->name);
					strcpy(p->pNext->name, a);
					strcpy(b, p->kind);
					strcpy(p->kind, p->pNext->kind);
					strcpy(p->pNext->kind, b);
					t = p->charge;
					p->charge = p->pNext->charge;
					p->pNext->charge = t;
				}
				p = p->pNext;
			}
		}
	}
}

DISH *Order(DISH *pOrder, DISH *pHead)//���
{
	system("cls"); 
	int n, i;
	DISH *po = pOrder;
	DISH *ph = pHead;
	//¼���Ʒ���˵� 
	printf("�������Ʒ��ţ�\n");
	scanf("%d", &n);
	while(ph != NULL)//�����Ʒ���� 
	{
		i++;
		ph = ph->pNext;
	}
	ph = pHead;
	if(i < n||n <=0)
		printf("������޶�Ӧ��Ʒ��\n");
	else
	{
		for(i = 1; i < n; i++)
			ph = ph->pNext;
		DISH *pNew = (DISH *)malloc(sizeof(DISH));
		if(pNew==NULL)
		{
			printf("�ڴ治�㣡");
			exit(0);
		} 
		//ָ����һ��ָ���
		pNew->pNext = NULL;
		//���������β���
		while (pOrder != NULL && po->pNext != NULL)
		{
			po = po->pNext;
		}
		//�ѽڵ�嵽�����β�ڵ�
		if (pOrder == NULL) 
		{
			pOrder = pNew;
		}
		else 
		{
			po->pNext = pNew;
		}
		pNew->charge = ph->charge;
		strcpy(pNew->kind, ph->kind);
		strcpy(pNew->name, ph->name);
		pNew->n = 1;
		Arrange(pOrder);
		printf("��˳ɹ���\n�Ƿ������ˣ���Y/N��\n");
		char c = getch();
		if(c=='Y'||c=='y')
			Order(pOrder, pHead);
	}
	usleep(500000);
	system("cls");
	return pOrder;
}

DISH *Bill(DISH *pOrder, DISH *pHead)//���� 
{
	int i, j, n;
	float pay = 0.00; 
	system("cls");
	DISH *p = pOrder;
step4:
	if (p == NULL) 
	{
		printf("\n\n\n\n\n\n\n\t\t\t\t\t�׻�û�е��Ŷ~���˺������鿴��\n\n\n\n");
		sleep(1);
		system("cls");
		system("pause");
		system("cls");
		return pOrder; 
	}
		
	while(1)
	{
		i = 0;
		n = 0; 
		p = pOrder;
		printf("\t\t\t\t*********************************************************\n");
		printf("\t\t\t\t*\t\t  ��ӭ����ŷ�ǲ���  \t\t\t*\n");
		printf("\t\t\t\t*********************************************************\n");
		printf("\t\t\t\t*\t����\t\t\t���\t�۸�\t����\t*\n");
		printf("\t\t\t\t*********************************************************\n");

		while (p != NULL)
		{
			i ++;
			n += p->n;
			pay += p->charge * p->n;
			printf("\t\t\t\t*\t%-5d%-15s%-6s\t��%-8.2fx%-3d\t*\n", i, p->name, p->kind, p->charge, p->n);
			//��һ���ڵ�
			p = p->pNext;
			printf("\t\t\t\t*********************************************************\n");
		}
		printf("\n\t\t\t\t\t\t  һ���� %d ����\n\t\t\t\t\t\t  Ӧ֧��  ��%.2f\n\n\n", n, pay);
		printf("\t\t\t\t\t\t\t��1���������\n\t\t\t\t\t\t\t��2���˲�\n\t\t\t\t\t\t\t��3������\n");
		char c = getch(); 
		switch(c)
		{
			case '1':
				pOrder = Order(pOrder, pHead);
				break;
			case '2':
				system("cls");
				printf("�������Ʒ��ţ�");
				int n;
				scanf("%d", &n);
				if(i < n||n <=0)
				{
					printf("������޶�Ӧ��Ʒ��\n");
					sleep(1);
					system("cls");
				}
				else
				{
step5:
					system("cls");
					printf("��ȷ��Ҫ�˶���������Ϻó���~(Y/N)\n");
					char c1 = getch();
					if(c1 == 'y'||c1 == 'Y')
						{}
					else if(c1 == 'n'||c1 == 'N')
					{
						goto step4;
					}
					else
						goto step5;
					p = pOrder;
					for(j = 1; j < n; j ++)
						p = p->pNext;
					if(p->n == 1)
						Bill_delete(pOrder, n);
					else
					{
						system("cls");
						printf("��Ҫ�˼�����\n");
						int a;
						scanf("%d", &a);
						if(a > p->n)
						{
							printf("��û�е���ô���Ŷ~\n");
							system("pause");
							system("cls");
							goto step4;
						}
						else if(a <= 0)
						{
							printf("��Ч��ָ�\n");
							system("pause");
							goto step4;
						}
						else if(a == p->n)
						{
							pOrder = Bill_delete(pOrder, n);
						}
						else
						{
							p->n -= a;
						}
					}
					printf("�˶��ɹ���\n");
				}
				break;
			case '3':
				system("cls");
				return pOrder;
				break;
			default: 
				system("cls");
				goto step4;
				break;
		}
	}
	return pOrder;
}

void Arrange(DISH *pOrder)//������ 
{
	DISH *p1 = pOrder, *p2 = pOrder;
	int n1 = 0, n2, n = 0;
	while(p1 != NULL)
	{
		n ++;
		p1 = p1->pNext;
	}
	p1 = pOrder;
	while(p1 != NULL)
	{
		n1 ++;
		n2 = n1;
		while(p2->pNext != NULL)
		{
			n2++;
			p2 = p2->pNext; 
			if(strcmp(p1->name, p2->name) == 0)
			{
				Bill_delete(pOrder, n2);
				p1->n ++;
			}
		}
		p1 = p1->pNext;
		p2 = p1;
	}
}

DISH *Bill_delete(DISH *pOrder, int n)//�˲�
{
	DISH  *pr, *p;
	int i;
	p = pOrder;
	for(i = 1; i < n - 1; i++)
		p = p->pNext;
	if(n == 1)//ɾ��ͷ�ڵ� 
	{
		pOrder = p->pNext;
		free(p);
	}
	else
	{
		pr = p->pNext;
		p->pNext = pr->pNext;
		free(pr);
	}
	return pOrder;
}

DISH *Read(DISH *pHead)//��ȡ�ļ� 
{
	DISH *p = pHead;
	DISH *pNew = NULL;
	FILE *fp;
	int n = 0, i;
	if((fp = fopen("D:\\devcpp\\����ϵͳ\\DISH.txt", "r")) == NULL)
	{
		printf("���ļ�ʧ�ܣ�");
		exit(0);
	}
	fscanf(fp, "%d\n", &n);
//	printf("%d", n); 
	for(i = 0; i < n; i ++)
	{
		p = pHead;
		pNew = NULL;
		pNew = (DISH *)malloc(sizeof(DISH));
		if(pNew==NULL)
		{
			printf("�ڴ治�㣡");
			exit(0);
		 } 
		//ָ����һ��ָ���
		pNew->pNext = NULL;
		//���������β���
		while (pHead != NULL && p->pNext != NULL)
		{
			p = p->pNext;
		}
		
		//¼���Ʒ��Ϣ
		fscanf(fp, "%s %s %f %d\n", pNew->kind, pNew->name, &pNew->charge, &pNew->num);
		pNew->n = 1; 
		
		//�ѽڵ�嵽�����β�ڵ�
		if (pHead == NULL) 
		{
			pHead = pNew;
		}
		else 
		{
			p->pNext = pNew;
		}
	}
	fclose(fp);
	return pHead;
}

void Write(DISH *pHead)//д���ļ� 
{
	system("cls");
	FILE *fp;
	if((fp = fopen("D:\\devcpp\\����ϵͳ\\DISH.txt", "w")) == NULL)
	{
		printf("����ʧ�ܣ�");
		exit(0);
	}
	int n = 0, i;
	DISH *p = pHead;
	while(p != NULL)//�����Ʒ���� 
	{
		n++;
		p = p->pNext;
	}
	p = pHead;
	fprintf(fp, "%d\n", n);
	for(i = 0; i < n; i ++)
	{
		fprintf(fp, "%s %s %.2f %d\n", p->kind, p->name, p->charge, p->num);
		p = p->pNext;
	}
	fclose(fp);
	printf("����ɹ���\n");
	usleep(500000);
	system("cls");
} 
