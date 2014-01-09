typedef struct _map_entry
{
  const char* key;
  const char* value;
  map_entry_t* next;
} map_entry_t;

typedef struct _map 
{
  map_entry_t* entry;  
} map_t;

// Part one functions.
void map_init(map_t*);
int map_put(map_t*, const char*, const char*);
const char* map_get(map_t*, const char*);
int map_remove(map_t*, const char*);
void map_destroy(map_t*);

// Part two functions. 
int map_serialize(map_t* self, FILE* stream);
int map_deserialize(map_t* self, FILE* stream);
