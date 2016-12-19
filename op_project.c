#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

// Программа обработки списка, в которой используется массив структур. МАГАЗИН АВТОЗАПЧАСТЕЙ
#define MAX 100
#define LEN 15
int ger = 0, cursorLarge = 0, cursorSmall = 0, wheat = 0;
// Структура для товарной единицы
struct item {
		char type[30]; // Тип товара
		char mark[30]; // Марка автомобиля
		char name[40]; // Название товара
		int have; // Количество штук в наличии
		int delivery; // Доставка в днях
		int price; // Цена в рублях
	} item_list[MAX];
	
	void init_list(void), enter(void);
	void delete(void), list(void);
	int menu_select(void), find_free(void);
	
// Главная функция
int main(void) {
	printf("МАГАЗИН АВТОЗАПЧАСТЕЙ\n\n");
	int circle;
	
	char choice;
	init_list(); // Инициализация массива структур
	for(;;) {
		choice = menu_select();
		switch(choice) {
			case 1: for(circle = 0; circle < MAX; circle++) //цикл для добавления 100 товаров из файлов
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

// Добавление товара в список
void enter(void)
 {
	int slot;
	char s[80];
	
	slot = find_free();

//Считывание данных из файлов и их запись в массив структур	
 int upload_files() {
 	
//Подгрузка файлов 	
char typesArray[LEN];
char marksArray[LEN]; 
char namesArray[LEN];
char stockArray[LEN];
char daysArray[LEN];
char pricesArray[LEN];
        FILE *fileTypes = fopen("types.txt", "r"); // файл с типами товаров
		FILE *fileMarks = fopen("marks.txt", "r"); // файл с марками авто
		FILE *fileNames = fopen("names.txt", "r"); // файл с наименованиями товаров
		FILE *fileStock = fopen("stock.txt", "r"); // файл с кол-вом в наличии
		FILE *fileDays = fopen("days.txt", "r"); // файл с днями по доставке
		FILE *filePrices = fopen("prices.txt", "r"); // файл с ценами		        
        if(fileTypes == NULL || fileMarks == NULL || fileNames == NULL || fileStock == NULL || fileDays == NULL || filePrices == NULL)  
		{puts("Возникла непредвиденная ошибка");}
        
// Условие, перемещающее внутренний указатель файлов для последовательного чтения строк	
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
			
			fgets(pricesArray, 5, filePrices);   
 			item_list[slot].price = strtoul(pricesArray, NULL, 10);
			  			
 		wheat=2; 
// С помощью переменной wheat программа определяет, какой тип таблицы выводить -
// после ручного ввода или считывания из файлов
        fclose(fileTypes);
 		return 0;
 }
	
upload_files();
	
 //Добавление товаров в массив структур вручную 
int hand_create() {
	printf("Введите тип товара: ");
	gets(item_list[slot].type);
	
	printf("Введите марку авто: ");
	gets(item_list[slot].mark);
	
	printf("Введите наименование товара: ");
	gets(item_list[slot].name);
	
	printf("Введите кол-во в наличии: ");
	gets(s);
	item_list[slot].have = strtoul(s, '\0', 10);
	
	printf("Введите дни на доставку: ");
	gets(s);
	item_list[slot].delivery = strtoul(s, '\0', 10);
	
	printf("Введите цену товара: ");
	gets(s);
	item_list[slot].price = strtoul(s, '\0', 10);
	return 0;
}

//hand_create();
}
// Поиск свободной структуры
int find_free(void) 
{
	register int t;
	
	for(t = 0; item_list[t].name[0] && t < MAX; ++t);
	
	if(t == MAX) return -1; // свободных структур нет
	return t;
}
// Удаление товара
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
{ 	if(wheat == 2) { // При считывании из файлов
	printf("\n№\tТип товара\t\tМарка авто\t\tНаименование товара\t\tЦена(руб.)\t\tВ наличии(шт)\t\tСроки доставки(дн)\n\n");
} else { // При вводе вручную
	printf("\n№\tТип товара\t\tМарка авто\t\tНаименование товара\t\tЦена(руб.)\t\tВ наличии(шт)\t\tСроки доставки(дн)\n\n");
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
