#ifndef ANDROID_ZXTASKSERVICE_H
#define ANDROID_ZXTASKSERVICE_H

#include "ZxTask.h"
#include <binder/BinderService.h>

namespace android {

class ZxTaskService : public BinderService<ZxTaskService>, public BnZxTask {
public:
    virtual int getPid();
    static char const* getServiceName() { return "ZxTask"; }
    friend class BinderService<ZxTaskService>;
};



} // namespace android

#endif // ANDROID_ZXTASKSERVICE_H
