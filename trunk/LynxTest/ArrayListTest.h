#ifndef ARRAYLISTTEST_H_INCLUDED
#define ARRAYLISTTEST_H_INCLUDED

/** @file ArrayListTest
    @brief arraylistTest的测试函数
*/

/** @def MAX(a,b)
    @brief A macro that returns the maximum of \a a and \a b.
    Details.
*/

/** @var typedef unsigned int UINT32
    @brief A type definition for a .
    Details.
*/

/** @var int errno
    @brief Contains the last error code.
    @warning Not thread safe!
*/

/** @fn int open(const char *pathname,int flags)
    @brief Opens a file descriptor.
    @param pathname The name of the descriptor.
    @param flags Opening flags.
    @return int an integer.
*/

/** @struct to document a C-struct.
    @union to document a union.
    @enum to document an enumeration type.
    @fn to document a function.
    @var to document a variable or typedef or enum value.
    @def to document a #define.
    @typedef to document a type definition.
    @file to document a file.
    @namespace to document a namespace.
*/

/*---------------------Initial & Cleaning Tests-----------------*/
void suite_initial(void);
void suite_clean(void);
/*---------------------Functions tests-----------------*/
void function_Init(void);
void function_IsEmpty(void);
void function_Length(void);
void function_GetElem(void);
void function_LocateElem(void);
void function_Insert(void);
void function_GetAndDelete(void);
void function_Traverse(void);
void function_Qsort(void);
void function_Bsearch(void);

#endif // ARRAYLISTTEST_H_INCLUDED
