typedef struct _map_entry
{
  
} map_entry_t;

typedef struct _map 
{
  map_entry_t* entry;  
} map_t;

void map_init(map_t*);
int map_put(map_t*, const char*, const char*);
const char* map_get(map_t*, const char*);
int map_remove(map_t*, const char*);
void map_destroy(map_t*);
