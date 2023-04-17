#include"contact.h"

void Initcontact(Contact* contact)
{
	memset(contact->information,0,sizeof(contact->information))	;
	contact->sz = 0;
}
int FindByName(Contact*contact)
{
	char name[NameSize] = {0};
	printf("���������֣�\n");
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
void Addcontact(Contact* contact)
{
	printf("�����룺\n");
	scanf(" %s", &(contact->information[contact->sz].name));
	scanf(" %d", &(contact->information[contact->sz].age));
	scanf(" %s", &(contact->information[contact->sz].sex));
	scanf(" %s", &(contact->information[contact->sz].tele));
	scanf(" %s", &(contact->information[contact->sz].addr));
	contact->sz++;
}
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
	}
	else
		printf("Ҫɾ������ϵ�˲�����\n");
}
void Searchcontact(Contact* contact)
{
	int ret = FindByName(contact);
	if (ret != -1)
	{
		printf("%-20s%-5s%-5s%-12s%-30s\n", "����", "����", "�Ա�", "�绰", "סַ");
		printf("%-20s", &(contact->information[ret].name));
		printf("%-5d", (contact->information[ret].age));
		printf("%-5s", &(contact->information[ret].sex));
		printf("%-12s", &(contact->information[ret].tele));
		printf("%-30s\n", &(contact->information[ret].addr));
	}
	else
	{
		printf("Ҫ���ҵ���ϵ�˲����ڣ�\n");
		return;
	}
}
void Modifycontact(Contact* contact)
{
	int ret=FindByName(contact);
	PepInfo modify = { {0},{0},{0},{0},{0} };
	if (ret != -1)
	{
		printf("���ҵ�Ҫ�޸ĵ���ϵ��\n");
		printf("������Ҫ�޸ĵ���Ϣ��\n");
		scanf("%s", modify.name);
		scanf("%d", &modify.age);
		scanf("%s", modify.sex);
		scanf("%s", modify.tele);
		scanf("%s", modify.addr);
		contact->information[ret] = modify;
	}
	else
		printf("Ҫ�޸ĵ���ϵ�˲�����\n");
}
void Printcontact(Contact* contact)
{
	printf("%-20s%-5s%-5s%-12s%-30s\n", "����", "����", "�Ա�", "�绰", "סַ");
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
	printf("��ѡ�����������ǵ�������\n1������     0������\n");
	scanf("%d", &n);
	if (n == 1)
	{
		qsort(&(contact->information->name), contact->sz, sizeof(contact->information[0]), cmp1);
		printf("����ɹ�\n");
	}
	else
	{
		qsort(&(contact->information->name), contact->sz, sizeof(contact->information[0]), cmp2);
		printf("����ɹ�\n");
	}
}
void DelAllcontact(Contact* contact)
{
	int n = 0;
	printf("��ȷ�ϣ�\n,1:ȷ�������    0������������\n");
	scanf("%d", &n);
	if (n == 1)
	{
		contact->sz = 0;
		printf("������\n");
	}
	else
	{
		printf("�����ɹ���\n");
		return;
	}
}