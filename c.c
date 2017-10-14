// Jake Zaia
// Systems p10
// 2017-10-13
// Work06

#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next;};

// Prints all items in list
void print_list(struct node * ll) {
  struct node *currNode = ll;
  printf("The list:   ");
  while(currNode) {
    printf("%d -> ", (*currNode).i);
    currNode = (*currNode).next;
  }
  printf("NULL\n");
}

// Adds a new node, creates a node if passed NULL
struct node * insert_front(struct node * ll, int n) {
  if (ll) {
    struct node * a = (struct node *) malloc( sizeof(struct node) );
    (*a).i = n;
    (*a).next = ll;
    return a;
  }
  else {
    struct node * a = (struct node *) malloc( sizeof(struct node) );
    (*a).i = n;
    (*a).next = 0;
    return a;
  }
}

struct node * free_list(struct node *ll) {
  struct node *currNode = ll;
  while (currNode) {
    struct node *p = (*currNode).next;
    free(currNode);
    currNode = p;
  }
  return 0;
}

int main () {
  printf("\nInserting %d\n", 3);
  struct node *ll = insert_front(0, 3);
  print_list(ll);
  
  printf("\nInserting %d\n", 2);
  ll = insert_front(ll, 2);
  print_list(ll);
  
  printf("\nInserting %d\n", 1);
  ll = insert_front(ll, 1);
  print_list(ll);
  
  printf("\nInserting %d\n", 0);
  ll = insert_front(ll, 0);
  print_list(ll);

  printf("\nFreeing list...\n");
  ll = free_list(ll);

  print_list(ll);
}
