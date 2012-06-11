/** Brief description which ends at this dot. Details follow
 *  here.
 *  编写日期： 2011年10月7日
 *  作者：     尚壬鹏
 */
#include <stdlib.h>
#include "../include/LynxArrayList.h"

void LynxArrayListInit (LynxArrayList *myArrayList,
                        long increaseStep
                       )
{
    (*myArrayList) = malloc(sizeof(struct __LynxArrayList));
    (*myArrayList)->data = NULL;
    (*myArrayList)->length = 0;
    (*myArrayList)->maxLength = 0;
    (*myArrayList)->increaseStep = increaseStep;
    (*myArrayList)->sorted = TRUE;
}
