struct StackElement;

struct Stack 
{
	StackElement* head;
};

struct StackElement 
{
	char value;
	StackElement *next;
};

Stack *createStack();
void destroy(Stack *stack);
bool isEmpty(Stack *stack);
void push(Stack *stack, char value);
char top(Stack *stack);
char pop(Stack *stack);
