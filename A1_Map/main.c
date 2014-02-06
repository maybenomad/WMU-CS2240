#include <stdlib.h>
#include <string.h>
#include "map.h"

int main(int argc, char const *argv[])
{
  map_t* map = malloc(sizeof(map_t));
  int score = 16;

  printf("\n>> INITALIZING MAP ...\n");
  map_init(map);

  printf(">> ADDING ENTRIES       ");
  int error = 1;
  do {
    if ( (map_put(map, "g", "garbage")) != OK ) { break; }
    if ( (map_put(map, "r", "rubbish")) != OK ) { break; }
    if ( (map_put(map, "t", "trash")) != OK ) { break; }
    error = 0;
  } while (0);
  if (!error) { printf("\033[1;32mPASSED\033[0m\n"); }
  else { printf("\033[1;31mFAILED\033[0m\n"); score--; }

  printf(">> DUPLICATE KEY        ");
  if (
    (map_put(map, "r", "rubbish")) == KEY_EXISTS
  ) { printf("\033[1;32mPASSED\033[0m\n"); }
  else { printf("\033[1;31mFAILED\033[0m\n"); score--; }

  printf(">> GETTING VALID KEY    ");
  if(
    strcmp((map_get(map, "t")), "trash") == 0
  ) { printf("\033[1;32mPASSED\033[0m\n"); }
  else { printf("\033[1;31mFAILED\033[0m\n"); score--; }

  printf(">> GETTING INVALID KEY  ");
  if(
    (map_get(map, "v")) == NULL
  ) { printf("\033[1;32mPASSED\033[0m\n"); }
  else { printf("\033[1;31mFAILED\033[0m\n"); score--; }

  printf(">> CHECKING SIZE (\033[1;37m%d\033[0m)    ", map_size(map));
  if(
    (map_size(map)) == 3
  ) { printf("\033[1;32mPASSED\033[0m\n"); }
  else { printf("\033[1;31mFAILED\033[0m\n"); score--; }

  printf(">> REMOVING KEY         ");
  if (
    map_remove(map, "r") == OK
  ) { printf("\033[1;32mPASSED\033[0m\n"); }
  else { printf("\033[1;31mFAILED\033[0m\n"); score--; }

  printf(">> GETTING INVALID KEY  ");
  if(
    (map_get(map, "r")) == NULL
  ) { printf("\033[1;32mPASSED\033[0m\n"); }
  else { printf("\033[1;31mFAILED\033[0m\n"); score--; }

  printf(">> GETTING VALID KEY    ");
  if(
    strcmp((map_get(map, "t")), "trash") == 0
  ) { printf("\033[1;32mPASSED\033[0m\n"); }
  else { printf("\033[1;31mFAILED\033[0m\n"); score--; }

  printf(">> REMOVING INVALID KEY ");
  if (
    map_remove(map, "r") == NO_KEY_EXISTS
  ) { printf("\033[1;32mPASSED\033[0m\n"); }
  else { printf("\033[1;31mFAILED\033[0m\n"); score--; }

  printf(">> REMOVING KEY         ");
  if (
    map_remove(map, "t") == OK
  ) { printf("\033[1;32mPASSED\033[0m\n"); }
  else { printf("\033[1;31mFAILED\033[0m\n"); score--; }

  printf(">> REMOVING KEY         ");
  if (
    map_remove(map, "g") == OK
  ) { printf("\033[1;32mPASSED\033[0m\n"); }
  else { printf("\033[1;31mFAILED\033[0m\n"); score--; } 

  printf(">> SERIALIZING          ");
  map_put(map, "g", "garbage");
  map_put(map, "r", "rubbish");
  map_put(map, "t", "trash");
  FILE *fout = fopen("map.txt", "w");
  if (
    map_serialize(map, fout) == OK
  ) { printf("\033[1;32mPASSED\033[0m\n"); }
  else { printf("\033[1;31mFAILED\033[0m\n"); score--; } 

  printf("\n-- FILE CONTENTS -------------\n");
  freopen("map.txt", "r", fout);
  char *buff = malloc(256 * sizeof(char));
  while ( (fgets(buff, 256, fout)) != NULL ) {
    printf("%s", buff);
  }
  printf("------------------------------\n");
  free(buff);
  fclose(fout);

  printf("\n>> DESTROYING MAP ...\n");
  map_destroy(map);

  printf(">> RECREATING MAP ...\n");
  map = malloc(sizeof(map_t));
  map_init(map);

  printf(">> DESERIALIZING        ");
  FILE *fin = fopen("map.txt", "r");
  if (
    map_deserialize(map, fin) == OK
  ) { printf("\033[1;32mPASSED\033[0m\n"); }
  else { printf("\033[1;31mFAILED\033[0m\n"); score--; } 
  fclose(fin);

  printf("\n-- LIST CONTENTS -------------\n");
  if (map->entry != NULL) {
    map_entry_t* current = map->entry;
    while ( current->next != NULL ) {
      printf("%s:%s\n", current->key, current->value);
      current = current->next;
    }
  } else {
    printf("\033[1;31mNULL\033[0m\n");
  }
  printf("------------------------------\n");

  printf("\n>> GETTING VALID KEY    ");
  if(
    strcmp((map_get(map, "g")), "garbage") == 0
  ) { printf("\033[1;32mPASSED\033[0m\n"); }
  else { printf("\033[1;31mFAILED\033[0m\n"); score--; }

  printf(">> GETTING VALID KEY    ");
  if(
    strcmp((map_get(map, "r")), "rubbish") == 0
  ) { printf("\033[1;32mPASSED\033[0m\n"); }
  else { printf("\033[1;31mFAILED\033[0m\n"); score--; }

  printf(">> GETTING VALID KEY    ");
  if(
    strcmp((map_get(map, "t")), "trash") == 0
  ) { printf("\033[1;32mPASSED\033[0m\n"); }
  else { printf("\033[1;31mFAILED\033[0m\n"); score--; }

  printf("                   \033[1;37mSCORE: %d/16\033[0m\n\n", score);
  return 0;
}