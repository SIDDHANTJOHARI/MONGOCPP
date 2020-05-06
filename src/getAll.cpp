#include "cmongo.h"
using namespace std;
int main()
{
MongoClient *mongoClient;
mongoClient = new MongoClient("mongodb://localhost:27017");
DB *db;
db=new DB();
char *str;
db=mongoClient->getDB("tmdb","students");
DBCursor *dbCursor=db->find();
while (dbCursor->hasNext()) {
if(dbCursor->hasNextDocument())
{
while(dbCursor->hasNextAttribute())
{
const char *key=dbCursor->getKey();
if(strcmp(key,"firstName")==0)
{
const char * val=dbCursor->getString();
cout<<"Key:"<<key<<"  Value:"<<val<<endl;
}
if(strcmp(key,"lastName")==0)
{
const char * val=dbCursor->getString();
cout<<"Key:"<<key<<"  Value:"<<val<<endl;
}
if(strcmp(key,"_id")==0)
{
int32_t val=dbCursor->getInt();
cout<<"Key:"<<key<<"  Value:"<<val<<endl;
}
}
}
}
mongoClient->close();
delete mongoClient;
printf("Done");
}
