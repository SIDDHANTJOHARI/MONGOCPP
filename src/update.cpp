#include"cmongo.h"
using namespace std;
int main()
{
MongoClient *mongoClient;
mongoClient=new MongoClient("mongodb://localhost:27017");
DB *db=mongoClient->getDB("tmdb","students");
ObjectInitializer *objectI;
objectI=new ObjectInitializer();
ObjectInitializer *queryObject;
queryObject=new ObjectInitializer();
objectI->objectInitializer();
queryObject->objectInitializer();
queryObject->Append("_id",102);
objectI->Append("firstName","Madan");
objectI->Append("lastName","Bansal");
DBObject *dbObject;
dbObject=new DBObject();
dbObject->update(db,objectI,queryObject);
delete dbObject;
delete objectI;
delete queryObject;
mongoClient->close();
delete mongoClient;
return 0;
}
