/***************************************************************
 * File Name    : hash.c
 * Description
 *      This is an implementation file for the open hash table.
 *
 ****************************************************************/

#include "subc.h"

#define HASH_TABLE_SIZE 101

typedef struct nlist
{
	struct nlist *next;
	id *data;
} nlist;

static nlist *hashTable[HASH_TABLE_SIZE];

char *tokenType2Text(int tokenType)
{
	if (tokenType == KEYWORD)
		return "KEY";
	if (tokenType == IDENTIFIER)
		return "ID";
}

// hash function
unsigned hash(char *name, int length)
{
	unsigned hash = 7;
	for (int i = 0; i < strlen(name); i++)
	{
		hash = hash * 31 + name[i];
	}
	return hash;
}

id *enter(int tokenType, char *name, int length)
{
	/* implementation is given here */
	unsigned key = hash(name, length) % HASH_TABLE_SIZE;
	nlist *node = hashTable[key];
	while (node)
	{
		if (strcmp(node->data->name, name) == 0)
		{
			node->data->count++;
			return node->data;
		}
		if (node->next)
			node = node->next;
		else
			break;
	}
	struct nlist *new_node = (struct nlist *)malloc(sizeof(struct nlist));
	new_node->data = (struct id *)malloc(sizeof(struct id));
	new_node->data->tokenType = tokenType;
	new_node->data->name = (char *)malloc(strlen(name) * sizeof(char));
	strcpy(new_node->data->name, name);

	if (tokenType != KEYWORD)
		new_node->data->count++;

	if (!hashTable[key])
		hashTable[key] = new_node;
	else
		node->next = new_node;

	return new_node->data;
}