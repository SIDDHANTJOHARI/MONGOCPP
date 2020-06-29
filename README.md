 # MongoCPP
  MongoCPP is a C Library to perform CRUD operations on MongoDB database using C++.
  Database:MongoDB.
  Technology:C,C++.
 
As this is the wrapper of C functionalty of MongoDB so first of all you have to build C MongoDB Driver.

Steps to Build C MongoDB Driver for ```UBUTU 16.04```  and above versions.
## STEP 1:-Build and Install MongoDB C Driver.
```bash
export SOURCE_ROOT=/<source_root>/
sudo apt-get update
sudo apt-get install -y cmake gcc libsasl2-dev libssl-dev make pkg-config tar wget
```
## STEP 2:- Basic validation testConfigure, build and install the MongoDB C Driver
```bash
cd $SOURCE_ROOT
wget https://github.com/mongodb/mongo-c-driver/releases/download/1.16.2/mongo-c-driver-1.16.2.tar.gz
tar -xzf mongo-c-driver-1.16.2.tar.gz
cd mongo-c-driver-1.16.2
mkdir cmake-build
cd cmake-build
cmake -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF ..
make
sudo make install
```
Set Envioronment Variables:
```
export LD_LIBRARY_PATH=/usr/local/lib
export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig
```
## STEP 3:-Validation test
```
For Validation you have to install MongoDB to install MongoDB instrunctions are on their website.
The below example is used to perform a basic test to ensure that the MongoDB C Driver is working as
expected, and can connect to, modify and query a MongoDB server save the below example in a folder as insert.c.
```
### Test Examples
```c
#include<mongoc.h>
#include<bson.h>
#include<stdio.h>
int main()
{
mongoc_client_t *client;
mongoc_collection_t *collection;
mongoc_cursor_t *cursor;
bson_error_t error;
bson_t *doc;
mongoc_init();
client = mongoc_client_new("mongodb://localhost:27017");
collection = mongoc_client_get_collection(client,"tmdb","students");
doc=bson_new();
BSON_APPEND_UTF8(doc,"_id","1098");
BSON_APPEND_UTF8(doc,"firstName","SIDDHANT");
BSON_APPEND_UTF8(doc,"lastName","JOHARI");
if(!mongoc_collection_insert_one(collection,doc,NULL,NULL,&error)) printf("%s\n",error.message);
bson_destroy(doc);
mongoc_collection_destroy(collection);
mongoc_client_destroy(client);
mongoc_cleanup();
printf("Done");
return 0;
}

```
### Compile and execute
```bash
gcc insert.c $(pkg-config --libs --cflags libmongoc-1.0) -o insert.exe
./insert.exe
```
### Output
```
Done
```
If you have completed everything proerly than Now you are all set to perform operations using c++ otherwise go back to step 1.

Now moving to c++.

To Perform CRUD Operations on MongoDB Database just you have clone my repository and write your examples inside src folder.
### Test Examples.

insert.cpp
```cpp
#include"cmongo.h"
using namespace std;
int main()
{
MongoClient *mongoClient;
mongoClient=new MongoClient("mongodb://localhost:27017");
DB *db=mongoClient->getDB("tmdb","students");
ObjectInitializer *objectI;
objectI=new ObjectInitializer();
objectI->objectInitializer();
objectI->Append("_id",58);	
objectI->Append("firstName","Mamta");
objectI->Append("lastName","Gupta");
DBObject *dbObject;
dbObject=new DBObject();
dbObject->insert(db,objectI);
delete dbObject;
delete objectI;
mongoClient->close();
delete mongoClient;
cout<<"Done\n";
return 0;
}
```
### Compile and execute
```bash
g++ -I../include insert.cpp -lcmongo -L../lib -o insert.exe  $(pkg-config --libs --cflags libmongoc-1.0)
./insert.exe
```
### Output
```
Done
```
Now you are all set to perform CRUD operations on mongodb database using c++.
You can try more examples like update/delete/getAll etc. their sample codes are present in src folder.
