#ifndef ANDROID_ZXTASK_H
#define ANDROID_ZXTASK_H

#include <binder/IInterface.h>
#include <utils/RefBase.h>
#include <binder/Parcel.h>

namespace android {

class IZxTask : public IInterface {
public:
    enum { TASK_GET_PID = IBinder::FIRST_CALL_TRANSACTION,
    };

    virtual int getPid() = 0;

    DECLARE_META_INTERFACE(ZxTask);
};

class BnZxTask : public BnInterface<IZxTask> {
public:
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);
};

}; // namespace android

#endif // ANDROID_ZXTASK_H
