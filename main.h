#include "header.h"
#include "menu.h"

void FLOID(int** arr, int V) // Алгоритм Флойда
{

	int k;
	for (i = 0; i < V; i++) arr[i][i] = 0;

	for (k = 0; k < V; k++)
		for (i = 0; i < V; i++)
			for (j = 0; j < V; j++)
				if (arr[i][k] && arr[k][j] && i != j)
					if (arr[i][k] + arr[k][j] < arr[i][j] || arr[i][j] == 0)
						arr[i][j] = arr[i][k] + arr[k][j];

	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++) printf("%d\t", arr[i][j]);
		putchar('\n');

	}
}
int** dynamic(int count) // Создание динамического массива.
{

	int** mass;
	mass = (int**)malloc(count * sizeof(int*));
	for (int i = 0; i < count; i++) mass[i] = (int*)malloc(count * sizeof(int));
	return mass;
}
void print(int** mass, int count) //Вывод на экран 
{
	printf("");
	for (int i = 0; i < count; i++) {

		for (int j = 0; j < count; j++) {
			printf("%d \t", mass[i][j]);
		}
		printf("\n");
	}
}




void generate_typeV_route(int** mass, int count, int ver) { //взвешенный ориентированный

	int a; // вероятность
	int b;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			a = rand() % 101;
			if (a < ver) {
				mass[j][i] = rand() % max + 1;
				mass[i][j] = 0;
			}
			else mass[j][i] = 0;
			if (i == j) mass[j][i] = 0;

		}
	}

}
void generate_typenv(int** mass, int count, int ver) { // взвешенный неориентированный
	int a; // вероятность 
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			a = rand() % 101;
			if (a < ver) {
				mass[j][i] = rand() % max + 1;
				mass[i][j] = mass[j][i];
			}
			else
			{
				mass[j][i] = 0;
				mass[i][j] = 0;


			}
			if (i == j) mass[j][i] = 0;

		}
	}

}