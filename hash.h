//File hash.h

#define BUCKET_SIZE 32
#define K_VEC 3
#define W 4

typedef struct Bucket
{
	Vector *key[BUCKET_SIZE];
	int data[BUCKET_SIZE];
	int entries;
	struct Bucket *overflow;
} Bucket;

typedef struct HashTable
{
	int size;
	Bucket **table;
} HashTable;

typedef struct GParameters
{
	Vector *v;
	double t;
} GParameters;

typedef struct HashInfo
{
	HashTable *hashTable;
	Point *grids;
	int *r;
	GParameters *gParameters;
} HashInfo;

int hash(Vector*, int*, int);
void g(Vector *g_u, Vector *u, GParameters *h);
HashTable *createHashTable(int size);
int insertToTable(HashTable *hashTable, Vector*, Vector*, int data, int *r);
void destroyHashTable(HashTable *hashTable);
Bucket *createBucket();
void insertToBucket(Bucket *bucket, Vector *key, int data);
void destroyBucket(Bucket *bucket);

