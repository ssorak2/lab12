// Code for a linked list queue

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct nodeStruct
{
 int value;
 struct nodeStruct* next;
} node;

typedef struct queueStruct
{
 node* front;
 node* rear;
}queue;

queue* my_create() {
  queue* result;
  result = (queue*) malloc(sizeof(queue));
  result->front = NULL;
  result->rear = NULL;
}

// add a value to the end of the queue
void my_add(queue* q, int val) {
  node* temp = (node*)malloc(sizeof(node));
  temp->value = val;
  temp->next = NULL;

  if (q->front == NULL) {
     q->front = temp;
     q->rear = temp;
  }
  else {
     q->rear->next = temp;
     q->rear = temp;
  }
}

// return TRUE if queue is empty
int my_isEmpty (queue* q) {
  if (q->front == NULL)
     return TRUE;
  else
     return FALSE;
}

// remove the value from the front of the queue
// AND return the value in the node that was remove
// If queue is empty when called RETURN -999
int my_remove (queue* q) {
  if (q->front == NULL) 
     return -999;
  else {
     node* temp = q->front;
     q->front = q->front->next;
     int retval = temp->value;
     free (temp);
     return retval;
  }
}

int main (int argc, char** argv) {
  queue* q1;
  q1 = my_create();

  for (int i = 10; i <= 50; i = i + 5) {
     my_add(q1, i);
  }

  while (my_isEmpty(q1) == FALSE) {
     int v = my_remove(q1);
     printf ("Value %d\n", v);
  }

  // the following printf should print -999
  printf ("Check if queue is empty\n");
  int v = my_remove(q1);
  printf ("Value %d\n", v);
}
