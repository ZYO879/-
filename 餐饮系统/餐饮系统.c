/*餐饮系统*/ 
//1.添加菜品（菜品名、价格、类型） 
//2.展示菜单 
//3.选择菜品分类并查看子菜单 （输出头像） 
//4.删除菜品 
//5.点菜 
//6.排序
//7.查看菜品 
//8.修改菜品 
//9.结账 
 
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>

typedef struct dishes//定义菜品结构体
{
	char kind[20]; 
	char name[30];
	float charge;
	int num;
	int n; 
	struct dishes *pNext;
} DISH;

DISH *Read(DISH *pHead);//读取文件 

void Show();//开机动画 

void Function_Menu();//打印功能菜单 

DISH *Add(DISH *pHead);//添加菜品 

DISH *Menu(DISH *pHead, DISH *pOrder);//打印菜单 

DISH *Delete(DISH *pHead);//删除菜品

void Change(DISH *pHead);//修改菜品 

void Sort_choose(DISH *pHead); //排序方式选择

void Name_sort(DISH *pHead);//按菜名排序 

void Charge_sort(DISH *pHead, char c);//按价格排序 

DISH *Order(DISH *pOrder, DISH *pHead);//点菜 

DISH *Bill(DISH *pOrder, DISH *pHead);//订单

void Arrange(DISH *pOrder);//整理订单 

DISH *Bill_delete(DISH *pOrder, int n);//退菜 

void Write(DISH *pHead);//写入文件 

int main()//主函数 
{	
	system("title 餐饮系统V4.0");//控制台标题 
	char c;
	DISH *pHead = NULL;
	DISH *pOrder = NULL;
	pHead = Read(pHead); 
	Show(); 
	system("pause");
	system("cls");
	
	while(1)//功能选择 
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
				printf("是否保存本次菜品修改(Y/N)\n");
				char cc = getch();
				if(cc == 'Y'||cc == 'y')
					Write(pHead);
				printf("感谢使用！"); 
				usleep(500000);
				return 0; 
				break;
			default: system("cls"); break;	
		}
	}
	return 0;
}

void Show()//开机动画 
{

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t欢迎使用餐饮系统4.0~\n");
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
	printf("\t\t\t\t\t      (\\@@@@@@@@@@@@@@@@@@@@@@@@/)\n\n\n\n\t\t\t\t\t\t◎");
}

void Function_Menu()//打印功能菜单 
{
	printf("\n\n\n\n");
	printf("\t\t\t\t                 ╭════════════════╮                 \n");
	printf("\t\t\t\t╭════════════════╣  餐饮系统V4.0  ╠════════════════╮\n");
	printf("\t\t\t\t║                ╰════════════════╯                ║\n");
	printf("\t\t\t\t║     【1】添加菜品             【2】删除菜品      ║\n");
	printf("\t\t\t\t║                                                  ║\n");
	printf("\t\t\t\t║     【3】修改菜品             【4】菜单排序      ║\n");
	printf("\t\t\t\t║                                                  ║\n");
	printf("\t\t\t\t║     【5】点菜                 【6】查看订单      ║\n");
	printf("\t\t\t\t║                                                  ║\n");
	printf("\t\t\t\t║     【7】展示菜单             【8】退出系统      ║\n");
	printf("\t\t\t\t║                                                  ║\n");
	printf("\t\t\t\t╰══════════════════════════════════════════════════╯\n");
	printf("\t\t\t\t\t◎请输入功能前的序号执行相应的功能:");
}


DISH *Add(DISH *pHead)//添加菜品 
{
	system("cls"); 
	DISH *pNew = (DISH *)malloc(sizeof(DISH));
	if(pNew==NULL)
	{
		printf("内存不足！");
		exit(0);
	 } 
	//指针下一个指向空
	pNew->pNext = NULL;
	//查找链表的尾结点
	DISH *p = pHead;
	while (pHead != NULL && p->pNext != NULL)
	{
		p = p->pNext;
	}
	//把节点插到链表的尾节点
	if (pHead == NULL) 
	{
		pHead = pNew;
	}
	else 
	{
		p->pNext = pNew;
	}

	//录入菜品信息
	printf("请输入菜品类别：\n");
	scanf("%s", &pNew->kind);
	printf("请输入菜名：\n");
	scanf("%s", &pNew->name);
	printf("请输入价格：\n");
	scanf("%f", &pNew->charge);
	pNew->n = 1; 
	getchar();
	printf("菜品信息录入成功！\n是否继续录入？（Y/N）\n");
	char c = getch();
	if(c=='Y'||c=='y')
		Add(pHead);
	system("cls");
	return pHead;
}

DISH *Menu(DISH *pHead, DISH *pOrder)//打印菜单 
{
	int i = 0;
	system("cls");
	DISH *p = pHead;
	if (p == NULL) 
	{
		printf("系统中暂无菜品信息，请录入后再来打印查看。\n\n");
	}
	else 
	{
		printf("\t\t\t\t*********************************************************\n");
		printf("\t\t\t\t*\t\t  欢迎光临欧记餐饮  \t\t\t*\n");
		printf("\t\t\t\t*********************************************************\n");
		printf("\t\t\t\t*\t菜名\t\t    类别\t价格\t\t*\n");
		printf("\t\t\t\t*********************************************************\n");
		while (p != NULL)
		{
			i++;
			p->num = i;
			printf("\t\t\t\t*\t%-5d%-15s%-6s\t￥%-8.2f\t*\n", i, p->name, p->kind, p->charge);
			p = p->pNext;
			printf("\t\t\t\t*********************************************************\n");
		}
		printf("\n\t\t\t\t\t\t  一共有%d道菜\n\n\n\t\t\t\t\t\t  ◎亲要点菜吗(Y/N)\n", i);
		char c = getch();
		if(c=='Y'||c=='y')
			pOrder = Order(pOrder, pHead);
		else
			system("pause");
	}
	system("cls");
	return pOrder;
}

void Change(DISH *pHead)//修改菜品 
{
	system("cls");
	DISH *p = pHead;
	if (p == NULL) 
	{
		printf("系统中暂无菜品信息！\n\n");
	}
	printf("请输入菜品序号（菜单中菜品对应序号）：");
	int n, i = 0;
	scanf("%d", &n);
	char c;
	while(p != NULL)//计算菜品总数 
	{
		i++;
		p = p->pNext;
	}
	if(i < n||n <=0)
		printf("该序号无对应菜品！\n");
	else
	{
		p = pHead;
		for(i = 1; i < n; i++)
		p = p->pNext;
step1:
		printf("请选择修改对象：\n1：菜名\n2：价格\n3：类别\n4：全部\n");
		c = getch();
		switch(c)
		{
			case '1': 
				system("cls");
				printf("请输入修改后的菜名：\n");
				scanf("%s", p->name);
				getchar();
				break;
			case '2': 
				system("cls");
				printf("请输入修改后的价格：\n");
				scanf("%f", &p->charge);
				break;
			case '3':
				system("cls");
				printf("请输入修改后的类别：\n");
				scanf("%s", p->kind);
				getchar();
				break;
			case '4': 
				system("cls");
				printf("请输入修改后的类别：\n");
				scanf("%s", p->kind);
				getchar();
				printf("请输入修改后的菜名：\n");
				scanf("%s", p->name);
				printf("请输入修改后的价格：\n");
				scanf("%f", &p->charge);
				break;
			default: 
				system("cls");
				goto step1;
				break;
		}
		system("cls");
		printf("菜品信息修改成功！\n");
	}
	system("pause");
	system("cls");
}

DISH *Delete(DISH *pHead)//删除菜品
{
	system("cls");
	DISH *p = pHead;
	if (p == NULL) 
	{
		printf("系统中暂无菜品信息！\n\n");
	}
	else
	{
		printf("请输入菜品序号：");
		int n, i = 0;
		scanf("%d", &n);
		DISH  *pr;
		while(p != NULL)//计算菜品总数 
		{
			i++;
			p = p->pNext;
		}
		p = pHead;
		if(i < n||n <=0)
			printf("该序号无对应菜品！\n");
		else
		{
			for(i = 1; i < n - 1; i++)
				p = p->pNext;
			if(n == 1)//删除头节点 
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
			printf("删除成功！\n");
		}
	}
	system("pause");
	system("cls");
	return pHead;
}

void Sort_choose(DISH *pHead)//排序方式选择 
{
step3:
	system("cls");
	DISH *p = pHead;
	if (p == NULL) 
	{
		printf("系统中暂无菜品信息！\n\n");
		system("pause");
		system("cls"); 
	}
	else
	{ 
		printf("\n\n\n\n");
		printf("\t\t\t\t                 ╭════════════════╮                 \n");
		printf("\t\t\t\t╭════════════════╣    排序方式    ╠════════════════╮\n");
		printf("\t\t\t\t║                ╰════════════════╯                ║\n");
		printf("\t\t\t\t║     【1】按菜名排序           【2】按价格升序    ║\n");
		printf("\t\t\t\t║                                                  ║\n");
		printf("\t\t\t\t║     【3】按价格降序                              ║\n");
		printf("\t\t\t\t║                                                  ║\n");
		printf("\t\t\t\t╰══════════════════════════════════════════════════╯\n");
		printf("\t\t\t\t\t◎请输入序号选择相应的排序方式:");   
		char c = getch();
		switch(c)
		{
			case '1': Name_sort(pHead); break;
			case '2': 
			case '3': Charge_sort(pHead, c); break;
			default: goto step3; break;
		}
		printf("排序成功！\n请打开菜单查看。");
		system("pause");
		system("cls"); 
	} 
}

void Name_sort(DISH *pHead)//按菜名排序 
{
	system("cls");
	int n = 0, i, j;
	float t;
	DISH *p = pHead;
	char a[30], b[20];
	while(p != NULL)//计算菜品总数 
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

void Charge_sort(DISH *pHead, char c)//按价格排序 
{
	DISH *p = pHead;
	int n = 0, i, j;
	float t;
	char a[30], b[20];
		while(p != NULL)//计算菜品总数 
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

DISH *Order(DISH *pOrder, DISH *pHead)//点菜
{
	system("cls"); 
	int n, i;
	DISH *po = pOrder;
	DISH *ph = pHead;
	//录入菜品到账单 
	printf("请输入菜品序号：\n");
	scanf("%d", &n);
	while(ph != NULL)//计算菜品总数 
	{
		i++;
		ph = ph->pNext;
	}
	ph = pHead;
	if(i < n||n <=0)
		printf("该序号无对应菜品！\n");
	else
	{
		for(i = 1; i < n; i++)
			ph = ph->pNext;
		DISH *pNew = (DISH *)malloc(sizeof(DISH));
		if(pNew==NULL)
		{
			printf("内存不足！");
			exit(0);
		} 
		//指针下一个指向空
		pNew->pNext = NULL;
		//查找链表的尾结点
		while (pOrder != NULL && po->pNext != NULL)
		{
			po = po->pNext;
		}
		//把节点插到链表的尾节点
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
		printf("点菜成功！\n是否继续点菜？（Y/N）\n");
		char c = getch();
		if(c=='Y'||c=='y')
			Order(pOrder, pHead);
	}
	usleep(500000);
	system("cls");
	return pOrder;
}

DISH *Bill(DISH *pOrder, DISH *pHead)//订单 
{
	int i, j, n;
	float pay = 0.00; 
	system("cls");
	DISH *p = pOrder;
step4:
	if (p == NULL) 
	{
		printf("\n\n\n\n\n\n\n\t\t\t\t\t亲还没有点菜哦~请点菜后再来查看。\n\n\n\n");
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
		printf("\t\t\t\t*\t\t  欢迎光临欧记餐饮  \t\t\t*\n");
		printf("\t\t\t\t*********************************************************\n");
		printf("\t\t\t\t*\t菜名\t\t\t类别\t价格\t数量\t*\n");
		printf("\t\t\t\t*********************************************************\n");

		while (p != NULL)
		{
			i ++;
			n += p->n;
			pay += p->charge * p->n;
			printf("\t\t\t\t*\t%-5d%-15s%-6s\t￥%-8.2fx%-3d\t*\n", i, p->name, p->kind, p->charge, p->n);
			//下一个节点
			p = p->pNext;
			printf("\t\t\t\t*********************************************************\n");
		}
		printf("\n\t\t\t\t\t\t  一共有 %d 道菜\n\t\t\t\t\t\t  应支付  ￥%.2f\n\n\n", n, pay);
		printf("\t\t\t\t\t\t\t◎1：继续点菜\n\t\t\t\t\t\t\t◎2：退菜\n\t\t\t\t\t\t\t◎3：返回\n");
		char c = getch(); 
		switch(c)
		{
			case '1':
				pOrder = Order(pOrder, pHead);
				break;
			case '2':
				system("cls");
				printf("请输入菜品序号：");
				int n;
				scanf("%d", &n);
				if(i < n||n <=0)
				{
					printf("该序号无对应菜品！\n");
					sleep(1);
					system("cls");
				}
				else
				{
step5:
					system("cls");
					printf("亲确定要退订吗，这道菜老好吃了~(Y/N)\n");
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
						printf("亲要退几份呢\n");
						int a;
						scanf("%d", &a);
						if(a > p->n)
						{
							printf("亲没有点这么多菜哦~\n");
							system("pause");
							system("cls");
							goto step4;
						}
						else if(a <= 0)
						{
							printf("无效的指令！\n");
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
					printf("退订成功！\n");
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

void Arrange(DISH *pOrder)//整理订单 
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

DISH *Bill_delete(DISH *pOrder, int n)//退菜
{
	DISH  *pr, *p;
	int i;
	p = pOrder;
	for(i = 1; i < n - 1; i++)
		p = p->pNext;
	if(n == 1)//删除头节点 
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

DISH *Read(DISH *pHead)//读取文件 
{
	DISH *p = pHead;
	DISH *pNew = NULL;
	FILE *fp;
	int n = 0, i;
	if((fp = fopen("D:\\devcpp\\餐饮系统\\DISH.txt", "r")) == NULL)
	{
		printf("打开文件失败！");
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
			printf("内存不足！");
			exit(0);
		 } 
		//指针下一个指向空
		pNew->pNext = NULL;
		//查找链表的尾结点
		while (pHead != NULL && p->pNext != NULL)
		{
			p = p->pNext;
		}
		
		//录入菜品信息
		fscanf(fp, "%s %s %f %d\n", pNew->kind, pNew->name, &pNew->charge, &pNew->num);
		pNew->n = 1; 
		
		//把节点插到链表的尾节点
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

void Write(DISH *pHead)//写入文件 
{
	system("cls");
	FILE *fp;
	if((fp = fopen("D:\\devcpp\\餐饮系统\\DISH.txt", "w")) == NULL)
	{
		printf("保存失败！");
		exit(0);
	}
	int n = 0, i;
	DISH *p = pHead;
	while(p != NULL)//计算菜品总数 
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
	printf("保存成功！\n");
	usleep(500000);
	system("cls");
} 
