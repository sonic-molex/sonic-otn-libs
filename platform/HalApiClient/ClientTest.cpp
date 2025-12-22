#include <iostream>
#include "Convert.h"

/*******************************INSTRUCTION*************************************/
/* When installed client deb, the include file path should be halapi/xxxx.h.   */
/* eg:                                                                         */
/*    #include <halapi/DevBoardCApi.h>                                         */
/*    #include <halapi/DevEdfaCApi.h>                                          */
/*******************************************************************************/

#define printobj(f, r, o) \
do {\
    std::cout << #f << ", res = " << r << std::endl;\
    o.printTo(std::cout);\
    std::cout << std::endl;\
} while(0)

int main(void)
{
    CMfg mfg = {0};
    int32_t res = BOARD_GetChassisMfg(&mfg);
    CMfg_t mfg_t;
    Convert::ToCMfg_t(mfg_t, mfg);
    printobj(BOARD_GetChassisMfg, res, mfg_t);

    return 0;
}