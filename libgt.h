#ifndef __GLTHREADS__
#define __GLTHREADS__

typedef struct glthread_node_ {
    
    struct glthread_node_ *left;
    struct glthread_node_ *right;
} glthread_node_t;

typedef struct glthread_ {

    glthread_node_t *head;
    unsigned int offset;
} glthread_t;

/*
 * Function to create a new linked list
 */
void glthread_add (glthread_t *lst, glthread_node_t *glnode);

/*
 * Remove data from DLL
 */
void glthread_remove (glthread_t *lst, glthread_node_t *glnode);

/*
 * Init the thread
 */
void init_glthread(glthread_t *glthread, unsigned int offset);

/*
 * Iterative macro
 * lstptr       -> list pointer
 * struct_type  ->  
 * ptr          ->
 */
#define ITERATE_GL_THREADS_BEGIN(lstptr, struct_type, ptr)          \
{                                                                   \
    glthread_node_t *_glnode = NULL; *_next = NULL;                 \
    for (_glnode = lstptr->head; _glnode; _glnode = _next){         \
        _next = _glnode->right;                                     \
        ptr = (struct_type *)((char *)_glnode - lsptr->offset);
#define ITERATE_GL_THREADS_ENDS }}

/*
 * Macro to get the offset of field in a structure
 */
#define offsetof(st, m) \
    ((size_t)&(((st *)0)->m))

#endif /* __GLTHREADS__ */