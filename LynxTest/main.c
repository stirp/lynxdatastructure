/** @brief 测试所用的主函数。应该把所有的东西移入相应的子函数去做测试才对
 *
 * @return int
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "LynxArrayList.h"
#include "Console.h"
#include "Tests.h"

int main(int argc, char* argv[])
{
    CU_BOOL Run = CU_FALSE ;

    setvbuf(stdout, NULL, _IONBF, 0);

    if (argc > 1)
    {
        if (!strcmp("-i", argv[1]))
        {
            Run = CU_TRUE ;
            CU_set_error_action(CUEA_IGNORE);
        }
        else if (!strcmp("-f", argv[1]))
        {
            Run = CU_TRUE ;
            CU_set_error_action(CUEA_FAIL);
        }
        else if (!strcmp("-A", argv[1]))
        {
            Run = CU_TRUE ;
            CU_set_error_action(CUEA_ABORT);
        }
        else
        {
            printf("\nUsage:  ConsoleTest [option]\n\n"
                   "Options:   -i   Run, ignoring framework errors [default].\n"
                   "           -f   Run, failing on framework error.\n"
                   "           -A   run, aborting on framework error.\n"
                   "           -h   Print this message.\n\n");
        }
    }
    else
    {
        Run = CU_TRUE;
        CU_set_error_action(CUEA_IGNORE);
    }

    if (CU_TRUE == Run)
    {
        if (CU_initialize_registry())
        {
            printf("\nInitialization of Test Registry failed.");
        }
        else
        {
            AddTests();
            CU_console_run_tests();
            CU_cleanup_registry();
        }
    }

    return 0;
}

//int main()
//{
//
//    LynxArrayListFunctions lynxArrayListFunctions;
//
//    HINSTANCE hinstDLL;
//
//     hinstDLL = LoadLibrary("libLynxArrayList.dll");
//
//    if (hinstDLL != NULL)
//    {
//        LynxArrayListInitialFunctions(
//            hinstDLL,
//            lynxArrayListFunctions
//            );
//    }
//    return 0;
//}
