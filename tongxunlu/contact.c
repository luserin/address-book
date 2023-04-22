#include"contact.h"
//动态
void Initcontact(Contact* contact)
{
	PepInfo* tmp = NULL;
	tmp=(PepInfo*)malloc(sizeof(PepInfo) * Info_Num);
	if (tmp != NULL)
	{
		contact->information = tmp;
		tmp = NULL;
	}
	else
	{
		perror("创建通讯录失败：");
		return;
	}
	contact->sz = 0;
	contact->capacity = Info_Num;
	memset(contact->information, 0, sizeof(PepInfo)*Info_Num);
	printf("通讯录创建成功！\n");
	/*初始化完成后加载文件中的通讯录*/
	Loadcontact(contact);
}
//静态
//void Initcontact(Contact* contact)
//{
//	memset(contact->information,0,sizeof(contact->information))	;
//	contact->sz = 0;
//}
int FindByName(Contact*contact)
{
	char name[NameSize] = {0};
	printf("请输入名字：\n");
	scanf("%s", name);
	for (int i = 0; i < contact->sz; i++) 
	{
		if (strcmp(name, contact->information[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void Checkcapacity(Contact*contact)
{
	if (contact->sz == contact->capacity)
	{
		PepInfo* tmp = NULL;
		tmp = (PepInfo*)realloc(contact->information, (contact->capacity + 2) * sizeof(PepInfo));
		if (tmp != NULL)
		{
			contact->information = tmp;
			memset(contact->information + contact->capacity, 0, sizeof(PepInfo) * Car_capicity);
			contact->capacity += 2;
			printf("扩容成功！\n");
			tmp = NULL;
		}
		else
		{
			perror("扩容失败：");
			return;
		}
	}
}
//动态

void Addcontact(Contact* contact)
{
	Checkcapacity(contact);
	printf("请输入要添加信息：\n");
	scanf(" %s", &(contact->information[contact->sz].name));
	scanf(" %d", &(contact->information[contact->sz].age));
	scanf(" %s", &(contact->information[contact->sz].sex));
	scanf(" %s", &(contact->information[contact->sz].tele));
	scanf(" %s", &(contact->information[contact->sz].addr));
	contact->sz++;
	printf("添加成功！\n");
}
//静态
//void Addcontact(Contact* contact)
//{
//	if (contact->sz == MaxSize)
//	{
//		printf("通讯录已满!\n");
//		return;
//	}
//	printf("请输入要添加信息：\n");
//	scanf(" %s", &(contact->information[contact->sz].name));
//	scanf(" %d", &(contact->information[contact->sz].age));
//	scanf(" %s", &(contact->information[contact->sz].sex));
//	scanf(" %s", &(contact->information[contact->sz].tele));
//	scanf(" %s", &(contact->information[contact->sz].addr));
//	contact->sz++;
//}
void Delcontact(Contact* contact)
{
	int ret = FindByName(contact);
	if (ret != -1)
	{
		for (int i = ret; i < contact->sz-1; i++)
		{
			contact->information[i]=contact->information[i + 1];
		}
		contact->sz--;
		printf("删除成功！\n");
	}
	else
		printf("要删除的联系人不存在\n");
}
void Searchcontact(Contact* contact)
{
	int ret = FindByName(contact);
	if (ret != -1)
	{
		printf("%-20s%-5s%-5s%-12s%-30s\n", "姓名", "年龄", "性别", "电话", "住址");
		printf("%-20s", &(contact->information[ret].name));
		printf("%-5d", (contact->information[ret].age));
		printf("%-5s", &(contact->information[ret].sex));
		printf("%-12s", &(contact->information[ret].tele));
		printf("%-30s\n", &(contact->information[ret].addr));
	}
	else
	{
		printf("要查找的联系人不存在！\n");
		return;
	}
}
void Modifycontact(Contact* contact)
{
	int ret=FindByName(contact);
	PepInfo modify = { {0},{0},{0},{0},{0} };
	if (ret != -1)
	{
		printf("已找到要修改的联系人\n");
		printf("请输入要修改的信息：\n");
		scanf("%s", modify.name);
		scanf("%d", &modify.age);
		scanf("%s", modify.sex);
		scanf("%s", modify.tele);
		scanf("%s", modify.addr);
		contact->information[ret] = modify;
		printf("修改成功！\n");
	}
	else
		printf("要修改的联系人不存在\n");
}
void Printcontact(Contact* contact)
{
	printf("%-20s%-5s%-5s%-12s%-30s\n", "姓名", "年龄", "性别", "电话", "住址");
	for (int i = 0; i < contact->sz; i++)
	{
		printf("%-20s", &(contact->information[i].name));
		printf("%-5d", (contact->information[i].age));
		printf("%-5s", &(contact->information[i].sex));
		printf("%-12s", &(contact->information[i].tele));
		printf("%-30s\n", &(contact->information[i].addr));
	}
}
int cmp1(const void* e1, const void* e2) 
{
	return strcmp((char*)e1 , (char*)e2);
}
int cmp2(const void* e1, const void* e2)
{
	return strcmp((char*)e2, (char*)e1);
}

void Sortcontact(Contact* contact)
{
	int n = 0;
	printf("请选择正序排序还是倒序排序：\n1：正序     0：倒序\n");
	scanf("%d", &n);
	if (n == 1)
	{
		qsort(&(contact->information->name), contact->sz, sizeof(contact->information[0]), cmp1);
		printf("排序成功\n");
	}
	else
	{
		qsort(&(contact->information->name), contact->sz, sizeof(contact->information[0]), cmp2);
		printf("排序成功\n");
	}
}
//动态
void DelAllcontact(Contact* contact)
{
	int n = 0;
	printf("请确认：\n,1:确认清除！    0：撤销操作！\n");
	scanf("%d", &n);
	if (n == 1)
	{
		contact->sz = 0;
		free(contact->information);
		contact->information = NULL;
		contact->capacity = 0;
		printf("清除完毕\n");
	}
	else
	{
		printf("撤销成功！\n");
		return;
	}
}
//静态
//void DelAllcontact(Contact* contact)
//{
//	int n = 0;
//	printf("请确认：\n,1:确认清除！    0：撤销操作！\n");
//	scanf("%d", &n);
//	if (n == 1)
//	{
//		contact->sz = 0;
//		printf("清除完毕\n");
//	}
//	else
//	{
//		printf("撤销成功！\n");
//		return;
//	}
//}
void Savecontact(Contact* contact)
{
	/*打开文件*/
	FILE* pf = fopen("contact.txt", "w");
	if (pf == NULL)
	{
		perror("Savecontact::fopen");
		return;
	}
	/*写数据*/
	int i = 0;
	for (i = 0; i < contact->sz; i++)
	{
		fwrite(&(contact->information[i]), sizeof(PepInfo), 1, pf);
	}
	/*关闭文件 */
	fclose(pf);
	pf = NULL;
	return;
}
void Loadcontact(Contact* contact)
{/*打开文件*/
	FILE* pf = fopen("contact.txt", "r");
	if (pf == NULL)
	{
		perror("Loadcontact::fopen");
		return;
	}
	/*读文件*/
	PepInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PepInfo), 1, pf))
	{
		Checkcapacity(contact);
		contact->information[contact->sz] = tmp;
		contact->sz++;
	}
	fclose(pf);
	pf = NULL;
}
