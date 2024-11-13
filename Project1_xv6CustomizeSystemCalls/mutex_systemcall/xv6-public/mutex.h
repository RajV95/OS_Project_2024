// mutex.h
#ifndef MUTEX_H
#define MUTEX_H



int mutex_init(uint *m);
int mutex_lock(uint *m);
int mutex_unlock(uint *m);

#endif // MUTEX_H

// struct mutex{
//     int locked;
// };