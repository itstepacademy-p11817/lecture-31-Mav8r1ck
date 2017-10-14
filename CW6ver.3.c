#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<stdint.h>

/*
uint64_t* D_function(uint64_t* size, uint64_t* a, uint64_t temp)

{

    *size = *size + 1;

    uint64_t* y = realloc(a, *size * sizeof(uint64_t));

    printf("For add element enter number\n");

    y[*size - 1] = temp;

    return y;

}
*/

void print_matrix(int64_t size_column, int64_t size_line, int64_t** a)
{
    for (int64_t col = 0; col < size_column; col++)
    {
        for (int64_t line = 0; line < size_line; line++)
        {
            printf("%lli ", a[col][line]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_array(int64_t size, int64_t *array)
{
    for (int64_t st = 0; st < size; st++)
    {
        printf("%lli ", array[st]);
    }
    printf("\n\n");
}

void randomarray(int64_t size_line, int64_t* a)
{
    for (int64_t st = 0; st < size_line; st++)
    {
        a[st] = rand() % 100000-50000;
    }
}

int64_t** make_array(int64_t size_column, int64_t size_line)
{
    int64_t** array = (int64_t**)malloc(size_column * sizeof(int64_t*));
    for (int64_t i = 0; i < size_column; i++)
    {
        array[i] = (int64_t*)malloc(size_line * sizeof(int64_t));
        randomarray(size_line, array[i]);
    }
    return array;
}

void** add_same_elements(int64_t size_column, int64_t size_line, int64_t** a, int64_t** b, int64_t** c)
{
    int64_t size = 1;
    int64_t* array = (int64_t*)malloc(size * sizeof(int64_t));
    for (int64_t col_a = 0; col_a < size_column; col_a++)
    {
        for (int64_t line_a = 0; line_a < size_line; line_a++)
        {
            bool temp_b = false;
            bool temp_c = false;
            for (int64_t col_b = 0; col_b < size_column; col_b++)
            {
                for (int64_t line_b = 0; line_b < size_line; line_b++)
                {
                    if (a[col_a][line_a] == b[col_b][line_b])
                    {
                        temp_b = true;
                        break;
                    }
                }
                if (temp_b == true)
                {
                    break;
                }
            }
            if (temp_b == true)
            {
                for (int64_t col_c = 0; col_c < size_column; col_c++)
                {
                    for (int64_t line_c = 0; line_c < size_line; line_c++)
                    {
                        if (a[col_a][line_a] == c[col_c][line_c])
                        {
                            temp_c = true;
                            break;
                        }
                    }
                    if (temp_c == true)
                    {
                        break;
                    }
                }
            }
            if (temp_c == true)
            {
                bool temp_array = false;
                for (int64_t st = 0; st < size; st++)
                {
                    if (a[col_a][line_a] == array[st])
                    {
                        temp_array = true;
                        break;
                    }
                }
                if (temp_array == false)
                {
                    array[size - 1] = a[col_a][line_a];
                    size = size + 1;
                    array = realloc(array, size * sizeof(int64_t));
                }
            }
        }
    }
    printf("Same numbers for a, b, c:\n");
    print_array(size, array);
    free(array);
}



void** add_unique_elements(int64_t size_column, int64_t size_line, int64_t** a, int64_t** b, int64_t** c)
{
    int64_t size = 1;
    int64_t* array = (int64_t*)malloc(size * sizeof(int64_t));
    for (int64_t col_a = 0; col_a < size_column; col_a++)
    {
        for (int64_t line_a = 0; line_a < size_line; line_a++)
        {
            bool temp_b = false;
            bool temp_c = false;
            for (int64_t col_b = 0; col_b < size_column; col_b++)
            {
                for (int64_t line_b = 0; line_b < size_line; line_b++)
                {
                    if (a[col_a][line_a] == b[col_b][line_b])
                    {
                        temp_b = true;
                        break;
                    }
                }
                if (temp_b == true)
                {
                    break;
                }
            }
            if (temp_b == false)
            {
                for (int64_t col_c = 0; col_c < size_column; col_c++)
                {
                    for (int64_t line_c = 0; line_c < size_line; line_c++)
                    {
                        if (a[col_a][line_a] == c[col_c][line_c])
                        {
                            temp_c = true;
                            break;
                        }
                    }
                    if (temp_c == true)
                    {
                        break;
                    }
                }
            }
            if (temp_b == false && temp_c == false)
            {
                bool flag_new_array = false;
                for (int64_t st = 0; st < size; st++)
                {
                    if (a[col_a][line_a] == array[st])
                    {
                        flag_new_array = true;
                        break;
                    }
                }
                if (flag_new_array == false)
                {
                    array[size - 1] = a[col_a][line_a];
                    size = size + 1;
                    array = realloc(array, size * sizeof(int64_t));
                }
            }
        }
    }
    printf("Unique numbers for first entered matrix:\n");
    print_array(size, array);
    free(array);
}

void** add_same_elements_for_A_C(int64_t size_column, int64_t size_line, int64_t** a, int64_t** c)
{
    int64_t size = 1;
    int64_t* array = (int64_t*)malloc(size * sizeof(int64_t));
    for (int64_t col_a = 0; col_a < size_column; col_a++)
    {
        for (int64_t line_a = 0; line_a < size_line; line_a++)
        {
            bool temp_c = false;
            for (int64_t col_c = 0; col_c < size_column; col_c++)
            {
                for (int64_t line_c = 0; line_c < size_line; line_c++)
                {
                    if (a[col_a][line_a] == c[col_c][line_c])
                    {
                        temp_c = true;
                        break;
                    }
                }
                if (temp_c == true)
                {
                    break;
                }
            }
            if (temp_c == true)
            {
                bool temp_array = false;
                for (int64_t st = 0; st < size; st++)
                {
                    if (a[col_a][line_a] == array[st])
                    {
                        temp_array = true;
                        break;
                    }
                }
                if (temp_array == false)
                {
                    array[size - 1] = a[col_a][line_a];
                    size = size + 1;
                    array = realloc(array, size * sizeof(int64_t));
                }
            }
        }
    }
    printf("Same numbers for a, c:\n");
    print_array(size, array);
    free(array);
}

void** add_negative_elements(int64_t size_column, int64_t size_line, int64_t** a, int64_t** b, int64_t** c)
{
	int64_t size = 1;
	int64_t* array = (int64_t*)malloc(size * sizeof(int64_t));
	for (int64_t col_a = 0; col_a < size_column; col_a++)
	{
		for (int64_t line_a = 0; line_a < size_line; line_a++)
		{
			bool temp = false;
            if (a[col_a][line_a] >= 0)
            {
                temp = true;
                break;
            }
            if(temp==false)
			{
				bool temp_array = false;
				for (int64_t st = 0; st < size; st++)
				{
					if (a[col_a][line_a] == array[st])
					{
						temp_array = true;
						break;
					}
				}
				if (temp_array == false)
				{
					array[size - 1] = a[col_a][line_a];
					size = size + 1;
					array = realloc(array, size * sizeof(int64_t));
				}
			}
		}
	}
    for (int64_t col_b = 0; col_b < size_column; col_b++)
    {
        for (int64_t line_b = 0; line_b < size_line; line_b++)
        {
            bool temp = false;
            if (b[col_b][line_b] >= 0)
            {
                temp = true;
                break;
            }
            if(temp==false)
            {
                bool temp_array = false;
                for (int64_t st = 0; st < size; st++)
                {
                    if (b[col_b][line_b] == array[st])
                    {
                        temp_array = true;
                        break;
                    }
                }
                if (temp_array == false)
                {
                    array[size - 1] = b[col_b][line_b];
                    size = size + 1;
                    array = realloc(array, size * sizeof(int64_t));
                }
            }
        }
    }
    for (int64_t col_c = 0; col_c < size_column; col_c++)
    {
        for (int64_t line_c = 0; line_c < size_line; line_c++)
        {
            bool temp = false;
            if (c[col_c][line_c] >= 0)
            {
                temp = true;
                break;
            }
            if(temp==false)
            {
                bool temp_array = false;
                for (int64_t st = 0; st < size; st++)
                {
                    if (c[col_c][line_c] == array[st])
                    {
                        temp_array = true;
                        break;
                    }
                }
                if (temp_array == false)
                {
                    array[size - 1] = c[col_c][line_c];
                    size = size + 1;
                    array = realloc(array, size * sizeof(int64_t));
                }
            }
        }
    }
	printf("Negative numbers for a, b, c:\n");
	print_array(size, array);
	free(array);
}

void free_function(int64_t size_column, int64_t** a)
{
    for (int64_t i = 0; i < size_column; i++)
    {
        free(a[i]);
    }
    free(a);
}


int64_t main()
{

    int64_t **a;
    int64_t **b;
    int64_t **c;
    int64_t size_column = 0;

    int64_t size_line = 0;

    printf("Enter size of column\n");

    scanf("%lli", &size_column);

    printf("Enter size of line\n");

    scanf("%lli", &size_line);

    srand(time(NULL));

    a = make_array(size_column, size_line);

    print_matrix(size_column, size_line, a);

    b = make_array(size_column, size_line);

    print_matrix(size_column, size_line, b);

    c = make_array(size_column, size_line);

    print_matrix(size_column, size_line, c);

    add_same_elements(size_column, size_line, a, b, c);

    add_unique_elements(size_column, size_line, a, b, c);
    add_unique_elements(size_column, size_line, b, a, c);
    add_unique_elements(size_column, size_line, c, a, b);

    add_same_elements_for_A_C(size_column, size_line, a, c);

    add_negative_elements(size_column, size_line, c, a, b);

    free_function(size_column, a);
    free_function(size_column, b);
    free_function(size_column, c);
    system("pause");

    return 0;

}