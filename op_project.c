#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
// ��������� ��������� ������, � ������� ������������ ������ ��������.

#define MAX 100
#define LEN 50
// ��� ��������� ��� ������ ������ �������
struct item {
		char type[30]; // ��� ������
		char mark[30]; // ����� ����������
		char name[40]; // �������� ������
		int have; // ���������� ���� � �������
		int delivery; // �������� � ����
	} item_list[MAX];
	
	void init_list(void), enter(void);
	void delete(void), list(void);
	int menu_select(void), find_free(void);
	//char categories();
	
	// ������� �������
int main(void) {
	printf("������� �������������\n\n");
	
	char choice;
	init_list(); // ������������� ������� ��������
	for(;;) {
		choice = menu_select();
		switch(choice) {
			case 1: enter();
			break;
			case 2: delete();
			break;
			case 3: list();
			break;
			case 4: exit(0);
		}
	}
	return 0;
}
	
//	char categories() {
//		//��� ������� ������� ������ ��������� ��� ���������.
//		const cat_max = 6;
//		int z;
//		char category[cat_max][20];
//		
//		printf("��������� ��������� ������:\n\n");
//		
//		strcpy(category[1], "������������");
//		strcpy(category[2], "�������� �����");
//		strcpy(category[3], "�������� ������");
//		strcpy(category[4], "��������� � �������");
//		strcpy(category[5], "���� �����");
//		for(z = 1; z < cat_max; z++) {
//			printf("%d. %s\n", z, category[z]);
//		}
//		return 0;
//	}
	
// ������������� ������
void init_list(void)
 {
	register int t; //��������������� ����������
	for(t = 0; t < MAX; ++t) item_list[t].name[0] = '\0';
}
// ��������� �������� ���������� ����
int menu_select(void)
 {
	char s[80];
	int c;
	printf("\n ������������� ����:\n\n");
	printf("1. �������� �����\n");
	printf("2. ������� �����\n");
	printf("3. ������� �������� ������\n");
	printf("4. �����\n");
	do {
		printf("\n ������� ����� ������� ������: ");
		gets(s);
		c = atoi(s);
	} while (c < 0 || c > 4);
	return c;
}
//������� ���-�� ����� � �����
int sc(FILE *fd) {
    int result = 1;
    rewind(fd);
    while (!ferror(fd) && !feof(fd)) {
        if (fgetc(fd) == '\n') ++result;
    }
    return result;
}
// ���������� ������ � ������
void enter(void)
 {
	int slot;
	char s[80];
	
	slot = find_free();
	
// �������� � ���������� �����	
char cArray[LEN];
        FILE *pTextFile = fopen("sometext.txt", "r");
        if(pTextFile == NULL)
        {
          puts("�������� �������������� ������");
        }
        
//        sc(pTextFile) - ���������� ����� � �����

        	while(fgets(cArray, LEN, pTextFile) != NULL)
        {       	  
 			fgets(cArray, LEN, pTextFile);   
 			CharToOem(cArray, cArray);
//			 printf("%s", cArray); 
        }

        fclose(pTextFile);
	
	
	if(slot==-1) {
		printf("\n ������ ��������");
		return; 
	}
	printf("������� ��� ������: ");
	gets(item_list[slot].type);
	
	printf("\n������� ����� ����: ");
	gets(item_list[slot].mark);
	
	printf("������� ������������ ������: ");
	gets(item_list[slot].name);
	
	printf("������� ���-�� � �������(��): ");
	gets(s);
	item_list[slot].have = strtoul(s, '\0', 10);
	
	printf("������� ��� �� ��������: ");
	gets(s);
	item_list[slot].delivery = strtoul(s, '\0', 10);
}
// ����� ��������� ���������
int find_free(void) 
{
	register int t;
	
	for(t = 0; item_list[t].name[0] && t < MAX; ++t);
	
	if(t == MAX) return -1; // ��������� �������� ���
	return t;
}
// �������� ������
void delete(void) 
{
	register int slot;
	char s[80];
	
	printf("������� � ������: ");
	gets(s);
	slot = atoi(s);
	
	if(slot >= 0 && slot < MAX) 
	item_list[slot].name[0] = '\0'; // ������ ������
	}
// ����� ������ �� �����
void list(void) 
{ 
	printf("\n�\t��� ������\t����� ����\t������������ ������\t� �������(��)\t����� ��������(��)\n\n");
	register int t;
	
	for(t = 0; t < MAX; ++t) {
		if(item_list[t].name[0]) {
			printf("%d.\t", t);
			printf("%s\t\t", item_list[t].type);
			printf("%s\t\t", item_list[t].mark);
			printf("%s\t\t", item_list[t].name);
			printf("%d\t\t", item_list[t].have);
			printf("%d\t\t\n", item_list[t].delivery);
		}
	}
	printf("\n\n");
}
// Now we're gonna try to read arrays from some text files.     
