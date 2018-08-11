#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define print(INFO) printf("Print: %s.\n", INFO)
#define error(INFO) printf("Error: %s!\n", INFO)

#define LEN 5

struct Node
{
	int m_data;
	struct Node *pm_next;
};

typedef struct Node NODE, *P_NODE;

bool list_create(P_NODE);
bool list_destroy(P_NODE *);
bool list_traverse(P_NODE);
bool node_insert(P_NODE, int, int);
bool node_delete(P_NODE, int);
bool node_search(P_NODE, int);

bool is_null(P_NODE p_head)
{
	if(NULL==p_head)
	{
		error("is_null");
		return true;
	}
	return false;
}

bool list_init(P_NODE p_head, int length)
{
	if(is_null(p_head))
	{
		error("list_init");
		return false;
	}
	P_NODE p_tail = p_head;
	for(int i=0; i<length; i++)
	{
		P_NODE p_new = (P_NODE)malloc(sizeof(NODE));
		if(NULL==p_new)
		{
			error("list_init");
			return false;
		}
		p_new->m_data = i+1;
		p_new->pm_next = NULL;
		p_tail->pm_next = p_new;
		p_tail = p_new;
		p_head->m_data++;
	}
	print("list_init");
	return true;
}

bool list_clear(P_NODE p_head)
{
	P_NODE p_cursor = p_head;
	if(is_null(p_head))
	{
		error("list_clear");
		return false;
	}
	while(NULL!=p_head->pm_next)
	{
		p_cursor = p_head->pm_next;
		p_head->pm_next = p_cursor->pm_next;
		free(p_cursor);
	}
	p_head->m_data = 0;
	print("list_clear");
	return true;
}

int main(void)
{
	P_NODE my_list;
	
	list_create(my_list);
	list_init(my_list, LEN);
	list_traverse(my_list);
	node_search(my_list, LEN);
	node_delete(my_list, LEN);
	node_insert(my_list, LEN, LEN+1);
	list_destroy(&my_list);
	
	return 0;
}

bool list_create(P_NODE p_head)
{
	p_head = (P_NODE)malloc(sizeof(NODE));
	if(NULL==p_head)
	{
		error("list_create");
		return false;
	}
	else
	{
		p_head->m_data = 0;
		p_head->pm_next = NULL;
		print("list_create");
		return true;
	}
}

bool list_destroy(P_NODE *pp_head)
{
	P_NODE p_head = *pp_head;
	if(!list_clear(p_head))
	{
		error("list_destroy");
		return false;
	}
	free(p_head);
	*pp_head = NULL;
	print("list_destroy");
	return true;
}

bool list_traverse(P_NODE p_head)
{
	if(is_null(p_head))
	{
		error("list_traverse");
		return false;
	}
	P_NODE p_cursor = p_head->pm_next;
	int i = 0;
	while(NULL!=p_cursor)
	{
		i++;
		printf("L[%d]=%d\t", i, p_cursor->m_data);
		p_cursor = p_cursor->pm_next;
	}
	printf("LEN=%d\t", p_head->m_data);
	print("list_traverse");
	return true;
}

bool node_insert(P_NODE p_head, int index, int value)
{
	P_NODE p_cursor = p_head;
	for(int i=1; i<index && NULL!=p_cursor; i++)
	{
		p_cursor = p_cursor->pm_next;
	}
	if(NULL==p_cursor || index<1 || index>p_head->m_data+1)
	{
		error("node_insert, Invalid Index");
		return false;
	}
	P_NODE p_new = (P_NODE)malloc(sizeof(NODE));
	if(NULL==p_new)
	{
		error("node_insert");
		return false;
	}
	p_new->m_data = value;
	p_new->pm_next = p_cursor->pm_next;
	p_cursor->pm_next = p_new;
	p_head->m_data++;
	printf("L[%d]=%d\t", index, value);
	print("node_insert");
	return true;
}

bool node_delete(P_NODE p_head, int index)
{
	P_NODE p_cursor = p_head;
	for(int i=1; i<index && NULL!=p_cursor; i++)
	{
		p_cursor = p_cursor->pm_next;
	}
	if(NULL==p_cursor || index<1 || index>p_head->m_data)
	{
		error("node_delete, Invalid Index");
		return false;
	}
	P_NODE p_delete = p_cursor->pm_next;
	p_cursor->pm_next = p_delete->pm_next;
	printf("L[%d]=%d\t", index, p_delete->m_data);
	free(p_delete);
	p_delete = NULL;
	p_head->m_data--;
	print("node_delete");
	return true;
}

bool node_search(P_NODE p_head, int index)
{
	P_NODE p_cursor = p_head;
	for(int i=1; i<=index && NULL!=p_cursor; i++)
	{
		p_cursor = p_cursor->pm_next;
	}
	if(NULL==p_cursor || index<1 || index>p_head->m_data)
	{
		error("node_search, Invalid Index");
		return false;
	}
	printf("L[%d]=%d\t", index, p_cursor->m_data);
	print("node_search");
	return true;
}
