#include "service/ZxTask.h"
#include <binder/IServiceManager.h>
#include <unistd.h>
#include <stdio.h>




int main()
{
    using namespace android;
    sp<IServiceManager> sm =defaultServiceManager();  
    printf("%s\n", "get serviceManager");
    sp<IBinder> binder =sm->getService(String16("ZxTask"));  
    sp<IZxTask> mTask =interface_cast<IZxTask>(binder);  
    printf("ZxTask Service pid %d, client pid:%d",mTask->getPid(), getpid());  

    return 0;
}
