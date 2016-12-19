#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

// ��������� ��������� ������, � ������� ������������ ������ ��������. ������� �������������
#define MAX 100
#define LEN 15
int ger = 0, cursorLarge = 0, cursorSmall = 0, wheat = 0;
// ��������� ��� �������� �������
struct item {
		char type[30]; // ��� ������
		char mark[30]; // ����� ����������
		char name[40]; // �������� ������
		int have; // ���������� ���� � �������
		int delivery; // �������� � ����
		int price; // ���� � ������
	} item_list[MAX];
	
	void init_list(void), enter(void);
	void delete(void), list(void);
	int menu_select(void), find_free(void);
	
// ������� �������
int main(void) {
	printf("������� �������������\n\n");
	int circle;
	
	char choice;
	init_list(); // ������������� ������� ��������
	for(;;) {
		choice = menu_select();
		switch(choice) {
			case 1: for(circle = 0; circle < MAX; circle++) //���� ��� ���������� 100 ������� �� ������
			enter();
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

// ���������� ������ � ������
void enter(void)
 {
	int slot;
	char s[80];
	
	slot = find_free();

//���������� ������ �� ������ � �� ������ � ������ ��������	
 int upload_files() {
 	
//��������� ������ 	
char typesArray[LEN];
char marksArray[LEN]; 
char namesArray[LEN];
char stockArray[LEN];
char daysArray[LEN];
char pricesArray[LEN];
        FILE *fileTypes = fopen("types.txt", "r"); // ���� � ������ �������
		FILE *fileMarks = fopen("marks.txt", "r"); // ���� � ������� ����
		FILE *fileNames = fopen("names.txt", "r"); // ���� � �������������� �������
		FILE *fileStock = fopen("stock.txt", "r"); // ���� � ���-��� � �������
		FILE *fileDays = fopen("days.txt", "r"); // ���� � ����� �� ��������
		FILE *filePrices = fopen("prices.txt", "r"); // ���� � ������		        
        if(fileTypes == NULL || fileMarks == NULL || fileNames == NULL || fileStock == NULL || fileDays == NULL || filePrices == NULL)  
		{puts("�������� �������������� ������");}
        
// �������, ������������ ���������� ��������� ������ ��� ����������������� ������ �����	
		if(ger == 0) {
			fseek( fileTypes , 0 , SEEK_SET);
			fseek( fileMarks , 0 , SEEK_SET);
			fseek( fileNames , 0 , SEEK_SET);
			fseek( fileStock , 0 , SEEK_SET);
			fseek( fileDays , 0 , SEEK_SET);
			fseek( filePrices , 0 , SEEK_SET); 
			ger+=2;
		}
			else if (ger != 0) {			
			fseek( fileTypes , cursorLarge+15 , SEEK_SET);
			fseek( fileMarks , cursorLarge+15 , SEEK_SET);
			fseek( fileNames , cursorLarge+15 , SEEK_SET);
			fseek( fileStock , cursorSmall+5 , SEEK_SET);
			fseek( fileDays , cursorSmall+5 , SEEK_SET);
			fseek( filePrices , cursorSmall+3 , SEEK_SET);
			cursorLarge+=15;
			cursorSmall+=5;
			}
	if(slot==-1) {printf("\n ������ ��������"); return;}
	
		
 			fgets(typesArray, 15, fileTypes);   
 			CharToOem(typesArray, typesArray); 
			strcpy(item_list[slot].type , typesArray);		
			
			fgets(marksArray, 15, fileMarks);   
			CharToOem(marksArray, marksArray); 
			strcpy(item_list[slot].mark , marksArray);	
			
			fgets(namesArray, 15, fileNames);   
 			CharToOem(namesArray, namesArray); 
			strcpy(item_list[slot].name , namesArray);
			
			fgets(stockArray, 5, fileStock);   
 			item_list[slot].have = strtoul(stockArray, NULL, 10);
 			
 			fgets(daysArray, 5, fileDays);   
 			item_list[slot].delivery = strtoul(daysArray, NULL, 10);
			
			fgets(pricesArray, 5, filePrices);   
 			item_list[slot].price = strtoul(pricesArray, NULL, 10);
			  			
 		wheat=2; 
// � ������� ���������� wheat ��������� ����������, ����� ��� ������� �������� -
// ����� ������� ����� ��� ���������� �� ������
        fclose(fileTypes);
 		return 0;
 }
	
upload_files();
	
 //���������� ������� � ������ �������� ������� 
int hand_create() {
	printf("������� ��� ������: ");
	gets(item_list[slot].type);
	
	printf("������� ����� ����: ");
	gets(item_list[slot].mark);
	
	printf("������� ������������ ������: ");
	gets(item_list[slot].name);
	
	printf("������� ���-�� � �������: ");
	gets(s);
	item_list[slot].have = strtoul(s, '\0', 10);
	
	printf("������� ��� �� ��������: ");
	gets(s);
	item_list[slot].delivery = strtoul(s, '\0', 10);
	
	printf("������� ���� ������: ");
	gets(s);
	item_list[slot].price = strtoul(s, '\0', 10);
	return 0;
}

//hand_create();
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
{ 	if(wheat == 2) { // ��� ���������� �� ������
	printf("\n�\t��� ������\t\t����� ����\t\t������������ ������\t\t����(���.)\t\t� �������(��)\t\t����� ��������(��)\n\n");
} else { // ��� ����� �������
	printf("\n�\t��� ������\t\t����� ����\t\t������������ ������\t\t����(���.)\t\t� �������(��)\t\t����� ��������(��)\n\n");
}
	
	register int t;
	
	for(t = 0; t < MAX; ++t) {
		if(item_list[t].name[0]) {
			printf("%d.\t", t);
			if(wheat == 2) {
				printf("%s\t\t", item_list[t].type);
				printf("%s\t\t", item_list[t].mark);
				printf("%s\t\t\t", item_list[t].name);
				printf("%d\t\t", item_list[t].price);
				printf("%d\t\t\t", item_list[t].have);
				printf("%d\n", item_list[t].delivery); 
			}
			else if(wheat != 2){
				printf("%s\t\t\t", item_list[t].type);
				printf("%s\t\t\t", item_list[t].mark);
				printf("%s\t\t\t", item_list[t].name);
				printf("%d\t\t", item_list[t].price);
				printf("%d\t\t\t", item_list[t].have);
				printf("%d\n", item_list[t].delivery);
			}

		}
	}
}   
