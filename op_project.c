#include <stdio.h>
#include <string.h>


const MAX = 100;
// ��� ��������� ��� ������ ������ �������
struct ben {
		char type[30]; // ��� ������
		int mark; // ����� ����������
		char name[40]; // �������� ������
		int have; // ���������� ���� � �������
		int delivery; // �������� � ����
	};
	
	char categories() {
		//��� ������� ������� ������ ��������� ��� ���������.
		const cat_max = 6;
		int z;
		char category[cat_max][20];
		
		printf("��������� ��������� ������:\n\n");
		
		strcpy(category[1], "������������");
		strcpy(category[2], "�������� �����");
		strcpy(category[3], "�������� ������");
		strcpy(category[4], "��������� � �������");
		strcpy(category[5], "���� �����");
		for(z = 1; z < cat_max; z++) {
			printf("%d. %s\n", z, category[z]);
		}
		return 0;
	}


int main() {
	
	printf("������� �������������\n\n");
	struct ben data;
	
	categories();
	
	// printf("��� ������ ���������.\n\n");
 	
	// 	gets(data.type);
	// 	printf( "The line entered was: %s\n", data.type);
 	// ��������� ������ � ���������� �� � ���������� "��� ������". 
 	// ������������ ��� ������� ���������� ������.
	
	
	return 0;
}
