#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "libdll.h"


/*
 * Function to create a new linked list
 */
dll_t * get_new_dll() {
    dll_t * new_dll = calloc(1, sizeof(dll_t));
    new_dll->head = NULL;
    return new_dll;
}

/*
 * Check if DLL is empty
 */
int is_dll_empty(dll_t *dll) {
    if (dll->head != NULL) return 1;
    return 0;
}

/*
 * Add data to DLL
 */
int add_data_to_dll(dll_t *dll, void *appn_data) {
    
    dll_node_t * new_node = calloc(1, sizeof(dll_node_t));
    if (new_node == NULL) return 1;
    new_node->data = appn_data;
    new_node->right = NULL;

    // Add to empty list
    if (dll->head == NULL) {
        dll->head = new_node;
        new_node->left = NULL;
    } else {
        // Find the last node if not empty
        dll_node_t * current_node = dll->head;
        while (current_node->right != NULL){
            current_node = current_node->right;
        }
        current_node->right = new_node;
        new_node->left = current_node;
    }
    return 0;
}

/*
 * Get DLL length
 */
int get_dll_len(dll_t *dll) {
    
    int count = 1;
    if (is_dll_empty(dll) == 0) return 0;
    dll_node_t * current_node = dll->head;
    while (current_node->right != NULL){
        current_node = current_node->right;
        count++;
    }

    return count;
} 

/*
 * Remove data from DLL
 */
int remove_data_from_dll(dll_t *dll, void *data) {
    // Can't remove data from empty list
    if (is_dll_empty(dll) == 0) return 1;

    // Find the data
    dll_node_t * current_node = dll->head;
    while ((current_node->data != data) && (current_node->right != NULL)){
        current_node = current_node->right;
    }
    
    if (current_node->data == data) {
        // Change the reference
        if ((current_node->left == NULL) && (current_node->right != NULL)) {
            current_node->right->left = NULL;
            dll->head = current_node->right;
        } else if ((current_node->left != NULL) && (current_node->right != NULL)) {
            current_node->right->left = current_node->left;
            current_node->left->right = current_node->right;
        } else if ((current_node->right == NULL) && (current_node->left != NULL)) {
            current_node->left->right = NULL;
        } else if ((current_node->left == NULL) && (current_node->right == NULL)) {
            dll->head = NULL;
        }

        // Remove node
        free(current_node);
        
    } else {
        return 1;
    }
    return 0;
}

/*
 * Drain the DLL
 */
void drain_dll(dll_t *dll) {
    // Can't remove data from empty list
    if (is_dll_empty(dll) == 0) return;
    // Iterate through the list
    dll_node_t * current_node = dll->head;
    dll_node_t * prev_node;
    while (current_node != NULL){
        prev_node = current_node;
        current_node = current_node->right;
        remove_data_from_dll(dll, prev_node->data);
    }

    return;
}