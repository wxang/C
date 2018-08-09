#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define print(INFO) printf("Print: %s.\n", INFO)
#define error(INFO) printf("Error: %s!\n", INFO)

#define VOL 5

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

bool is_null(P_ARRAY p_array)
{
	if(NULL==p_array || NULL==p_array->pm_base)
	{
		error("is_null");
		return true;
	}
	return false;
}

bool is_full(P_ARRAY p_array)
{
	if(p_array->m_volume==p_array->m_length)
	{
		error("is_full");
		return true;
	}
	return false;
}

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

bool array_create(P_ARRAY p_array, int volume)
{
	p_array->pm_base = (int*)malloc(sizeof(int)*volume);
	if(NULL==p_array->pm_base)
	{
		error("array_create");
		return false;
	}
	else
	{
		p_array->m_volume = volume;
		p_array->m_length = 0;
		print("array_create");
		return true;
	}
}

bool array_destroy(P_ARRAY p_array)
{
	if(is_null(p_array))
	{
		error("array_destroy");
		return false;
	}
	p_array->m_length = 0;
	p_array->m_volume = 0;
	free(p_array->pm_base);
	p_array->pm_base = NULL;
	print("array_destroy");
	return true;
}

bool array_traverse(P_ARRAY p_array)
{
	if(is_null(p_array))
	{
		error("array_traverse");
		return false;
	}
	for(int i=0; i<p_array->m_length; i++)
	{
		printf("A[%d]=%d\t", i, p_array->pm_base[i]);
	}
	print("array_traverse");
	return true;
}

bool node_insert(P_ARRAY p_array, int index, int value)
{
	if(is_full(p_array))
	{
		error("node_insert");
		return false;
	}
	if(index<0 || index>p_array->m_length)
	{
		error("node_insert, Invalid Index");
		return false;
	}
	for(int i=p_array->m_length; i>index; i--)
	{
		p_array->pm_base[i] = p_array->pm_base[i-1];
	}
	p_array->m_length++;
	p_array->pm_base[index] = value;
	printf("A[%d]=%d\t", index, value);
	print("node_insert");
	return true;
}

bool node_delete(P_ARRAY p_array, int index)
{
	if(!node_search(p_array, index))
	{
		error("node_delete");
		return false;
	}
	printf("A[%d]=%d\t", index, p_array->pm_base[index]);
	for(int i=index; i<(p_array->m_length-1); i++)
	{
		p_array->pm_base[i] = p_array->pm_base[i+1];
	}
	p_array->m_length--;
	p_array->pm_base[p_array->m_length] = 0;
	print("node_delete");
	return true;
}
