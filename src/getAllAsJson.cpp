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
 str = dbCursor->next();
cout<<str<<endl;
  }
mongoClient->close();
delete mongoClient;
printf("Done");
}
