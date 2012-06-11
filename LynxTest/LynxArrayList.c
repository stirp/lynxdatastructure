/** 用户使用的函数绑定页面.
 *  编写日期： 2010年10月18日
 *  作者：     尚壬鹏
 */

#include "LynxArrayList.h"


void LynxArrayListInitialFunctions(
                    HINSTANCE *hinstDLL,
                    LynxArrayListFunctions lynxArrayListFunctions
                    )
{
    *hinstDLL = LoadLibrary("libLynxArrayList.dll");

    if (*hinstDLL == NULL)//dll文件不存在
    {
        lynxArrayListFunctions.LynxArrayListInit = NULL,
        lynxArrayListFunctions.LynxArrayListDestroy = NULL;
        lynxArrayListFunctions.LynxArrayListClear = NULL;
        lynxArrayListFunctions.LynxArrayListLength = NULL;
        lynxArrayListFunctions.LynxArrayListIsEmpty = NULL;
        lynxArrayListFunctions.LynxArrayListGetElem = NULL;
        lynxArrayListFunctions.LynxArrayListLocateElem = NULL;
        lynxArrayListFunctions.LynxArrayListInsert = NULL;
        lynxArrayListFunctions.LynxArrayListGetAndDelete = NULL;
        lynxArrayListFunctions.LynxArrayListTraverse = NULL;
        lynxArrayListFunctions.LynxArrayListQsort = NULL;
        lynxArrayListFunctions.LynxArrayListBsearch = NULL;
        return;
    }

    lynxArrayListFunctions.LynxArrayListInit =
            (tLynxArrayListInit)
            GetProcAddress(*hinstDLL, "LynxArrayListInit");

    lynxArrayListFunctions.LynxArrayListDestroy =
            (tLynxArrayListDestroy)
            GetProcAddress(*hinstDLL, "LynxArrayListDestroy");

    lynxArrayListFunctions.LynxArrayListClear =
            (tLynxArrayListClear)
            GetProcAddress(*hinstDLL, "LynxArrayListClear");

    lynxArrayListFunctions.LynxArrayListLength =
            (tLynxArrayListLength)
            GetProcAddress(*hinstDLL, "LynxArrayListLength");

    lynxArrayListFunctions.LynxArrayListIsEmpty =
            (tLynxArrayListIsEmpty)
            GetProcAddress(*hinstDLL, "LynxArrayListIsEmpty");

    lynxArrayListFunctions.LynxArrayListGetElem =
            (tLynxArrayListGetElem)
            GetProcAddress(*hinstDLL, "LynxArrayListGetElem");

    lynxArrayListFunctions.LynxArrayListLocateElem =
            (tLynxArrayListLocateElem)
            GetProcAddress(*hinstDLL, "LynxArrayListLocateElem");

    lynxArrayListFunctions.LynxArrayListInsert =
            (tLynxArrayListInsert)
            GetProcAddress(*hinstDLL, "LynxArrayListInsert");

    lynxArrayListFunctions.LynxArrayListGetAndDelete =
            (tLynxArrayListGetAndDelete)
            GetProcAddress(*hinstDLL, "LynxArrayListGetAndDelete");

    lynxArrayListFunctions.LynxArrayListTraverse = (tLynxArrayListTraverse)
            GetProcAddress(*hinstDLL, "LynxArrayListTraverse");

    lynxArrayListFunctions.LynxArrayListQsort = (tLynxArrayListQsort)
            GetProcAddress(*hinstDLL, "LynxArrayListTraverse");

    lynxArrayListFunctions.LynxArrayListBsearch = (tLynxArrayListBsearch)
            GetProcAddress(*hinstDLL, "LynxArrayListTraverse");
}

void LynxArrayListCleanFunctions(
                    HINSTANCE *hinstDLL,
                    LynxArrayListFunctions lynxArrayListFunctions
                    )
{
    if(FreeLibrary(*hinstDLL))
    {
        *hinstDLL = NULL;
        lynxArrayListFunctions.LynxArrayListInit = NULL,
        lynxArrayListFunctions.LynxArrayListDestroy = NULL;
        lynxArrayListFunctions.LynxArrayListClear = NULL;
        lynxArrayListFunctions.LynxArrayListLength = NULL;
        lynxArrayListFunctions.LynxArrayListIsEmpty = NULL;
        lynxArrayListFunctions.LynxArrayListGetElem = NULL;
        lynxArrayListFunctions.LynxArrayListLocateElem = NULL;
        lynxArrayListFunctions.LynxArrayListInsert = NULL;
        lynxArrayListFunctions.LynxArrayListGetAndDelete = NULL;
        lynxArrayListFunctions.LynxArrayListTraverse = NULL;
        lynxArrayListFunctions.LynxArrayListQsort = NULL;
        lynxArrayListFunctions.LynxArrayListBsearch = NULL;
    }

}
