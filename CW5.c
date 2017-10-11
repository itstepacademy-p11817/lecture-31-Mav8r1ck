#include<stdio.h>

#include<stdlib.h>

#include<stdint.h>

#include<string.h>

void print_array(uint64_t size_column, char** a)

{

    for (uint64_t col = 0; col < size_column; col++)

    {
        printf("%s ", *(a+col));
    }

    printf("\n");

}

char** make_array(uint64_t size_column, uint64_t size_line)

{

    char** array = (char**)malloc(size_column * sizeof(char*));

    for (uint64_t i = 0; i < size_column; i++)

    {

        array[i] = (char*)malloc(size_line * sizeof(char));

        printf("Enter name:\n");
//		scanf_s("%s\0", *(array+i));
        gets(*(array+i));
    }

    return array;

}

void strcmp_sort(uint64_t size_column, char** a)

{
    char** temp = (char**)malloc(1 * sizeof(char*));
    temp[0] = (char*)malloc(15 * sizeof(char));
    for (uint64_t n = 0; n < 10; n++)
    {
        int b = 0;
        for (uint64_t col = 0; col < size_column-1 ; col++)
        {
            if (strcmp(*(a + col), *(a + col + 1)) > 0)
            {
                strcpy(*(temp + 0), *(a + col));
                strcpy(*(a + col), *(a + col + 1));
                strcpy(*(a + col + 1), *(temp + 0));
                b++;
            }
        }
        if (b == 0)
        {
            break;
        }
    }
    free(temp[0]);
    free(temp);
}

void free_function(uint64_t size_column, char** a)

{

    for (uint64_t i = 0; i < size_column; i++)

    {

        free(a[i]);

    }

    free(a);

}


uint64_t main()

{

    char **a;

    uint64_t size_column = 5;

    uint64_t size_line = 15;

    a = make_array(size_column, size_line);

    print_array(size_column, a);

    strcmp_sort(size_column, a);

    print_array(size_column, a);

    free_function(size_column, a);

//    system("pause");

    return 0;

}