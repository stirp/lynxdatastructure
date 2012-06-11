/** Brief description which ends at this dot. Details follow
 *  here.
 *  编写日期：2011.11.29
 *  作者：     尚壬鹏
 */

#include <stdlib.h>
#include <assert.h>
#include "../include/LynxArrayList.h"

void LynxArrayListDestroy (LynxArrayList myArrayList,
                               BOOL (*freeElement) (void *elem)
                              )
{
    assert(myArrayList != NULL);
    // TODO (Lynx#1#): 注意void指针的自增不是通用的
}
