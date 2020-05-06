#include<mongoc.h>
#include<bson.h>
//#include<bcon.h>
#include<stdio.h>
#include<bits/stdc++.h>
#include "cmongo.h"
using namespace std;
void ObjectInitializer::objectInitializer()
{
this->doc= bson_new();
}
void ObjectInitializer::Append(const char * attribute,int32_t value)
{
BSON_APPEND_INT32(this->doc,attribute,value);
}
void ObjectInitializer::Append(const char * attribute, const char *  value)
{
BSON_APPEND_UTF8(this->doc,attribute,value);
}
ObjectInitializer::~ObjectInitializer()
{
bson_destroy(this->doc);
}
bool DBCursor::hasNext()
{
if(mongoc_cursor_next(this->cursor, &(this->document)))return true;
else return false;
}
char * DBCursor::next()
{
char *str;
str=bson_as_json (this->document, NULL);
return str;
}
bool DBCursor::hasNextDocument()
{
return bson_iter_init(&(this->iterator),this->document);
}
bool DBCursor::hasNextAttribute()
{
return bson_iter_next(&(this->iterator));
}
const char * DBCursor::getKey()
{
return bson_iter_key(&(this->iterator));
}
int32_t DBCursor::getInt()
{
return bson_iter_int32(&(this->iterator));
}
const char * DBCursor::getString()
{
return bson_iter_utf8(&(this->iterator),&(this->length));
}
DBCursor::~DBCursor()
{
mongoc_cursor_destroy(this->cursor);
}
DBCursor * DB::find()
{
dbCursor=new DBCursor();
bson_t query;
bson_init (&query);
dbCursor->cursor = mongoc_collection_find_with_opts (collection,&query, NULL, NULL);
return dbCursor;
}
DB::~DB()
{
delete this->dbCursor;
mongoc_collection_destroy(this->collection);
}
MongoClient::MongoClient(const char * connectionString)
{
mongoc_init();
this->client=mongoc_client_new(connectionString);
}

DB* MongoClient::getDB(const char * database,const char * documentName)
{
db=new DB();
db->collection=mongoc_client_get_collection(this->client,database,documentName);
return db;
}
void MongoClient::close()
{
mongoc_cleanup();
}
MongoClient::~MongoClient()
{
delete this->db;
mongoc_client_destroy(this->client);
}
void DBObject::insert(DB *db,ObjectInitializer *object)
{
if(!mongoc_collection_insert_one(db->collection,object->doc,NULL,NULL,&(error))) printf("%s\n",error.message);
}
void DBObject::remove(DB *db,ObjectInitializer *queryObject)
{
if(!mongoc_collection_delete_one(db->collection,queryObject->doc,NULL,NULL,&error)) printf("%s\n",error.message);
}
void DBObject::update(DB *db,ObjectInitializer *object,ObjectInitializer *queryObject)
{
if(!mongoc_collection_update(db->collection,MONGOC_UPDATE_NONE,queryObject->doc,object->doc,NULL,&error))printf("%s\n",error.message);
}

