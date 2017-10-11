#include<stdio.h>

#include<stdlib.h>

#include<time.h>

#include <stdbool.h>

#include<stdint.h>


void print_array(int64_t size_column, int64_t size_line, int64_t** a)
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

void randomarray(int64_t size_line, int64_t* a)
{
    for (int64_t st = 0; st < size_line; st++)
    {
        a[st] = rand() % 50-25;
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
            int64_t temp = 0;
            for (int64_t col_b = 0; col_b < size_column; col_b++)
            {
                for (int64_t line_b = 0; line_b < size_line; line_b++)
                {
                    if(a[col_a][line_a]==b[col_b][line_b])
                    {
                        temp=b[col_b][line_b];
                        break;
                    }
                }
                if(a[col_a][line_a]==temp)
                {
                    break;
                }
            }
            for (int64_t col_c = 0; col_c < size_column; col_c++)
            {
                for (int64_t line_c = 0; line_c < size_line; line_c++)
                {
                    if(temp == c[col_c][line_c])
                    {
                        temp = c[col_c][line_c];
                        break;
                    }
                }
                if(a[col_a][line_a]==temp)
                {
                    break;
                }
            }
            int64_t temp_array = 0;
            for(int64_t st = 0; st < size; st++)
            {
                if (temp == array[st])
                {
                    temp_array++;
                    break;
                }
            }
            if (temp_array == 0)
            {
                array[size - 1] = temp;
                size = size + 1;
                array = realloc(array, size * sizeof(int64_t));
            }
        }
    }
    for (int64_t st = 0; st < size-1; st++)
    {
        printf("%lli ", array[st]);
    }
    printf("\n\n");
    free(array);
}

/*
void** add_unique_elements(int64_t size_column, int64_t size_line, int64_t** a, int64_t** b, int64_t** c)
{
    int64_t size = 1;
    int64_t* array = (int64_t*)malloc(size * sizeof(int64_t));
    for (int64_t col_a = 0; col_a < size_column; col_a++)
    {
        for (int64_t line_a = 0; line_a < size_line; line_a++)
        {
            int64_t temp = 0;
            for (int64_t col_b = 0; col_b < size_column; col_b++)
            {
                for (int64_t line_b = 0; line_b < size_line; line_b++)
                {
                    if(a[col_a][line_a]==b[col_b][line_b])
                    {
                        temp=b[col_b][line_b];
                        break;
                    }
                }
                if(a[col_a][line_a]==temp)
                {
                    break;
                }
            }
            for (int64_t col_c = 0; col_c < size_column; col_c++)
            {
                for (int64_t line_c = 0; line_c < size_line; line_c++)
                {
                    if(temp == c[col_c][line_c])
                    {
                        temp = c[col_c][line_c];
                        break;
                    }

                }
                if(a[col_a][line_a]==temp)
                {
                    break;
                }
            }
            int64_t temp_array = 0;
            for(int64_t st = 0; st < size; st++)
            {
                if (temp == array[st])
                {
                    temp_array++;
                    break;
                }
            }
            if (temp_array == 0)
            {
                array[size - 1] = temp;
                size = size + 1;
                array = realloc(array, size * sizeof(int64_t));
            }
        }
    }
    for (int64_t st = 0; st < size-1; st++)
    {
        printf("%lli ", array[st]);
    }
    printf("\n\n");
    free(array);
}
*/

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
    int64_t line = 0;
    int64_t size_column = 0;

    int64_t size_line = 0;

    printf("Enter size of column\n");

    scanf("%lli", &size_column);

    printf("Enter size of line\n");

    scanf("%lli", &size_line);

    srand(time(NULL));

    a = make_array(size_column, size_line);

    print_array(size_column, size_line, a);

    b = make_array(size_column, size_line);

    print_array(size_column, size_line, b);

    c = make_array(size_column, size_line);

    print_array(size_column, size_line, c);

    add_same_elements(size_column, size_line, a, b, c);

    free_function(size_column, a);

    free_function(size_column, b);

    free_function(size_column, c);
//    system("pause");

    return 0;

}