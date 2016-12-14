#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// ���������� ���������
const int MAX = 100;
struct addr {
	char name[30];
	char street[40];
	char city[20];
	char state[3];
	unsigned long int zip;
}; addr_list[MAX];

// ������� init_list()
void init_list(void) {
	register int t; //��������������� ����������
	for(t = 0; t < MAX; ++t) addr_list[t].name[0] = '\0';
}
// ������� menu_select() ���������� �������� �� ����� 
int menu_select(void) {
	char s[80];
	int c;
	printf("1. �������� �����\n");
	printf("2. ������� �����\n");
	printf("3. ������� ������\n");
	printf("4. �����\n");
	
	do {
		printf("\n ������� ����� ������� ������");
		gets(s);
		c = atoi(s);
	} while (c < 0 || c > 4);
	return c;
}
// ������� enter() ��� ���������� ������ ������
void enter(void) {
	int slot;
	char s[80];
	slot = find_free();
	if(slot == -1) {
		printf("\n ������ ��������");
		return; 
	}
	printf("������� ���: ");
	gets(addr_list[slot].name);
	printf("������� �����: ");
	gets(addr_list[slot].street);
	printf("������� �����: ");
	gets(addr_list[slot].city);
	printf("������� ����: ");
	gets(addr_list[slot].state);
	printf("������� ������: ");
	gets(addr_list[slot].zip);
	gets(s);
	addr_list[slot].zip = strtoint(s, '\0', 10);
}
int find_free(void) {
	register int t;
	for(t = 0; addr_list[t].name[0] && t < MAX; ++t) 
	if(t == MAX) return -1;
}
void delete(void) {
	register int;
	char s[80];
	printf("������� � ������: ");
	gets(s);
	slot = atoi(s);
	if(slot >= 0 && slot < MAX) 
	addr_list[slot].name[0] = '\0'; // ������ ������
	}
}
// ������� list() ������� ������ ������ ���������
void list(void) { 
	register int t;
	for(t = 0; t < MAX; ++t) {
		if(addr_list[t].name[0]) {
			printf("%s\t", addr_list[t].name);
			printf("%s\t", addr_list[t].street);
			printf("%s\t", addr_list[t].city);
			printf("%s\t", addr_list[t].state);
			printf("%s\t", addr_list[t].zip);
		}
		printf("\n\n");
	}
}
// ������� �������
int main(void) {
	int choice;
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
