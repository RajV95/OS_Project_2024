#include "types.h"
#include "defs.h"
#include "mutex.h"

int mutex_init(struct mutex *m) {
    m->locked = 0;
    return 0;
}

int mutex_lock(struct mutex *m) {
    while (xchg(&m->locked, 1) != 0);
    return 0;
}

int mutex_unlock(struct mutex *m) {
    xchg(&m->locked, 0);
    return 0;
}
