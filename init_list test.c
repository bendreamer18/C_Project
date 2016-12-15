#include <stdio.h>
#include <stdlib.h>
// Простой пример программы обработки списка, в которой используется массив структур

#define MAX 100
struct addr {
	char name[30];
	char street[40];
	char city[20];
	char state[3];
	unsigned long int zip;
} addr_list[MAX];

void init_list(void), enter(void);
void delete(void), list(void);
int menu_select(void), find_free(void);

// Главная функция
int main(void) {
	
	char choice;
	init_list(); // Инициализация массива структур
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
// Инициализация списка
void init_list(void)
 {
	register int t; //Регистрационная переменная
	for(t = 0; t < MAX; ++t) addr_list[t].name[0] = '\0';
}
// Получение значения выбранного меню
int menu_select(void)
 {
	char s[80];
	int c;
	
	printf("1. Добавить имя\n");
	printf("2. Удалить имя\n");
	printf("3. Вывести список\n");
	printf("4. Выход\n");
	do {
		printf("\n Введите номер нужного пункта: ");
		gets(s);
		c = atoi(s);
	} while (c < 0 || c > 4);
	return c;
}
// ВВод адреса в список
void enter(void)
 {
	int slot;
	char s[80];
	
	slot = find_free();
	
	if(slot==-1) {
		printf("\n Список заполнен");
		return; 
	}
	printf("Введите имя: ");
	gets(addr_list[slot].name);
	
	printf("Введите улицу: ");
	gets(addr_list[slot].street);
	
	printf("Введите город: ");
	gets(addr_list[slot].city);
	
	printf("Введите штат: ");
	gets(addr_list[slot].state);
	
	printf("Введите индекс: ");
	gets(s);
	addr_list[slot].zip = strtoul(s, '\0', 10);
}
// Поиск свободной структуры
int find_free(void) 
{
	register int t;
	
	for(t = 0; addr_list[t].name[0] && t < MAX; ++t);
	
	if(t == MAX) return -1; // свободных структур нет
	return t;
}
// Удаление адреса
void delete(void) 
{
	register int slot;
	char s[80];
	
	printf("Введите № записи: ");
	gets(s);
	slot = atoi(s);
	
	if(slot >= 0 && slot < MAX) 
	addr_list[slot].name[0] = '\0'; // Пустая строка
	}
	
// Вывод списка на экран
void list(void) 
{ 
	register int t;
	
	for(t = 0; t < MAX; ++t) {
		if(addr_list[t].name[0]) {
			printf("%s\t", addr_list[t].name);
			printf("%s\t", addr_list[t].street);
			printf("%s\t", addr_list[t].city);
			printf("%s\t", addr_list[t].state);
			printf("%lu\n\n", addr_list[t].zip);
		}
	}
	printf("\n\n");
}

