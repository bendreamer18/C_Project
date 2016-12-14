#include <stdio.h>
#include <string.h>


const MAX = 100;
// Это структура для общего списка товаров
struct ben {
		char type[30]; // Тип товара
		int mark; // Марка автомобиля
		char name[40]; // Название товара
		int have; // Количество штук в наличии
		int delivery; // Доставка в днях
	};
	
	char categories() {
		//Эта функция выводит список категорий для запчастей.
		const cat_max = 6;
		int z;
		char category[cat_max][20];
		
		printf("Доступные категории товара:\n\n");
		
		strcpy(category[1], "Аккумуляторы");
		strcpy(category[2], "Машинные масла");
		strcpy(category[3], "Кузовные детали");
		strcpy(category[4], "Глушители и фаркопы");
		strcpy(category[5], "Авто лампы");
		for(z = 1; z < cat_max; z++) {
			printf("%d. %s\n", z, category[z]);
		}
		return 0;
	}


int main() {
	
	printf("МАГАЗИН АВТОЗАПЧАСТЕЙ\n\n");
	struct ben data;
	
	categories();
	
	// printf("Вот пример структуры.\n\n");
 	
	// 	gets(data.type);
	// 	printf( "The line entered was: %s\n", data.type);
 	// Считывает строку и записывает ее в переменную "Тип товара". 
 	// Использовать для функции добавления товара.
	
	
	return 0;
}
