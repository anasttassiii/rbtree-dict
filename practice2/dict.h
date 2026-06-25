#ifndef DICT_H
#define DICT_H

#include <stdbool.h>
#include <stddef.h>
#include "rbtree.h"

// ===== Словарь (ассоциативный массив) =====
typedef struct {
    rb_tree_t* tree;
} dict_t;


dict_t* dict_create(void);
void dict_free(dict_t* dict);


void dict_put(dict_t* dict, int key, int value);
bool dict_get(dict_t* dict, int key, int* value);
bool dict_remove(dict_t* dict, int key);
bool dict_contains(dict_t* dict, int key);
size_t dict_size(dict_t* dict);
bool dict_is_empty(dict_t* dict);


void dict_print(dict_t* dict);
void dict_print_sorted(dict_t* dict);

#endif /* DICT_H */