/** @file   LynxArrayList.h
    @brief  Lynx的数组线性表\n
    编写日期： 2011年10月5日\n
    作者：     尚壬鹏\n
*/

/** @struct __LynxArrayList
    @brief  定义了LynxArrayList的数据结构
            用户不应该直接操作这个结构体
*/

/** @typedef    struct __LynxArrayList *LynxArrayList
    @brief  将指向数据结构的指针定义为LynxArrayList类型。
            这样定以后使用者的使用方式将大大轻松
    @warning    不要忘记使用LynxArrayListInit初始化
*/

/** @fn void LynxArrayListInit (LynxArrayList *myArrayList,
                               long increaseStep
                               )
    @brief  初始化一个数组线性表的指针，如果该指针原本指向一
            处保留的数据，将失去对该数据的指向。
    @param  myArrayList LynxArrayList指针，该指针应当为无效的指针。
            存储空间将自动分配。
    @param  increaseStep 每次分配的数组空间不够用时，
            增加increaseStep个存储单元。单独提出这个参数是由于处
            理的数据规模不同，为了尽量减少重新分配空间的次数。
*/

/** @fn LynxArrayListDestroy (LynxArrayList myArrayList,
                              BOOL (*freeElement) (void *elem)
                             )
    @brief  删除一个数组线性表指针指向的数据结构，存储的元素将使
            用freeElement函数释放掉空间。
    @param  myArrayList LynxArrayList指针，该指针应当为有效的指针。
    @param  freeElement 用于释放单个元素的函数，用户编写后传入
*/

/** @fn LynxArrayListClear (LynxArrayList myArrayList,
                            BOOL (*freeElement) (void *elem)
                           )
    @brief  清空一个数组线性表指针中的元素。存储的元素将使用
            freeElement函数释放掉空间。
    @param  myArrayList LynxArrayList指针，该指针应当为有效的指针。
    @param  freeElement 用于释放单个元素的函数，用户编写后传入
*/

/** @fn BOOL LynxArrayListIsEmpty (LynxArrayList myArrayList)
    @brief  判断数组线性表是否为空
    @param  myArrayList LynxArrayList指针，该指针应当为有效的指针。
    @return 如果数组线性表是空，则返回TRUE；否则返回FALSE
*/

/** @fn void *LynxArrayListGetElem (LynxArrayList myArrayList,
                                    long position
                                   )
    @brief  从数组线性表中获得第position个元素
    @param  myArrayList LynxArrayList指针，该指针应当为有效的指针。
    @param  position 第position个元素
    @return 如果存在第position个元素，则返回指向第position个元素
            的指针；否则返回NULL指针
*/

/** @fn long LynxArrayListLocateElem (LynxArrayList myArrayList,
                                      void *elem,
                                      BOOL (*compare)(void *elema,
                                                      void *elemb
                                                     )
                                     )
    @brief  根据elem的值，定位与elem相等的元素在线性表的位置。
    @param  myArrayList LynxArrayList指针，该指针应当为有效的指针。
    @param  elem 用户提供的元素
    @param  compare 该函数由用户编写后传入，用于比较两个元素是否
            相等的函数
    @return 返回元素在数组的位置。如果不存在，则返回-1
*/

/** @fn BOOL LynxArrayListInsert (LynxArrayList myArrayList,
                                  long position,
                                  void *elem
                                 )
    @brief  在数组线性表的第position的位置插入一个元素
    @param  myArrayList LynxArrayList指针，该指针应当为有效的指针。
    @param  position 打算插入元素的位置
    @param  elem 插入的元素
    @return 如果插入成功，则返回TRUE；否则返回FALSE
*/

/** @fn void *LynxArrayListGetAndDelete (LynxArrayList myArrayList,
                                         long position
                                        )
    @brief Opens a file descriptor.
    @param  myArrayList LynxArrayList指针，该指针应当为有效的指针。
    @param  position 数组的第i个位置
    @return 如果元素存在，则返回第position个元素的地址；否则返回
            NULL
*/

/** @fn long LynxArrayListTraverse (LynxArrayList myArrayList,
                                    void (*visit)(void *returns)
                                   )
    @brief  对整个数组的所有元素调用visit函数访问
    @param  myArrayList LynxArrayList指针，该指针应当为有效的指针。
    @param  visit visit函数，由用户编写并传入
    @return 返回访问的元素个数
*/

#ifndef LYNXARRAYLIST_H_INCLUDED
#define LYNXARRAYLIST_H_INCLUDED

#include <windows.h>
#include "Common.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

    struct __LynxArrayList
    {
        void *data;         /**< data指针,指向数组的开头 */
        long length;        /**< 当前包含的元素个数 */
        long maxLength;     /**< 整个数组的长度 */
        long increaseStep;  /**< 每当数组长度不够时，自动增加的个数 */
        BOOL sorted;        /**< 表明当前的数组是否是排序好的 */
    };

    typedef struct __LynxArrayList *LynxArrayList;

    typedef void (*tLynxArrayListInit) (LynxArrayList *myArrayList,
                            long increaseStep
                           );

    typedef void (*tLynxArrayListDestroy) (LynxArrayList myArrayList,
                               BOOL (*freeElement) (void *elem)
                              );

    typedef void (*tLynxArrayListClear) (LynxArrayList myArrayList,
                             BOOL (*freeElement) (void *elem)
                            );

    typedef long (*tLynxArrayListLength) (LynxArrayList myArrayList);

    typedef BOOL (*tLynxArrayListIsEmpty) (LynxArrayList myArrayList);

    typedef void *(*tLynxArrayListGetElem) (LynxArrayList myArrayList,
                                long position
                               );

    typedef long (*tLynxArrayListLocateElem) (LynxArrayList myArrayList,
                                  void *elem,
                                  long (*compare)(void *elema,
                                          void *elemb
                                                 )
                                 );

    typedef BOOL (*tLynxArrayListInsert) (LynxArrayList myArrayList,
                              long position,
                              void *elem
                             );

    typedef void *(*tLynxArrayListGetAndDelete) (LynxArrayList myArrayList,
                                     long position
                                    );

    typedef long (*tLynxArrayListTraverse) (LynxArrayList myArrayList,
                                void (*visit)(void *returns)
                               );

    typedef void (*tLynxArrayListQsort) (LynxArrayList myArrayList,
                             long (*compare)(void *elema,
                                          void *elemb
                                                 )
                            );

    typedef void *(*tLynxArrayListBsearch)  (LynxArrayList myArrayList,
                                 long (*compare)(void *elema,
                                          void *elemb
                                                 ),
                                void *elem
                                );

    struct __LynxArrayListFunctions
    {
        tLynxArrayListInit LynxArrayListInit;
        tLynxArrayListDestroy LynxArrayListDestroy;
        tLynxArrayListClear LynxArrayListClear;
        tLynxArrayListLength LynxArrayListLength;
        tLynxArrayListIsEmpty LynxArrayListIsEmpty;
        tLynxArrayListGetElem LynxArrayListGetElem;
        tLynxArrayListLocateElem LynxArrayListLocateElem;
        tLynxArrayListInsert LynxArrayListInsert;
        tLynxArrayListGetAndDelete LynxArrayListGetAndDelete;
        tLynxArrayListTraverse LynxArrayListTraverse;
        tLynxArrayListQsort LynxArrayListQsort;
        tLynxArrayListBsearch LynxArrayListBsearch;
    };

    typedef struct __LynxArrayListFunctions LynxArrayListFunctions;

    void LynxArrayListInitialFunctions(HINSTANCE *hinstDLL,
                    LynxArrayListFunctions lynxArrayListFunctions
                    );

    void LynxArrayListCleanFunctions(
                    HINSTANCE *hinstDLL,
                    LynxArrayListFunctions lynxArrayListFunctions
                    );

#ifdef __cplusplus
}
#endif

#endif // LYNXARRAYLIST_H_INCLUDED
