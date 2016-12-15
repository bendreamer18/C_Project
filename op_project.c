#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
// Программа обработки списка, в которой используется массив структур.

#define MAX 100
#define LEN 50
// Это структура для общего списка товаров
struct item {
		char type[30]; // Тип товара
		char mark[30]; // Марка автомобиля
		char name[40]; // Название товара
		int have; // Количество штук в наличии
		int delivery; // Доставка в днях
	} item_list[MAX];
	
	void init_list(void), enter(void);
	void delete(void), list(void);
	int menu_select(void), find_free(void);
	//char categories();
	
	// Главная функция
int main(void) {
	printf("МАГАЗИН АВТОЗАПЧАСТЕЙ\n\n");
	
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
	
//	char categories() {
//		//Эта функция выводит список категорий для запчастей.
//		const cat_max = 6;
//		int z;
//		char category[cat_max][20];
//		
//		printf("Доступные категории товара:\n\n");
//		
//		strcpy(category[1], "Аккумуляторы");
//		strcpy(category[2], "Машинные масла");
//		strcpy(category[3], "Кузовные детали");
//		strcpy(category[4], "Глушители и фаркопы");
//		strcpy(category[5], "Авто лампы");
//		for(z = 1; z < cat_max; z++) {
//			printf("%d. %s\n", z, category[z]);
//		}
//		return 0;
//	}
	
// Инициализация списка
void init_list(void)
 {
	register int t; //Регистрационная переменная
	for(t = 0; t < MAX; ++t) item_list[t].name[0] = '\0';
}
// Получение значения выбранного меню
int menu_select(void)
 {
	char s[80];
	int c;
	printf("\n Навигационное меню:\n\n");
	printf("1. Добавить товар\n");
	printf("2. Удалить товар\n");
	printf("3. Вывести товарный список\n");
	printf("4. Выход\n");
	do {
		printf("\n Введите номер нужного пункта: ");
		gets(s);
		c = atoi(s);
	} while (c < 0 || c > 4);
	return c;
}
//Считаем кол-во строк в файле
int sc(FILE *fd) {
    int result = 1;
    rewind(fd);
    while (!ferror(fd) && !feof(fd)) {
        if (fgetc(fd) == '\n') ++result;
    }
    return result;
}
// Добавление товара в список
void enter(void)
 {
	int slot;
	char s[80];
	
	slot = find_free();
	
// Работаем с подгрузкой файла	
char cArray[LEN];
        FILE *pTextFile = fopen("sometext.txt", "r");
        if(pTextFile == NULL)
        {
          puts("Возникла непредвиденная ошибка");
        }
        
//        sc(pTextFile) - количество строк в файле

        	while(fgets(cArray, LEN, pTextFile) != NULL)
        {       	  
 			fgets(cArray, LEN, pTextFile);   
 			CharToOem(cArray, cArray);
//			 printf("%s", cArray); 
        }

        fclose(pTextFile);
	
	
	if(slot==-1) {
		printf("\n Список заполнен");
		return; 
	}
	printf("Введите тип товара: ");
	gets(item_list[slot].type);
	
	printf("\nВведите марку авто: ");
	gets(item_list[slot].mark);
	
	printf("Введите наименование товара: ");
	gets(item_list[slot].name);
	
	printf("Введите кол-во в наличии(шт): ");
	gets(s);
	item_list[slot].have = strtoul(s, '\0', 10);
	
	printf("Введите дни на доставку: ");
	gets(s);
	item_list[slot].delivery = strtoul(s, '\0', 10);
}
// Поиск свободной структуры
int find_free(void) 
{
	register int t;
	
	for(t = 0; item_list[t].name[0] && t < MAX; ++t);
	
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
	item_list[slot].name[0] = '\0'; // Пустая строка
	}
// Вывод списка на экран
void list(void) 
{ 
	printf("\n№\tТип товара\tМарка авто\tНаименование товара\tВ наличии(шт)\tСроки доставки(дн)\n\n");
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
