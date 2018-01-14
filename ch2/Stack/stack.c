#include "stack.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define T Stack_T

struct T {
	int count;
	struct elem {
		int x;
		struct elem *link;
	} * head;
};

pT Stack_new(void)
{
	pT stk = malloc(sizeof(struct T));
	stk->count = 0;
	stk->head = NULL;
	return stk;
}

int Stack_empty(pT stk)
{
	// assert check runtime error, halt if stk is 0
	assert(stk);
	return stk->count == 0;
}

void Stack_push(pT stk, int x)
{
	assert(stk);
	struct elem *t = malloc(sizeof(struct elem));
	t->x = x;
	// add head
	t->link = stk->head;
	stk->head = t;
	++stk->count;
}

int Stack_pop(pT stk)
{
	assert(stk);
	assert(stk->count > 0);
	struct elem *t = stk->head;
	stk->head = stk->head->link;
	--stk->count;
	int x = t->x;
	free(t);
	return x;
}

void Stack_free(pT *stk)
{
	assert(stk && *stk);
	struct elem *t, *u;
	for (t = (*stk)->head; t; t = u) {
		u = t->link;
		free(t);
	}
	free(*stk);
}

int main()
{
	pT S = Stack_new();
	printf("%d\n", Stack_pop(S));
	printf("%d\n", Stack_pop(S));
	Stack_free(&S);
	return 0;
}
