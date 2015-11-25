#include <QString>
#include "ContactsHelper.h"


ContactsHelper* ContactsHelper::instance=NULL;

ContactsHelper::~ContactsHelper()
{
    if(NULL!=ContactsHelper::instance){
           delete ContactsHelper::instance;
    }
}

ContactsHelper *ContactsHelper::getInstance()
{
    if(NULL==ContactsHelper::instance){
           ContactsHelper::instance=new ContactsHelper();
    }

   return ContactsHelper::instance;
}
