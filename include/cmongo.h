#include<mongoc.h>
#include<bits/stdc++.h>
class ObjectInitializer
{
public:
bson_t *doc;
void objectInitializer();
void Append(const char * attribute, const char *  value);
void Append(const char * attribute,int32_t value);
~ObjectInitializer();
};
class DBCursor
{
public:
mongoc_cursor_t *cursor;
const bson_t *document;
bson_iter_t iterator;
uint32_t length;
bool hasNext();
char * next();
bool hasNextDocument();
bool hasNextAttribute();
const char * getKey();
int32_t getInt();
const char * getString();
~DBCursor();
};
class DB
{
DBCursor *dbCursor;
public:
mongoc_collection_t *collection;
DBCursor * find();
~DB();
};
class MongoClient
{
mongoc_client_t *client;
DB *db;
public:
MongoClient(const char * connectionString);
DB* getDB(const char * database,const char * documentName);
void close();
~MongoClient();
};
 class DBObject
{
public:
bson_error_t error;
void insert(DB *db,ObjectInitializer *object);
void remove(DB *db,ObjectInitializer *queryObject);
void update(DB *db,ObjectInitializer *object,ObjectInitializer *queryObject);
};
