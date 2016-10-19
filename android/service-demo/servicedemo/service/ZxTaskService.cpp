#include "ZxTaskService.h"
#include <unistd.h>

namespace android {

int ZxTaskService::getPid()
{
    return getpid();
}


}; // namespace android