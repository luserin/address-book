#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxSize 1000
#define NameSize 20
#define SexSize 5
#define TeleSize 12
#define AddrSize 30
#define Info_Num 3
#define Car_capicity 2
typedef struct PepInfo 
{
	char name[NameSize];
	int age;
	char sex[SexSize];
	char tele[TeleSize];
	char addr[AddrSize];
}PepInfo;
//¶¯Ì¬
typedef struct Contact
{
	PepInfo *information;
	int sz;
	int capacity ;
}Contact;

//¾²Ì¬
//typedef struct Contact 
//{
//	PepInfo information[MaxSize];
//	int sz;
//}Contact;
void Initcontact(Contact*contact);
void Addcontact(Contact* contact);
void Delcontact(Contact*contact);
void Searchcontact(Contact*contact);
void Modifycontact(Contact*contact);
void Printcontact(Contact*contact);
void Sortcontact(Contact*contact);
void DelAllcontact(Contact* contact);
