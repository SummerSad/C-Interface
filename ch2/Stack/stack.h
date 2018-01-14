#ifndef STACK_INCLUDED
#define STACK_INCLUDED

typedef struct Stack_T *pT;

extern pT Stack_new(void);
extern int Stack_empty(pT stk);
extern void Stack_push(pT stk, int x);
extern int Stack_pop(pT stk);
extern void Stack_free(pT *stk);

#endif
