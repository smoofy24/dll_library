#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "libbt.h"

/*
 * Function to create a new BT
 */
bt_t * get_new_bt() {
    bt_t * new_bt = calloc(1, sizeof(bt_t));
    new_bt->root = NULL;
    return new_bt;
}

/*
 * Function to create first node in BT
 */
int new_node_to_bt(bt_t *bt, void *appn_data) {
    // If not empty return with -1
    if (bt->root != NULL) {
        return -1;
    }

    bt_node_t * new_node = calloc(1, sizeof(bt_node_t));
    if (new_node == NULL) {
        return -1;
    }

    bt->root = new_node;
    
    new_node->data = appn_data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;
    new_node->children = NULL;

    return 0;
}

/*
 * Append child of the parent
 */
int append_node_to_bt(bt_node_t *parent, void *appn_data) {
    // Create new node
    bt_node_t * new_node = calloc(1, sizeof(bt_node_t));
    if (new_node == NULL) {
        return -1;
    }

    // First child?
    if (parent->children == NULL) {
        parent->children = new_node;
    } else {
        bt_node_t * node_ptr;
        ITERATE_NODES_BEGIN(parent, node_ptr);
            if (node_ptr->right == NULL) {
                node_ptr->right = new_node;
                new_node->left = node_ptr;
            }
        ITERATE_NODES_END;

    }

    new_node->data = appn_data;
    new_node->parent = parent;
    new_node->right = NULL;
    new_node->children = NULL;

    return 0;
}

/*
 * Number of children parent has
 */
int num_of_children(bt_node_t *parent) {
    int child_count = 0;
    bt_node_t * cur_node = parent->children;

    while(cur_node != NULL) {
        cur_node = cur_node->right;
        child_count++;
    }
    return child_count;
}

/*
 * Is root?
 */
int is_root(bt_node_t *node) {
    if (node->parent == NULL) {
        return 1;
    } else {
        return 0;
    }
}

/*
 * Is leaf?
 */
int is_leaf(bt_node_t *node) {
    if (node->children == NULL) {
        return 1;
    } else {
        return 0;
    }
}