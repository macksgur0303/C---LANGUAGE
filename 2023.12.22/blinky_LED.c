#include "IfxPort.h"
#include "Bsp.h"


#define LEDa          &MODULE_P00,1
#define LEDb          &MODULE_P00,2
#define LEDc          &MODULE_P00,3
#define LEDd          &MODULE_P00,9
#define LEDe          &MODULE_P00,10
#define LEDf          &MODULE_P00,11
#define LEDg          &MODULE_P00,12

#define LEDdp         &MODULE_P00,8

#define LED_C1        &MODULE_P33,1
#define LED_C2        &MODULE_P33,2
#define LED_C3        &MODULE_P33,3
#define LED_C4        &MODULE_P33,4

#define btnL          &MODULE_P33,5
#define btnR          &MODULE_P33,6 

int delay = 1000;
int btnL_cnt = 0;
int btnR_cnt = 0;

void initLED(void)
{
    IfxPort_setPinModeOutput(LEDa, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinModeOutput(LEDb, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinModeOutput(LEDc, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinModeOutput(LEDd, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinModeOutput(LEDe, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinModeOutput(LEDf, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinModeOutput(LEDg, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);

    IfxPort_setPinModeOutput(LED_C1, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinModeOutput(LED_C2, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinModeOutput(LED_C3, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinModeOutput(LED_C4, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);

    IfxPort_setPinMode(btnL, IfxPort_Mode_inputPullUp);
    IfxPort_setPinMode(btnR, IfxPort_Mode_inputPullUp);

    IfxPort_setPinLow(LEDa);
    IfxPort_setPinLow(LEDb);
    IfxPort_setPinLow(LEDc);
    IfxPort_setPinLow(LEDd);
    IfxPort_setPinLow(LEDe);
    IfxPort_setPinLow(LEDf);
    IfxPort_setPinLow(LEDg);
    IfxPort_setPinHigh(LEDdp);

    IfxPort_setPinHigh(LED_C1);
    IfxPort_setPinHigh(LED_C2);
    IfxPort_setPinHigh(LED_C3);
    IfxPort_setPinHigh(LED_C4);
}
///////////////////////////////////////////btn 옛날 입출력 함수///////////////////////////////////////////////////////
/*
void Btn_Output(int btn_L, int btn_R)
{
    if(btn_L > 0 && btn_R > 0)
    {
        if((btn_L + 50) >= btn_R ||  (btn_L - 50) <= btn_R)
        {
            int cnt = 0;
            Size(22, 0);
            while(1)
            {
                if(IfxPort_getPinState(btnL) == 0 && IfxPort_getPinState(btnR) == 0)
                {
                    cnt++;
                    if(cnt >= 300)
                        break;
                }
                
                cnt = 0;
            }
        }
        
        else
        {
            if(btn_L >= btn_R)
                delay -= btn_L;
            else
                delay += btn_R;
        }
        
    }
    
    if(btn_L > 0 && btn_R == 0)
        delay += btn_L;

    if(btn_L == 0 && btn_R > 0)
        delay -= btn_R;
    
    if(delay < 5)
        delay = 0;
    if(delay > 1000)
        delay = 1000;
    
    waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 10));
}

void Btn_Input()
{
    int btnL_cnt = 0;
    int btnR_cnt = 0;
    
    while(IfxPort_getPinState(btnL) == 1 && IfxPort_getPinState(btnR) == 1)
    {
        
        if(IfxPort_getPinState(btnL) == 0)
        {
            btnL_cnt++;
            waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 100));
        }
        if(IfxPort_getPinState(btnR) == 0)
        {
            btnR_cnt++;
            waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 100));
        }

        waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 10));
    }
    
    Btn_Output(btnR_cnt, btnL_cnt);
            
    btnL_cnt = 0;
    btnR_cnt = 0;

}

*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////
void Btn_Input()
{
    if(IfxPort_getPinState(btnL) == 0)
    {
        btnL_cnt++;
        waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 10));
        blinkLED();
    }
}

void Btn_Output()
{
    while(btnL_cnt != 1)
    {
        if(IfxPort_getPinState(btnL) == 0)
        {
            btnL_cnt++;
            waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 10));
        }
        
        if(IfxPort_getPinState(btnL) == 0)
        {
            btnR_cnt++;
            waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 10));
        }
        
        if(btnL_cnt == 1 && btnR_cnt == 1)
        {
            btnL_cnt = 0;
            btnR_cnt = 0;
            blinkLED();
        }
        
        if(btnL_cnt > 1)
            btnL_cnt = 0;
       
    }
}

void On_Seg(int num)
{
    switch(num)
    {
        case 22:
            IfxPort_setPinLow(LEDa);
            IfxPort_setPinLow(LEDb);
            IfxPort_setPinLow(LEDc);
            IfxPort_setPinLow(LEDd);
            IfxPort_setPinLow(LEDe);
            IfxPort_setPinLow(LEDf);
            IfxPort_setPinLow(LEDg);
            break;
        case 0:
            IfxPort_setPinLow(LEDa);
            IfxPort_setPinLow(LEDb);
            IfxPort_setPinLow(LEDc);
            IfxPort_setPinLow(LEDd);
            IfxPort_setPinLow(LEDe);
            IfxPort_setPinLow(LEDf);
            IfxPort_setPinHigh(LEDg);
            break;
        case 1:
            IfxPort_setPinLow(LEDa);
            IfxPort_setPinHigh(LEDb);
            IfxPort_setPinHigh(LEDc);
            IfxPort_setPinLow(LEDd);
            IfxPort_setPinLow(LEDe);
            IfxPort_setPinLow(LEDf);
            IfxPort_setPinLow(LEDg);
            break;
        case 2:
            IfxPort_setPinLow(LEDa);
            IfxPort_setPinLow(LEDb);
            IfxPort_setPinHigh(LEDc);
            IfxPort_setPinLow(LEDd);
            IfxPort_setPinLow(LEDe);
            IfxPort_setPinHigh(LEDf);
            IfxPort_setPinLow(LEDg);
            break;
        case 3:
            IfxPort_setPinLow(LEDa);
            IfxPort_setPinLow(LEDb);
            IfxPort_setPinLow(LEDc);
            IfxPort_setPinLow(LEDd);
            IfxPort_setPinHigh(LEDe);
            IfxPort_setPinHigh(LEDf);
            IfxPort_setPinLow(LEDg);
            break;
        case 4:
            IfxPort_setPinHigh(LEDa);
            IfxPort_setPinLow(LEDb);
            IfxPort_setPinLow(LEDc);
            IfxPort_setPinHigh(LEDd);
            IfxPort_setPinHigh(LEDe);
            IfxPort_setPinLow(LEDf);
            IfxPort_setPinLow(LEDg);
            break;
        case 5:
            IfxPort_setPinLow(LEDa);
            IfxPort_setPinHigh(LEDb);
            IfxPort_setPinLow(LEDc);
            IfxPort_setPinLow(LEDd);
            IfxPort_setPinHigh(LEDe);
            IfxPort_setPinLow(LEDf);
            IfxPort_setPinLow(LEDg);
            break;
        case 6:
            IfxPort_setPinLow(LEDa);
            IfxPort_setPinLow(LEDb);
            IfxPort_setPinLow(LEDc);
            IfxPort_setPinLow(LEDd);
            IfxPort_setPinLow(LEDe);
            IfxPort_setPinLow(LEDf);
            IfxPort_setPinLow(LEDg);
            break;
        case 7:
            IfxPort_setPinLow(LEDa);
            IfxPort_setPinHigh(LEDb);
            IfxPort_setPinLow(LEDc);
            IfxPort_setPinLow(LEDd);
            IfxPort_setPinLow(LEDe);
            IfxPort_setPinLow(LEDf);
            IfxPort_setPinLow(LEDg);
            break;
        case 8:
            IfxPort_setPinLow(LEDa);
            IfxPort_setPinLow(LEDb);
            IfxPort_setPinLow(LEDc);
            IfxPort_setPinLow(LEDd);
            IfxPort_setPinLow(LEDe);
            IfxPort_setPinLow(LEDf);
            IfxPort_setPinLow(LEDg);
            break;
        case 9:
            IfxPort_setPinLow(LEDa);
            IfxPort_setPinLow(LEDb);
            IfxPort_setPinLow(LEDc);
            IfxPort_setPinLow(LEDd);
            IfxPort_setPinHigh(LEDe);
            IfxPort_setPinLow(LEDf);
            IfxPort_setPinLow(LEDg);
            break;
    }
}
void Size(int num, int len)
{
    switch(len)
    {
        case 0:
            IfxPort_setPinHigh(LED_C1);
            IfxPort_setPinHigh(LED_C2);
            IfxPort_setPinHigh(LED_C3);
            IfxPort_setPinHigh(LED_C4);
            break;
        case 1:
            IfxPort_setPinLow(LED_C1);
            IfxPort_setPinLow(LED_C2);
            IfxPort_setPinLow(LED_C3);
            IfxPort_setPinHigh(LED_C4);
            break;
        case 10:
            IfxPort_setPinLow(LED_C1);
            IfxPort_setPinLow(LED_C2);
            IfxPort_setPinHigh(LED_C3);
            IfxPort_setPinLow(LED_C4);
            break;
        case 100:
            IfxPort_setPinLow(LED_C1);
            IfxPort_setPinHigh(LED_C2);
            IfxPort_setPinLow(LED_C3);
            IfxPort_setPinLow(LED_C4);
            break;
        case 1000:
            IfxPort_setPinHigh(LED_C1);
            IfxPort_setPinLow(LED_C2);
            IfxPort_setPinLow(LED_C3);
            IfxPort_setPinLow(LED_C4);
            break;
    }
    
    On_Seg(num);
    
}



void blinkLED(void)
{

    while(1)
    {
        for(int i = 0; i <= 9999; i++)
        {
            if(IfxPort_getPinState(btnL) == 0 || IfxPort_getPinState(btnR) == 0)
            {
                //Btn_Input();
                Btn_Output();
            }
            else
            {
                if(i % 10 >= 0)         // 1의 자리
                    Size(i % 10, 1);
                if((i / 10) % 10 > 0)   // 10의 자리
                    Size((i / 10) % 10, 10);
                if((i / 100) % 10 > 0)  // 100의 자리
                    Size((i / 100) % 10, 100);
                if((i / 1000) % 10 > 0) // 1000의 자리
                    Size((i / 1000) % 10, 1000);
            }
        }
            
    
        
        for(int i = 9999; i >= 0; i--)
        {
            if(IfxPort_getPinState(btnL) == 0 || IfxPort_getPinState(btnR) == 0)
            {
                //Btn_Input();
                Btn_Output();
            }
            else
            {
                if(i % 10 >= 0)         // 1의 자리
                    Size(i % 10, 1);
                if((i / 10) % 10 > 0)   // 10의 자리
                    Size((i / 10) % 10, 10);
                if((i / 100) % 10 > 0)  // 100의 자리
                    Size((i / 100) % 10, 100);
                if((i / 1000) % 10 > 0) // 1000의 자리
                    Size((i / 1000) % 10, 1000);
            }
        }
    
        waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, delay));
    }
}
