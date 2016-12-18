#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
//#include <string.h>

// Программа обработки списка, в которой используется массив структур.

#define MAX 101
#define LEN 15
int ger = 0, cursorLarge = 0, cursorSmall = 0, wheat = 0;
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

//Функция для считывания данных из файлов и их запись в массив структур	
 int upload_files() {
 	
//Подгрузка файлов 	
char typesArray[LEN];
char marksArray[LEN]; 
char namesArray[LEN];
char stockArray[LEN];
char daysArray[LEN];
        FILE *fileTypes = fopen("types.txt", "r"); // файл с типами товаров
		FILE *fileMarks = fopen("marks.txt", "r"); // файл с марками авто
		FILE *fileNames = fopen("names.txt", "r"); // файл с наименованиями товаров
		FILE *fileStock = fopen("stock.txt", "r"); // файл с кол-вом в наличии
		FILE *fileDays = fopen("days.txt", "r"); // файл с днями по доставке		        
        if(fileTypes == NULL)  {puts("Возникла непредвиденная ошибка");}
        
//        sc(fileTypes) - количество строк в файле
		int m;
// Это условие перемещает внутренний указатель файлов для последовательного чтения строк	
		if(ger == 0) {
			fseek( fileTypes , 0 , SEEK_SET);
			fseek( fileMarks , 0 , SEEK_SET);
			fseek( fileNames , 0 , SEEK_SET);
			fseek( fileStock , 0 , SEEK_SET);
			fseek( fileDays , 0 , SEEK_SET); 
			ger+=2;
		}
			else if (ger != 0) {			
			fseek( fileTypes , cursorLarge+15 , SEEK_SET);
			fseek( fileMarks , cursorLarge+15 , SEEK_SET);
			fseek( fileNames , cursorLarge+15 , SEEK_SET);
			fseek( fileStock , cursorSmall+5 , SEEK_SET);
			fseek( fileDays , cursorSmall+5 , SEEK_SET);
			cursorLarge+=15;
			cursorSmall+=5;
			}
	if(slot==-1) {printf("\n Список заполнен"); return;}
	
		
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
 			
 		wheat+=2;
        fclose(fileTypes);
 		return 0;
 }
	
upload_files();
	
// Добавление товаров в массив структур вручную 
//	printf("Введите тип товара: ");
//	gets(item_list[slot].type);
//	
//	printf("Введите марку авто: ");
//	gets(item_list[slot].mark);
//	
//	printf("Введите наименование товара: ");
//	gets(item_list[slot].name);
//	
//	printf("Введите кол-во в наличии: ");
//	gets(s);
//	item_list[slot].have = strtoul(s, '\0', 10);
//	
//	printf("Введите дни на доставку: ");
//	gets(s);
//	item_list[slot].delivery = strtoul(s, '\0', 10);
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
{ 	if(wheat == 2) {
	printf("\n№\tТип товара\t\tМарка авто\tНаименование товара\t\tВ наличии(шт)\t\tСроки доставки(дн)\n\n");
} else {
	printf("\n№\tТип товара\t\t\tМарка авто\t\tНаименование товара\t\tВ наличии(шт)\t\tСроки доставки(дн)\n\n");
}
	
	register int t;
	
	for(t = 0; t < MAX; ++t) {
		if(item_list[t].name[0]) {
			printf("%d.\t", t);
			if(wheat == 2) {
				printf("%s\t", item_list[t].type);
				printf("%s\t", item_list[t].mark); //хуета с отступами при вызове функции
			}
			else {
				printf("%s\t\t\t", item_list[t].type);
				printf("%s\t\t\t", item_list[t].mark);
			}
			printf("%s\t\t\t", item_list[t].name);
			printf("%d\t\t\t", item_list[t].have);
			printf("%d\n", item_list[t].delivery);
		}
	}
//	printf("\n\n");
}
// Now we're gonna try to read arrays from some text files.     
