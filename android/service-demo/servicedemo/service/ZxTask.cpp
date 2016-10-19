#include "ZxTask.h"


namespace android {

class BpZxTask : public BpInterface<IZxTask> {
public:
    BpZxTask(const sp<IBinder>& binder)
        : BpInterface<IZxTask>(binder)
    {
    }

    virtual int getPid()
    {
        Parcel data, reply;
        data.writeInterfaceToken(IZxTask::getInterfaceDescriptor());
        remote()->transact(TASK_GET_PID, data, &reply);
        return reply.readInt32();
    }
};


IMPLEMENT_META_INTERFACE(ZxTask, "android.hardware.IZxTask");

status_t BnZxTask::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{

    switch (code) {
    case TASK_GET_PID: {
        CHECK_INTERFACE(IZxTask, data, reply);
        int32_t pid = getPid();
        reply->writeInt32(pid);
        return NO_ERROR;

    } break;

    default:
    	return BBinder::onTransact(code, data, reply, flags);
    }
}

}; // namespace android
