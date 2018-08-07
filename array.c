#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Array
{
	int *pm_base;
	int m_length;
	int m_volume;
};

typedef struct Array ARRAY, *P_ARRAY;

bool array_create(P_ARRAY, int);
bool array_destroy(P_ARRAY);
bool array_traverse(P_ARRAY);
bool node_insert(P_ARRAY, int, int);
bool node_delete(P_ARRAY, int);
bool node_search(P_ARRAY, int);

bool is_empty(P_ARRAY p_array)
{
	if(0==p_array->m_length)
	{
		error("is_empty");
		return true;
	}
	return false;
}

bool array_init(P_ARRAY p_array)
{
	if(is_null(p_array))
	{
		error("array_init");
		return false;
	}
	for(int i=0; i<p_array->m_volume; i++)
	{
		p_array->pm_base[i] = i;
		p_array->m_length++;
	}
	print("array_init");
	return true;
}

int main(void)
{
	ARRAY my_array;
	return 0;
}
