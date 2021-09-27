/******************************************************
 * File Name   : subc.h
 * Description
 *    This is a header file for the subc program.
 ******************************************************/

#ifndef __SUBC_H__
#define __SUBC_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEYWORD 1
#define IDENTIFIER 2

typedef struct id {
	int tokenType;
	char *name;
	int count;
} id;

/* For hash table */
char* tokenType2Text(int tokenType);
unsigned hash(char *name);
id *enter(int tokenType, char *name, int length);

#endif