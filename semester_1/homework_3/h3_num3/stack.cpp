#include <stdlib.h>
#include <limits.h>
#include <iostream>

#include "stack.h"

using namespace std;

Stack *createStack()
{
	Stack *stack = new Stack;
	stack->head = NULL;
	return stack;
}

bool isEmpty(Stack *stack)
{
	return stack->head == NULL;
}

void destroy(Stack *stack)
{
	while (!isEmpty(stack))
	{
		pop(stack);
	}
}

char pop(Stack *stack)
{
	if (isEmpty(stack))
	{
		cout << "Stack is empty";
		return '0';
	}
	char result = top(stack);
	StackElement *tmp = stack->head;
	stack->head = stack->head->next;
	delete tmp;
	return result;
}

char top(Stack *stack)
{
	if (isEmpty(stack))
		{
			cout << "Stack is empty :(" << endl;
			return INT_MAX;
	}
	else
		return stack->head->value;
}

void push(Stack *stack, char value)
{
	StackElement *temp = new StackElement;
	temp->value = value;
	temp->next = stack->head;
	stack->head = temp; 
}
