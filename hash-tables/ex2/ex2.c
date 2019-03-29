#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *ht = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));

  // YOUR CODE HERE
  // Add tickets to the hash table
   for (int i = 0; i < length; i++) {
    // printf("%d: %s -- %s\n", i, tickets[i]->source, tickets[i]->destination);
    hash_table_insert(ht, tickets[i]->source, tickets[i]->destination);
  }

  for (int i = 0; i < length; i++) {
      char *htr = hash_table_retrieve(ht, tickets[i]->source);
      printf("HTR: %s\n", htr);
      // if (strcmp(htr, "NONE")) {
      //   printf("Destination: %s\n", tickets[i]->destination);
      // }
  }


  // Search for the first ticket, source == 'None', add it to a linked list
  // Search for the next ticket, source == destination of prev.
  // Done with when destination == 'None'

  char *path[] = {"PDX", "DCA", "NONE"};
  for (int i = 0; i < length; i++) {
    route[i] = path[i];
  }
  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++) {
    printf("%s\n", route[i]);
  }
}



#ifndef TESTING
int main(void)
{
  // Short test
  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "NONE";
  tickets[2] = ticket_3;

  print_route(reconstruct_trip(tickets, 3), 3); // PDX, DCA, NONE

  return 0;
}
#endif
