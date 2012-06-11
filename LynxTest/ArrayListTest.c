/** 专门放置arraylist的测试函数于此
 *  编写日期： 8:49 2011-11-10
 *  作者：     尚壬鹏
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <windows.h>
#include "LynxArrayList.h"

#include "CUnit.h"

LynxArrayListFunctions lynxArrayListFunctions;
HINSTANCE hinstDLL = NULL;
LynxArrayList myArrayList = NULL;
int myTarget = 10;
int sums = 0;

/*---------------------User Functions-----------------*/
static long compare(void *a, void *b)
{
    return ((*(int*)a) - (*(int*)b));
}

static void sum(void *a)
{
    sums += *(int *)a;
}

/*---------------------Initial & Cleaning Tests-----------------*/
void suite_initial(void)
{

    LynxArrayListInitialFunctions(&hinstDLL,
                                  lynxArrayListFunctions);

    CU_ASSERT_PTR_NOT_NULL(hinstDLL);
    CU_ASSERT_PTR_NOT_NULL(lynxArrayListFunctions.LynxArrayListInit);
}

void suite_clean(void)
{
    CU_ASSERT_PTR_NOT_NULL(hinstDLL);
    LynxArrayListCleanFunctions(&hinstDLL,lynxArrayListFunctions);
    CU_ASSERT_PTR_NOT_NULL(lynxArrayListFunctions.LynxArrayListBsearch);
}
/*---------------------Functions tests-----------------*/
void function_Init(void)
{
    CU_ASSERT_PTR_NOT_NULL(lynxArrayListFunctions.LynxArrayListInit);
    if (lynxArrayListFunctions.LynxArrayListInit != NULL)
    {
        lynxArrayListFunctions.LynxArrayListInit(&myArrayList, 10);
    }
    CU_ASSERT_PTR_NOT_NULL(myArrayList);
}

void function_IsEmpty(void)
{
    BOOL isEmpty = FALSE;
    CU_ASSERT_PTR_NOT_NULL(lynxArrayListFunctions.LynxArrayListIsEmpty);
    if (lynxArrayListFunctions.LynxArrayListIsEmpty != NULL)
    {
        isEmpty = lynxArrayListFunctions.LynxArrayListIsEmpty(myArrayList);
    }
    CU_ASSERT_TRUE(isEmpty);
}

void function_Length(void)
{
    long int length = -1;
    CU_ASSERT_PTR_NOT_NULL(lynxArrayListFunctions.LynxArrayListLength);
    if (lynxArrayListFunctions.LynxArrayListLength != NULL)
    {
        length = lynxArrayListFunctions.LynxArrayListLength(myArrayList);
    }
    CU_ASSERT_EQUAL(length,0);
}

void function_GetElem(void)
{
    void *target = NULL;
    CU_ASSERT_PTR_NOT_NULL(lynxArrayListFunctions.LynxArrayListGetElem);
    if (lynxArrayListFunctions.LynxArrayListGetElem != NULL)
    {
        target = lynxArrayListFunctions.LynxArrayListGetElem(myArrayList,0);
    }
    CU_ASSERT_PTR_NOT_NULL(target);
}

void function_LocateElem(void)
{
    long target = -1;
    CU_ASSERT_PTR_NOT_NULL(lynxArrayListFunctions.LynxArrayListLocateElem);
    if (lynxArrayListFunctions.LynxArrayListLocateElem != NULL)
    {
        target = lynxArrayListFunctions.LynxArrayListLocateElem(myArrayList,&myTarget,compare);
    }
    CU_ASSERT_EQUAL(target,0);
}

void function_Insert(void)
{
    BOOL success = FALSE;
    CU_ASSERT_PTR_NOT_NULL(lynxArrayListFunctions.LynxArrayListInsert);
    if (lynxArrayListFunctions.LynxArrayListInsert != NULL)
    {
        success = lynxArrayListFunctions.LynxArrayListInsert(myArrayList,0,&myTarget);
        success = lynxArrayListFunctions.LynxArrayListInsert(myArrayList,1,&myTarget);
        success = lynxArrayListFunctions.LynxArrayListInsert(myArrayList,2,&myTarget);
    }
    CU_ASSERT_TRUE(success);
}

void function_GetAndDelete(void)
{
    int *ans = NULL;
    CU_ASSERT_PTR_NOT_NULL(lynxArrayListFunctions.LynxArrayListGetAndDelete);
    if (lynxArrayListFunctions.LynxArrayListGetAndDelete != NULL)
    {
        ans = lynxArrayListFunctions.LynxArrayListGetAndDelete(myArrayList,0);
    }
    CU_ASSERT_PTR_NOT_NULL(ans);
}

void function_Traverse(void)
{
    CU_ASSERT_PTR_NOT_NULL(lynxArrayListFunctions.LynxArrayListTraverse);
    if (lynxArrayListFunctions.LynxArrayListTraverse != NULL)
    {
        lynxArrayListFunctions.LynxArrayListTraverse(myArrayList,sum);
    }
    CU_ASSERT_EQUAL(sums,20);
}

void function_Qsort(void)
{
    CU_ASSERT_PTR_NOT_NULL(lynxArrayListFunctions.LynxArrayListQsort);
    if(lynxArrayListFunctions.LynxArrayListQsort != NULL)
    {
        lynxArrayListFunctions.LynxArrayListQsort(myArrayList,compare);
    }
    if(NULL != myArrayList)
    {
        CU_ASSERT_TRUE((*myArrayList).sorted);
    }
}

void function_Bsearch(void)
{
    int *ans = NULL;
    CU_ASSERT_PTR_NOT_NULL(lynxArrayListFunctions.LynxArrayListBsearch);
    if(lynxArrayListFunctions.LynxArrayListBsearch != NULL)
    {
        ans = lynxArrayListFunctions.LynxArrayListBsearch(myArrayList,compare,&myTarget);
    }
    CU_ASSERT_PTR_NOT_NULL(ans);
}
