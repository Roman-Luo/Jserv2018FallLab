/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
    /* Hint - 2-layer malloc */
//    if (q!=NULL)
//        list_ele_t *ele = (list_ele_t *)malloc(sizeof(list_ele_t));
//        if (ele==NULL)
//            q->head = NULL;
//        else
//            q->head = ele;

    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* How about freeing the list elements and the strings? */
    /* Free queue structure */
    list_ele_t *ele = q->head;
    ele->value = NULL;
    ele->next =NULL;
    free(ele);

    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh;
    /* What should you do if the q is NULL? */
    if (q==NULL)
        return false;

    /* Don't forget to allocate space for the string and copy it */
    else
        newh = (list_ele_t *)malloc(sizeof(list_ele_t));
        
        if (newh!=NULL)
        newh->next = q->head;
        q->head = newh;

        newh->string = s;

        /* What if either call to malloc returns NULL? */
        else
            return false;
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    
    if (q!=NULL)
        /* Create a new tail element */
        list_ele_t *newt=(list_ele_t *)malloc(sizeof(list_ele_t));
        if (newt!=NULL)
            newt->value=s;
            newt->next=NULL;
        else
            return false;
        /* Insert the newt to tail of queue */
        /* Hint: No chance to write a recursive fn here, iterative only */
        list_ele_t *oldt; //old tail
        oldt=q->head;
        while (oldt->next!=NULL)
        {
            oldt=oldt->next; 
        }
        oldt->next=newt;
        return true;

    else
        return false;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
/* Hint: *sp is a ready pointer somewhere in the memory */
/* Notice: the precedence of using free to remove the element */

bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* You need to fix up this code. */
    if (q!=NULL)
        /* Copy string value from element to *sp */
        char *str = q->head->value;
        for (int i=0, i<bufsize-1, i++)
        {
            *(sp+i) = *(str+i);
        }
        *(sp+bufsize-1) = '\0';
        
        /* Remove element */
        list_ele_t *oldele = q->head;
        q->head = q->head->next;
        free(oldele);
        
        return true;

    else
        return false;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    if (q!=NULL)
        list_ele_t *node = q->head;
        int count = 0;
        if (node==NULL)
            return count;
        else if (node!=NULL && node->next=NULL)
            count = 1;
            return count;
        else
            while (node->next!=NULL)
            {
                count++;
                node = node->next;
            }
            return count;

    else (q==NULL || q->head->value=NULL)
        return 0;
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
    if (q!=NULL)
        list_ele_t *node;
        node = q->head;
        while (node!=NULL && node->next!=NULL)
        {
            node->next->next = node; 
            node = node->next;
            q->head = node;
        }
        node->next=NULL;
}

