/**
 * @file cp_log.cpp
 * @author zpf (you@domain.com)
 * @brief 日志模块
 * @version 0.1
 * @date 2022-12-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "log.h"


namespace ChiXiao{

/**
* @brief 将日志级别转成文本输出
* @param[in] level 日志级别
*/
const char* LogLevel::ToString(LogLevel::Level level){
    switch(level){
        // #的功能是将其后面的宏参数进行字符串化操作，简单说就是在对它所引用的宏变量通过替换后在其左右各加上一个双引号
        #define XX(name) case LogLevel::name: return #name; break;
        XX(DEBUG);
        XX(INFO);
        XX(WARN);
        XX(ERROR);
        XX(FATAL);
        
        #undef XX default: return "UNKNOW";
    }
    return "UNKNOW";
}

/**
* @brief 将文本转换成日志级别
* @param[in] str 日志级别文本
*/
LogLevel::Level LogLevel::FromString(const std::string& str){
    #define XX(level, v) \
        if(str == #v){ \
            return LogLevel::level; \
        }

        XX(DEBUG, debug);
        XX(INFO, info);
        XX(WARN, warn);
        XX(ERROR, error);
        XX(FATAL, fatal);

        XX(DEBUG, DEBUG);
        XX(INFO, INFO);
        XX(WARN, WARN);
        XX(ERROR, ERROR);
        XX(FATAL, FATAL);
        return LogLevel::UNKNOW;
    #undef XX
}



/**
 * @brief 将文本转换成日志级别
 *
 */















}



