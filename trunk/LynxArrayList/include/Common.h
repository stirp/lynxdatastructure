/*! \file Common.h
    \brief Lynx数据结构通用的设置
    详细信息 /// @todo (Lynx#1#): 详细信息留待以后填写
*/

/*! \def BOOL
    \brief 用普通整型定义布尔变量
    用整型变量定义布尔变量
*/

#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED


#ifndef BOOL
#define BOOL int    /**定义布尔型变量*/
#endif

#ifndef FALSE
#define FALSE 0     /**定义布尔假*/
#endif

#ifndef TRUE
#define TRUE !FALSE /**定义布尔真*/
#endif


#endif // COMMON_H_INCLUDED
