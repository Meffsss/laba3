#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <locale.h>
struct node
{
	char inf[256];  // полезная информация
	struct node* next; // ссылка на следующий элемент 
	struct node* prev; // ссылка на предыдущий элемент
};

struct node* head = NULL, * last = NULL, * f = NULL, * next = NULL; // указатели на первый и последний элементы списка
int n = 0;

// Функции добавления элемента, просмотра списка
void spstore(int k), review(void), del(char* name);
void pop_back(void);
char find_el[256];
struct node* find(char* name); // функция нахождения элемента
struct node* get_struct(int k); // функция создания элемента

int main()
{
	setlocale(0, "");
	printf("Введите кол-во элементов:");
	scanf("%d", &n);
	for (int k = 1; k <= n; k++)
	{
		spstore(k);
	};
	review();
	printf("\n\n");
	pop_back();
	printf("\n\n");
	review();

	return 0;

}
void pop_back(void)
{
	struct node* tmp = last;
	last = tmp->prev;
	last->next = NULL;
	printf("Последний элемент: %s\n", tmp->inf);
	free(tmp);
}
struct node* get_struct(int k)
{
	struct node* p = NULL;
	struct node* struc = head;
	char s[256];

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	printf("Введите название объекта: \n");   // вводим данные 
	scanf("%s", s);

	if (head != NULL)
	{

		for (int t = 0; t <= k; t++)
		{
			if ((strcmp(s, struc->inf))==0)
			{
				printf("Да ты че \n");
				system("pause");
				exit(1);
			}
			if (struc->next != NULL) 
			struc = struc->next;
		}
	}
	if (*s == 0)
	{
		printf("Запись не была произведена\n");
		return NULL;
	} \
		strcpy(p->inf, s);

	p->next = NULL;
	p->prev = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

/* Последовательное добавление в список элемента (в конец)*/
void spstore(int k)
{
	struct node* p = NULL;
	p = get_struct(k);
	if (head == NULL && p != NULL)	// если списка нет, то устанавливаем голову списка
	{
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) // список уже есть, то вставляем в конец
	{
		last->next = p;
		p->prev = last;
		last = p;
	}
	return;
}


/* Просмотр содержимого списка. */
void review(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	while (struc)
	{
		printf("Имя - %s, \n", struc->inf);
		struc = struc->next;
	}
	return;
}


/* Поиск элемента по содержимому. */
struct node* find(char* name)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
			return struc;
		}
		struc = struc->next;
	}
	printf("Элемент не найден\n");
	return NULL;
}
