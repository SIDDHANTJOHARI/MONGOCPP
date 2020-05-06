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
return 0;
}
