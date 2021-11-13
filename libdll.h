
typedef struct dll_node_{
    void *data;
    struct dll_node_ *left;
    struct dll_node_ *right;
} dll_node_t;

typedef struct dll_{
    dll_node_t *head;
} dll_t;

/*
 * Function to create a new linked list
 */
dll_t * get_new_dll();

/*
 * Add data to DLL
 */
int add_data_to_dll(dll_t *dll, void *appn_data);

/*
 * Remove data from DLL
 */
int remove_data_from_dll(dll_t *dll, void *data);

/*
 * Check if DLL is empty
 */
int is_dll_empty(dll_t *dll);

/*
 * Drain the DLL
 */
void drain_dll(dll_t *dll);

/*
 * Get DLL length
 */
int get_dll_len(dll_t *dll);