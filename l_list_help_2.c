#include "main.h"

/**
 * searchNode - searches linked list for string and
 * returns index
 * @head: pointer to head of list
 * @str: input string
 * Return: index of node with matching string
 */
int searchNode(l_list *head, char *str)
{
	register int _len = 0, index = 0, i;
	l_list *curr;
	char *tmp, *ptr;

	curr = head;
	while (curr)
	{
		ptr = _strchr(curr->string, '=');
		_len = ptr - curr->string;
		tmp = malloc(sizeof(char) * _len + 1);
		for (i = 0; i < _len; i++)
			tmp[i] = curr->string[i];
		tmp[i] = '\0';
		if (_strcmp(str, tmp) == 0)
		{
			free(tmp);
			return (index);
		}
		index++;
		curr = curr->next;
		free(tmp);
	}
	return (-1);
}

/**
 * convertToLL - generates a linked list of environ
 * variables
 * @array: input array of strings
 * Return: head of linked list
 */
l_list *convertToLL(char **array)
{
	register int i = 0;
	l_list *head;

	head = NULL;
	while (array[i])
	{
		addNodeEnd(&head, array[i]);
		i++;
	}
	return (head);
}

/**
 * addNodeAtIndex - add node at index with string
 * @head: double pointer to head
 * @index: index to add at
 * @str: string to add
 * Return: address of node added
 */
l_list *addNodeAtIndex(l_list **head, int index, char *str)
{
	register int i = 0;
	l_list *newNode, *curr;
	char *newStr;

	curr = *head;
	if (!str)
		return (NULL);
	newNode  = malloc(sizeof(l_list));
	if (!newNode)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	newStr = _strdup(str);
	if (!newStr)
	{
		free(newNode);
		perror("Malloc failed\n");
		exit(errno);
	}

	newNode->string = newStr;
	newNode->next = NULL;

	while (i < index - 1)
	{
		if (curr->next == NULL)
		{
			free(newNode);
			return (NULL);
		}
		curr = curr->next;
		i++;
	}
	newNode->next = curr->next;
	curr->next = newNode;
	return (newNode);
}

/**
 * getNodeAtIndex - returns the nth node of a listint_t linked list
 * @head: pointer to head of list
 * @index: index of value to be returned
 * Return: address of node at input index
 */
char *getNodeAtIndex(l_list *head, unsigned int index)
{
	register uint count = 0;
	l_list *curr;
	char *ptr;

	curr = head;
	while (curr)
	{
		if (count == index)
		{
			ptr = _strdup(curr->string);
			return (ptr);
		}
		count++;
		curr = curr->next;
	}
	return (NULL);
}
