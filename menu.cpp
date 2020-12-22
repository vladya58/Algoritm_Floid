#include "header.h"
#include "main.h"
#include "menu.h"

int main(int argc, char* argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int begin;
	int n = 0;
	
	srand(time(NULL));

	bool exitPerformed = false;
	if (argc <= 3) {
		
		printf("Курсовая работа на тему «Реализация алгоритма Флойда» \n");
		printf("Выполнил студент группы 19ВВ3:\nЯцков В.В\n\n");
		printf("Вариант работы программы с помощью вызова параметров в командной строки \n\n");
		printf("Введите параметры в командной строке через пробел.\n");
		printf("Варианты параметров:\n");
		printf("Ориентированный граф - route.\n");
		printf("Неориентированный граф - nroute.\n");
		printf("Размер массива - укажите число.\n");
		printf("Вероятность появления ребра - укажите число.\n");
		printf("Максимальный вес ребра - укажите число.\n");

		exitPerformed = true;
	}



	if ((argc >= 4) && (strcmp(argv[1], "route") == 0)) {
		if (argc > 5) {
			printf("Слишком много параметров. Попробуйте снова!\n");
			return 1;
		}
		if (argv[2] != NULL) {
			n = atoi(argv[2]);
		}
		else if (n == 0) {
			printf("Число не обнаружено! Попробуйте снова!\n");
			return (0);
		}

		if (argv[3] != NULL) {
			ver = atoi(argv[3]);
		}
		else if (ver == 0) {
			printf("Число не обнаружено! Попробуйте снова!\n");
			return (0);
		}

		if (argv[4] != NULL) {
			max = atoi(argv[4]);
		}
		else if (max == 0) {
			printf("Число не обнаружено! Попробуйте снова!\n");
			return (0);
		}


		arr = dynamic(n);
		generate_typeV_route(arr, n,ver);
		printf("Матрица смежности взвешенного ориентированного графа:\n\n");
		print(arr, n);
		printf("Матрица кратчайших путей: \n");
		FLOID(arr, n);
		printf("Для перехода в режим работы консольного приложения программы введите 1\n");
		scanf("%d", &usl);
		if (usl == 1) {
			printf("Основная часть программы!");

		}
	}










	if ((argc >= 4) && (strcmp(argv[1], "nroute") == 0)) {
		if (argc > 5) {
			printf("Слишком много параметров(Больше 4). Попробуйте снова!\n");
			return 1;
		}
		if (argv[2] != NULL) {
			n = atoi(argv[2]);
		}
		else if (n == 0) {
			printf("Число не обнаружено! Попробуйте снова!\n");
			return (0);
		}

		if (argv[3] != NULL) {
			ver = atoi(argv[3]);
		}
		else if (ver == 0) {
			printf("Число не обнаружено! Попробуйте снова!\n");
			return (0);
		}

		if (argv[4] != NULL) {
			max = atoi(argv[4]);
		}
		else if (max == 0) {
			printf("Число не обнаружено! Попробуйте снова!\n");
			return (0);
		}

		arr = dynamic(n);
		generate_typenv(arr, n, ver);
		printf("Матрица смежности взвешенного неориентированного графа:\n\n");
		print(arr, n);
		printf("Матрица кратчайших путей: \n");
		FLOID(arr, n);
		printf("Для перехода в режим работы консольного приложения программы введите 1\n");
		scanf("%d", &usl);
		if (usl == 1) {
			printf("Основная часть программы!");

		}
	}



	unsigned int level = 1;
	while (exitPerformed == false) {

		srand(time(NULL));
		system("cls");
		switch (level)
			printf("\n\n\n");
		printf("Курсовая работа на тему «Реализация алгоритма Флойда» \n");
		printf("Выполнил студент группы 19ВВ3\n");
		printf("Яцков Владислав\n");
		printf("\n\n\n");
		printf("\t1) Создать массив рандомно\n");
		printf("\t2) Открыть массив из файла\n");
		printf("\t3) Создать массив вручную в консоли\n");
		printf("\t0) Завершить работу\n\n\n");
		printf("\tВыберите пункт: ");
		unsigned int item = 0;
		scanf("%u", &item);




		switch (item) {
		case 1: {

			f_output = fopen("output.txt", "w");
			fprintf(f_output, "Первоначальный массив полученный рандомно:\n");
			printf("Выберите размер массива:\n\n\n");
			scanf("%d", &n);
			
			num = (int*)malloc(n * sizeof(int));
			for (int i = 0; i < n; i++) {
				num[i] = 0;
			}

			arr = (int**)malloc(n * sizeof(int*));
			for (int i = 0; i < n; i++) arr[i] = (int*)malloc(n * sizeof(int));

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (j > i) {
						arr[i][j] = rand() % 256;
						arr[j][i] = arr[i][j];
					}
					else if (i == j) arr[i][j] = 0;
				}
			}
			printf("\nЗаданный массив: \n");
			printf("");


			for (int i = 0; i < n; i++) {


				for (int j = 0; j < n; j++) {


					printf("%d \t", arr[i][j]);
					fprintf(f_output, " %d", arr[i][j]);

				}
				printf("\n");
				fprintf(f_output, "\n");
			}
			{

				printf("Матрица кратчайших путей: \n");
				fprintf(f_output, "Матрица кратчайших путей: \n");
				FLOID(arr, n);
				for (int i = 0; i < n; i++) {

					for (int j = 0; j < n; j++) {

						fprintf(f_output, " %d", arr[i][j]);
					}

					fprintf(f_output, "\n");

				}

			}
			fclose(f_output);
			printf("\n\nДля возрата в главное меню нажмите 1\nДля завершения работы нажмите 0\n");
			scanf("%d", &usl);
			if (usl == 1) {
				break;

			}
			return (0);
		}

		case 2: {
			 
			f_input = fopen("input.txt", "r");
			f_output = fopen("output.txt", "w");
			fprintf(f_output, "Первоначальный массив полученный из файла:\n");
			// считывание данных с файла
			

				while ((fscanf(f_input, "%d", &s) != EOF)) {
					if (!f_input) break;
					m += 1;
				}
				rewind(f_input); // перематываем файл для повторного чтения
				n = sqrt(m);
				arr = dynamic(n);

				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						fscanf_s(f_input, "%d", &arr[i][j]);
					}
				}
				printf("Массив считан из файла.\n");
				print(arr, n);
				fclose(f_input);
				printf("Матрица кратчайших путей: \n");
				for (int i = 0; i < n; i++) {

					for (int j = 0; j < n; j++) {
						fprintf(f_output, " %d", arr[i][j]);
					}
					fprintf(f_output, "\n");
				}
				FLOID(arr, n);
				fprintf(f_output, "Матрица кратчайших путей: \n");
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {

						fprintf(f_output, " %d", arr[i][j]);
					}
					fprintf(f_output, "\n");
				}
			
			fclose(f_output);
			printf("\n\nДля возрата в главное меню нажмите 1\nДля завершения работы нажмите 0\n");
			scanf("%d", &usl);
			if (usl == 1) {
				break;

			}
			return (0);
		}

		case 3: {

			f_output = fopen("output.txt", "w");
			fprintf(f_output, "Первоначальный массив заданный в консоли:\n");
			printf("Количество вершин в графе > ");
			scanf("%d", &n);
			arr = (int**)malloc(n * sizeof(int*));
			for (int i = 0; i < n; i++) arr[i] = (int*)malloc(n * sizeof(int));
			printf("Введите элементы матрицы: \n");
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
				{
					printf("arr[%d][%d] > ", i + 1, j + 1);
					scanf("%d", &arr[i][j]);
				}
			printf("Заданная матрица:\n");
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					printf(" %d\t", arr[i][j]);
					fprintf(f_output, " %d", arr[i][j]);
				}
				printf("\n");
				fprintf(f_output, "\n");
			}
			printf("Матрица кратчайших путей: \n");
			FLOID(arr, n);
			fprintf(f_output, "Матрица кратчайших путей: \n");
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					fprintf(f_output, " %d", arr[i][j]);
				}
				fprintf(f_output, "\n");
			}
			fclose(f_output);
			printf("\n\nДля возрата в главное меню нажмите 1\nДля завершения работы нажмите 0\n");
			scanf("%d", &usl);
			if (usl == 1) {
				break;

			}
			return (0);
		}

		case 0:
			return(0);
		}
	}
}