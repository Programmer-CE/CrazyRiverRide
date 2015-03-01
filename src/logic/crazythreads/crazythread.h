#ifndef CRAZYTHREAD_H
#define CRAZYTHREAD_H
#include<pthread.h>


class CrazyThread
{
public:
   CrazyThread() {}
   virtual ~CrazyThread() {}
   bool start()
   {
      return (pthread_create(&_thread, NULL, InternalThreadEntryFunc, this) == 0);
   }


   void stop()
   {
      (void) pthread_join(_thread, NULL);
   }

protected:
   virtual void internalRun() = 0;

private:
   static void * InternalThreadEntryFunc(void * This) {((CrazyThread *)This)->internalRun(); return NULL;}

   pthread_t _thread;
};

#endif // CRAZYTHREAD_H
