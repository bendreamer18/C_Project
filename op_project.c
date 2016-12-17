#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//#include <string.h>

// ��������� ��������� ������, � ������� ������������ ������ ��������.

#define MAX 100
#define LEN 20
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
	
 //�������� � ���������� �����	
char typesArray[LEN];
char marksArray[LEN]; 
char namesArray[LEN];
char stockArray[LEN];
char daysArray[LEN];
        FILE *fileTypes = fopen("types.txt", "r"); // ���� � ������ �������
		FILE *fileMarks = fopen("marks.txt", "r"); // ���� � ������� ����
		FILE *fileNames = fopen("names.txt", "r"); // ���� � �������������� �������
		FILE *fileStock = fopen("stock.txt", "r"); // ���� � ���-��� � �������
		FILE *fileDays = fopen("days.txt", "r"); // ���� � ����� �� ��������
			        
        if(fileTypes == NULL)
        {
          puts("�������� �������������� ������");
        }
        
//        sc(fileTypes) - ���������� ����� � �����
		
		
       	while(fgets(typesArray, 6, fileTypes) != NULL)
{			
			
 			fgets(typesArray, 6, fileTypes);   
 			CharToOem(typesArray, typesArray); 
			strcpy(item_list[slot].type , typesArray);
			
			fgets(marksArray, 6, fileMarks);   
			CharToOem(marksArray, marksArray); 
			strcpy(item_list[slot].mark , marksArray);
			
			fgets(namesArray, 6, fileNames);   
 			CharToOem(namesArray, namesArray); 
			strcpy(item_list[slot].name , namesArray);
			
			fgets(stockArray, 6, fileStock);   
 			item_list[slot].have = strtoul(stockArray, NULL, 10);
 			
 			fgets(daysArray, 6, fileDays);   
 			item_list[slot].delivery = strtoul(daysArray, NULL, 10);
        }

        fclose(fileTypes);
	
	
	if(slot==-1) {
		printf("\n ������ ��������");
		return; 
	}
//	printf("������� ��� ������: ");
//	gets(item_list[slot].type);
//	
//	printf("������� ����� ����: ");
//	gets(item_list[slot].mark);
//	
//	printf("������� ������������ ������: ");
//	gets(item_list[slot].name);
//	
//	printf("������� ���-�� � �������: ");
//	gets(s);
//	item_list[slot].have = strtoul(s, '\0', 10);
//	
//	printf("������� ��� �� ��������: ");
//	gets(s);
//	item_list[slot].delivery = strtoul(s, '\0', 10);
//	 �������� ��� ����������
//	strcpy(item_list[slot].type , "Egzona");
//	printf("%s", item_list[slot].type);
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
			printf("%d\t", t);
			printf("%s\t\t", item_list[t].type);
			printf("%s\t\t", item_list[t].mark);
			printf("%s\t\t\t", item_list[t].name);
			printf("%d\t\t", item_list[t].have);
			printf("%d\n", item_list[t].delivery);
		}
	}
//	printf("\n\n");
}
// Now we're gonna try to read arrays from some text files.     
