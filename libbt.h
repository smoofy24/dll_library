#ifndef lib_bt
#define lib_bt

typedef struct bt_node_ {
    void *data;
    struct bt_node_ *left;
    struct bt_node_ *right;
    struct bt_node_ *parent;
    struct bt_node_ *children;
} bt_node_t;

typedef struct bt_{
    bt_node_t *root;
} bt_t;

/*
 * Function to create a new BT
 */

bt_t * get_new_bt();

/*
 * Function to create first node in BT
 */
int new_node_to_bt(bt_t *bt, void *appn_data);

/*
 * Append child of the parent
 */
int append_node_to_bt(bt_node_t *node, void *appn_data);

/*
 * Number of children
 */
int num_of_children(bt_node_t *parent);

/*
 * Is root?
 */
int is_root(bt_node_t *node);

/*
 * Is leaf?
 */
int is_leaf(bt_node_t *node);

/*
 * Remove data from BT
 */
int remove_data_from_bt(bt_t *bt, void *data);

/*
 * Check if BT is empty
 */
int is_bt_empty(bt_t *bt);

/*
 * Drain the BT
 */
void drain_bt(bt_t *bt);

/*
 * Get DLL length
 */
int get_bt_len(bt_t *bt);

/*
 * Macro to iterate through the bt
 */
#define ITERATE_NODES_BEGIN(list_ptr, node_ptr)      \
{                                                   \
    bt_node_t * _node_ptr = NULL;                  \
    node_ptr = list_ptr->children;                      \
    for(; node_ptr != NULL; node_ptr =_node_ptr){   \
        _node_ptr = node_ptr->right;                

#define ITERATE_NODES_END }}  

#endif