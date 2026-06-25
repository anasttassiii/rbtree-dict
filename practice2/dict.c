#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dict.h"


dict_t* dict_create(void) {
    dict_t* dict = malloc(sizeof(dict_t));
    if (dict == NULL) return NULL;

    dict->tree = rb_create();
    if (dict->tree == NULL) {
        free(dict);
        return NULL;
    }

    return dict;
}


void dict_free(dict_t* dict) {
    if (dict == NULL) return;
    rb_free(dict->tree);
    free(dict);
}

// ===== Вставка/обновление =====
void dict_put(dict_t* dict, int key, int value) {
    assert(dict != NULL);
    rb_insert(dict->tree, key, value);
}

// ===== Получение значения =====
bool dict_get(dict_t* dict, int key, int* value) {
    assert(dict != NULL);
    return rb_search(dict->tree, key, value);
}


bool dict_remove(dict_t* dict, int key) {
    assert(dict != NULL);
    return rb_delete(dict->tree, key);
}

// ===== Проверка наличия =====
bool dict_contains(dict_t* dict, int key) {
    assert(dict != NULL);
    return rb_search(dict->tree, key, NULL);
}


size_t dict_size(dict_t* dict) {
    assert(dict != NULL);
    return rb_size(dict->tree);
}

bool dict_is_empty(dict_t* dict) {
    assert(dict != NULL);
    return rb_is_empty(dict->tree);
}


void dict_print(dict_t* dict) {
    assert(dict != NULL);
    printf("Dictionary size: %zu\n", dict_size(dict));
    printf("Tree structure:\n");
    rb_print(dict->tree);
}

void dict_print_sorted(dict_t* dict) {
    assert(dict != NULL);
    printf("Sorted keys: ");
    rb_inorder(dict->tree, dict->tree->root);
    printf("\n");
}