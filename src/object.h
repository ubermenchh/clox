#ifndef clox_object_h
#define clox_object_h

#include "common.h"
#include "chunk.h"
#include "value.h"

#define OBJ_TYPE(value) (AS_OBJ(value)->type)
#define IS_STRING(value) is_obj_type(value, OBJ_STRING)
#define IS_FUNCTION(value) is_obj_type(value, OBJ_FUNCTION)

#define AS_FUNCTION(value) ((ObjFunction*)AS_OBJ(value))
#define AS_STRING(value) ((ObjString*)AS_OBJ(value))
#define AS_CSTRING(value) (((ObjString*)AS_OBJ(value))->chars)

typedef enum {
    OBJ_FUNCTION,
    OBJ_STRING,
} ObjType;

struct Obj {
    ObjType type;
    struct Obj *next;
};

typedef struct {
    Obj obj;
    int arity; // number of arguments the function expects
    Chunk *chunk;
    ObjString *name; // function name
} ObjFunction;

struct ObjString {
    Obj obj;
    int length;
    char *chars;
    uint32_t hash;
};

ObjFunction *new_function();
ObjString *take_string(char *chars, int length);
ObjString *copy_string(const char *chars, int length);
void print_object(Value value);

static inline bool is_obj_type(Value value, ObjType type) {
    return IS_OBJ(value) && AS_OBJ(value)->type == type;
}

#endif