#include"contact.h"

enum Option 
{
	Exit,Add,Del,Search,Modify,Print,Sort,DelAll
};
void menu()
{
	printf("*****************************\n");
	printf("*****   1.Add    2.Del  *****\n");
	printf("***** 3.Search 4.Modify *****\n");
	printf("*****  5.Print  6.Sort  *****\n");
	printf("***** 7.DelAll  0.Exit  *****\n");
	printf("*****************************\n");

}


int main()
{
	Contact contact;
	Initcontact(&contact);
	int input = 0;
	do {
		menu();
		printf("��ѡ��\n");
		scanf_s(" %d", &input);
		switch (input)
		{
		case Add:
			if (contact.capacity == 0)
			{
				Initcontact(&contact);
			}
			Addcontact(&contact);
			break;
		case Del:
			Delcontact(&contact);
			break;
		case Search:
			Searchcontact(&contact);
			break;
		case Modify:
			Modifycontact(&contact);
			break;
		case Print:
			Printcontact(&contact);
			break;
		case Sort:
			Sortcontact(&contact);
			break;
		case DelAll:
			DelAllcontact(&contact);
			break;
		case Exit:
			free(contact.information);
			contact.information = NULL;
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}