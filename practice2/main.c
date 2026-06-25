#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rbtree.h"
#include "dict.h"

// Тест для красно-черных деревьев
void test_rbtree(void) {
    printf("\n========== TEST 1: RED-BLACK TREE ==========\n\n");

    rb_tree_t* tree = rb_create();

    int keys[] = { 10, 20, 30, 40, 50, 25, 15, 12, 18, 35, 45, 5, 8 };
    int num = 13;

    printf("Inserting: ");
    for (int i = 0; i < num; i++) {
        printf("%d ", keys[i]);
        rb_insert(tree, keys[i], keys[i] * 10);
    }
    printf("\n\n");

    printf("Inorder traversal: ");     // вывод линейного обхода дерева
    rb_inorder(tree, tree->root);
    printf("\n\n");

    printf("Tree structure:\n");
    rb_print(tree);
    printf("\n");

    printf("Search tests:\n");
    for (int i = 0; i < num; i++) {
        int value;
        if (rb_search(tree, keys[i], &value)) {
            printf("  [OK] Key %d found (value = %d)\n", keys[i], value);
        }
    }

    int value;
    if (!rb_search(tree, 100, &value)) {
        printf("  [OK] Key 100 not found (correct)\n");
    }
    printf("\n");

    printf("Deleting keys: 20, 30, 40\n");
    rb_delete(tree, 20);
    rb_delete(tree, 30);
    rb_delete(tree, 40);

    printf("Inorder after deletion: ");
    rb_inorder(tree, tree->root);
    printf("\n");
    printf("Size: %zu\n", rb_size(tree));
    printf("\n");

    rb_free(tree);
}

// Тест для словаря 
void test_dict(void) {
    printf("\n========== TEST 2: DICTIONARY ==========\n\n");

    dict_t* dict = dict_create();

    printf("Inserting pairs (key -> value):\n");
    dict_put(dict, 1, 100);
    dict_put(dict, 2, 200);
    dict_put(dict, 3, 300);
    dict_put(dict, 4, 400);
    dict_put(dict, 5, 500);
    dict_put(dict, 3, 333);
    printf("  dict[3] updated to 333\n\n");

    printf("Getting values:\n");
    for (int i = 1; i <= 5; i++) {
        int value;
        if (dict_get(dict, i, &value)) {
            printf("  dict[%d] = %d\n", i, value);
        }
    }
    printf("\n");

    printf("Contains tests:\n");
    printf("  dict contains 3: %s\n", dict_contains(dict, 3) ? "yes" : "no");
    printf("  dict contains 10: %s\n", dict_contains(dict, 10) ? "yes" : "no");
    printf("\n");

    printf("Removing key 2...\n");
    dict_remove(dict, 2);
    printf("  dict contains 2: %s\n", dict_contains(dict, 2) ? "yes" : "no");
    printf("\n");

    printf("Dictionary size: %zu\n", dict_size(dict));
    printf("Is empty: %s\n", dict_is_empty(dict) ? "yes" : "no");
    printf("\n");

    dict_print_sorted(dict);

    dict_free(dict);
}


void test_real_world(void) {
    printf("\n========== TEST 3: REAL-WORLD EXAMPLE ==========\n\n");

    dict_t* students = dict_create();

    printf("Student grades database:\n");
    dict_put(students, 1001, 85);
    dict_put(students, 1002, 92);
    dict_put(students, 1003, 78);
    dict_put(students, 1004, 95);
    dict_put(students, 1005, 88);
    dict_put(students, 1006, 73);
    dict_put(students, 1007, 91);

    printf("All students (sorted by ID):\n");
    rb_inorder(students->tree, students->tree->root);
    printf("\n\n");

    int grade;
    if (dict_get(students, 1004, &grade)) {
        printf("Student 1004 has grade: %d\n", grade);
    }

    printf("\nStatistics:\n");
    printf("  Total students: %zu\n", dict_size(students));

    printf("  Removing student 1006...\n");
    dict_remove(students, 1006);
    printf("  Total students after removal: %zu\n", dict_size(students));

    dict_free(students);
}



int main(void) {
    printf("============================================\n");
    printf("   RED-BLACK TREE AND DICTIONARY\n");
    printf("============================================\n");

    test_rbtree();
    test_dict();
    test_real_world();


    return 0;
}