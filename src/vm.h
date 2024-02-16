#ifndef clox_vm_h
#define clox_vm_h

#include "object.h"
#include "table.h"
#include "chunk.h"
#include "value.h"

#define FRAMES_MAX 64
#define STACK_MAX (FRAMES_MAX * UINT8_COUNT)

typedef struct {
    ObjFunction *function;      // function itself
    uint8_t *ip;                // to store the return addresses (instruction pointer)
    Value *slots;               // points at the VM's value stack at the first slot a function can use
} CallFrame;

typedef struct {
    CallFrame frames[FRAMES_MAX];
    int frame_count;

    Value stack[STACK_MAX];
    Value *stack_top;
    Table globals;
    Table strings;
    Obj *objects;
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

extern VM vm;

void init_VM();
void free_VM();
InterpretResult interpret(const char *source);
void push(Value value);
Value pop();

#endif