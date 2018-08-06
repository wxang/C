#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Array
{
	int *pm_base;
	int m_length;
	int m_volume;
}ARRAY,*P_ARRAY;

bool array_create(P_ARRAY, int);
bool array_destroy(P_ARRAY);
bool array_traverse(P_ARRAY);
bool node_insert(P_ARRAY, int, int);
bool node_delete(P_ARRAY, int);
bool node_search(P_ARRAY, int);

int main(void)
{
	ARRAY my_array;
	return 0;
}
