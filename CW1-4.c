#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdint.h>
#include<stdbool.h>


void print_array(uint64_t size_column, uint64_t size_line, uint64_t** a)
{
	for (uint64_t col = 0; col < size_column; col++)
	{
		for (uint64_t line = 0; line < size_line; line++)
		{
			printf("%llu ", a[col][line]);
		}
		printf("\n");
	}
	printf("\n");
}

void randomarray(uint64_t size_line, uint64_t* a)
{
	for (uint64_t st = 0; st < size_line; st++)
	{
		a[st] = rand() % 100;
	}
}

uint64_t** make_array(uint64_t size_column, uint64_t size_line)
{
	uint64_t** array = (uint64_t**)malloc(size_column * sizeof(uint64_t*));
	for (uint64_t i = 0; i < size_column; i++)
	{
		array[i] = (uint64_t*)malloc(size_line * sizeof(uint64_t));
		randomarray(size_line, array[i]);
	}
	return array;
}

uint64_t** add_line_to_end(uint64_t *size_column, uint64_t size_line, uint64_t** a)
{
	*size_column = (*size_column) + 1;
	uint64_t** array = (uint64_t**)realloc(a, (*size_column) * sizeof(uint64_t*));

		array[(*size_column)-1] = (uint64_t*)malloc(size_line * sizeof(uint64_t));
		randomarray(size_line, array[(*size_column)-1]);
	return array;
}

uint64_t** add_line_to_start(uint64_t *size_column, uint64_t size_line, uint64_t** a)
{
	*size_column = (*size_column) + 1;
	uint64_t** array = (uint64_t**)realloc(a, (*size_column) * sizeof(uint64_t*));
	for (uint64_t i = *(size_column)-1; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	array[0] = (uint64_t*)malloc(size_line * sizeof(uint64_t));

	randomarray(size_line, array[0]);
	return array;
}

void free_function(uint64_t size_column,uint64_t** a)
{
	for (uint64_t i = 0; i < size_column; i++)
	{
		free(a[i]);
	}
	free(a);
}
/*
uint64_t* D_function(uint64_t* size, uint64_t* a, uint64_t temp)
{
	*size = *size + 1;
	uint64_t* y = realloc(a, *size * sizeof(uint64_t));
	printf("For add element enter number\n");
	y[*size - 1] = temp;
	return y;
}

uint64_t* E_function(uint64_t* size, uint64_t* a, uint64_t temp, uint64_t index)
{
	*size = *size + 1;
	uint64_t* y = realloc(a, *size * sizeof(uint64_t));
	for (uint64_t i = (*size - 1); i >= index; i--)
	{
		y[i] = y[i - 1];
	}
	y[index] = temp;
	return y;
}

uint64_t* F_function(uint64_t* size, uint64_t* a, uint64_t index)
{
	for (uint64_t i = index; i < *size; i++)
	{
		a[i] = a[i + 1];
	}
	*size = *size - 1;
	uint64_t* y = realloc(a, *size * sizeof(uint64_t));
	return y;
}

*/

uint64_t main()
{
	uint64_t **a;
	uint64_t size_column = 0;
	uint64_t size_line = 0;
	printf("Enter size of column\n");
	scanf_s("%llu", &size_column);
	printf("Enter size of line\n");
	scanf_s("%llu", &size_line);
	srand(time(NULL));
	a = make_array(size_column, size_line);
	print_array(size_column, size_line, a);
	a = add_line_to_end(&size_column, size_line, a);
	print_array(size_column, size_line, a);
	a = add_line_to_start(&size_column, size_line, a);
	print_array(size_column, size_line, a);
	free_function(size_column, a);
/*
	randomarray(size, a);
	B_function(size, a);
	printf("For add element enter number\n");
	uint64_t temp = 0;
	scanf_s("%llu", &temp);
	a = D_function(&size, a, temp);
	B_function(size, a);
	printf("For add element enter number\n");
	scanf_s("%llu", &temp);
	printf("Enter index\n");
	uint64_t index = 0;
	scanf_s("%llu", &index);
	a = E_function(&size, a, temp, index);
	B_function(size, a);
	printf("For delete element enter index\n");
	scanf_s("%llu", &index);
	a = F_function(&size, a, index);
	B_function(size, a);
*/
	system("pause");
	return 0;
}