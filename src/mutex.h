/**
 * @file mutex.h
 * @author zpf (zpf001001@gmail.com)
 * @brief 锁模块
 * @version 0.1
 * @date 2022-12-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __CHIXIAO_MUTEX_H__
#define __CHIXIAO_MUTEX_H__

#include <thread>
#include <functional>
#include <memory>
#include <pthread.h>
#include <semaphore.h>
#include <stdint.h>
#include <atomic>
#include <list>

namespace ChiXiao{


/**
 * @brief 局部锁的模板实现
 *
*/
template<class T>
struct ScopedLockImpl
{
    private:
        // mutex
        T& m_mutex;
        // 是否已上锁
        bool m_locked;

    /**
     * @brief 构造函数，自动加锁
     *
     */
    ScopedLockImpl(T& mutex)
        :m_mutex(mutex){
        m_mutex.lock();
        m_locked = true;
    }

    /**
     * @brief 析构函数,自动释放锁
     *
     */
    ~ScopedLockImpl()
    {
        unlock();
    }

    /**
     * @brief 加锁
     *
     */
    void lock()
    {
        if (!m_locked)
        {
            m_mutex.lock();
            m_locked = true;
        }
    }

    /**
     * @brief 解锁
     *
     */
    void unlock()
    {
        if (m_locked)
        {
            m_mutex.unlock();
            m_locked = false;
        }
    }

};




/**
 * @brief 自旋锁
 *
//  */
// class Spinlock : Noncopyable{
//     public:
//         // 局部锁
//         // typedef Scoped
// }









}


#endif