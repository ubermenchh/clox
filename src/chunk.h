#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
    OP_CONSTANT,
    OP_NIL,
    OP_TRUE,
    OP_FALSE,
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,
    OP_NOT,
    OP_NEGATE,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_JUMP_IF_FALSE,
    OP_JUMP,
    OP_PRINT,
    OP_POP,
    OP_GET_LOCAL,
    OP_SET_LOCAL,
    OP_GET_GLOBAL,
    OP_SET_GLOBAL,
    OP_DEFINE_GLOBAL,
    OP_LOOP,
    OP_CALL,
    OP_RETURN,
    OP_CLOSURE,
    OP_CLOSE_UPVALUE,
    OP_GET_UPVALUE,
    OP_SET_UPVALUE,
    OP_CLASS,
} OpCode;

typedef struct {
    int count;
    int capacity;
    uint8_t *code;
    int *lines;
    ValueArray constants;
} Chunk;

void init_chunk(Chunk *chunk);
void write_chunk(Chunk *chunk, uint8_t byte, int line);
int add_constant(Chunk *chunk, Value value);
void free_chunk(Chunk *chunk);

#endif