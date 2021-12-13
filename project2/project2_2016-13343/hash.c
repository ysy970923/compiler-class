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

/*
 * Function:  hash
 * --------------------
 *	simple hash function with using prime number 7, 31
 * 
 * 	name: token name
 *  length: token string length
 *
 *  returns: (unsigned type) hash value from given token name 
 */
unsigned hash(char *name, int length)
{
	int i;
	unsigned hash = 7;
	for (i = 0; i < length; i++)
	{
		hash = hash * 31 + name[i];
	}
	return hash;
}

/*
 * Function:  enter
 * --------------------
 *	enter token to hashTable:
 *		if token name already in hashTable: increment count value;
 *		else: add token to hashTable
 *
 * 	tokenType: type of token
 *  length: token string length
 *
 *  returns: the unsigned hash value from given token name 
 */
id *enter(int tokenType, char *name, int length)
{
	unsigned key = hash(name, length) % HASH_TABLE_SIZE;
	nlist *node = hashTable[key];
	while (node)
	{
		if (strcmp(node->data->name, name) == 0)
		{
			node->data->count++;
			return node->data;
		}
		else if (node->next) {
			node = node->next;
		}
		else
			break;
	}
	struct nlist *new_node = (struct nlist *)malloc(sizeof(struct nlist));
	new_node->data = (struct id *)malloc(sizeof(struct id));
	new_node->data->tokenType = tokenType;
	new_node->data->name = (char *)malloc(strlen(name) * sizeof(char));
	strcpy(new_node->data->name, name);

	if (!hashTable[key])
		hashTable[key] = new_node;
	else
		node->next = new_node;

	return new_node->data;
}