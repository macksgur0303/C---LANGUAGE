#include "IfxPort.h"
#include "Bsp.h"


#define LEDa         &MODULE_P00,1
#define LEDb         &MODULE_P00,2
#define LEDc         &MODULE_P00,3
#define LEDd         &MODULE_P00,9
#define LEDe         &MODULE_P00,10
#define LEDf         &MODULE_P00,11
#define LEDg         &MODULE_P00,12

#define LEDdp        &MODULE_P00,8

#define LED_C1        &MODULE_P33,1
#define LED_C2        &MODULE_P33,2
#define LED_C3        &MODULE_P33,3
#define LED_C4        &MODULE_P33,4

#define Button1   &MODULE_P33,12 // 오른쪽 버튼
#define Button2   &MODULE_P33,11 // 왼쪽 버튼
//#define WAIT_TIME   25.7
#define WAIT_TIME   1


int button_data1 = 0;
int button_data2 = 0;
int button_data3 = 0;
int start_flag   = 0;
int cnt          = 0;


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

    IfxPort_setPinMode(Button1, IfxPort_Mode_inputPullUp);
    IfxPort_setPinMode(Button2, IfxPort_Mode_inputPullUp);

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

void button_data(void){
    if(IfxPort_getPinState(Button1) == 0){
        button_data1++;
        button_data1 %= 2;
        waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 300));
    }
    if(IfxPort_getPinState(Button2) == 0){
        button_data2++;
        button_data2 %= 3;
        waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 300));
    }

}


void LED9(void)
{
    IfxPort_setPinLow(LEDa);
    IfxPort_setPinLow(LEDb);
    IfxPort_setPinLow(LEDc);
    IfxPort_setPinLow(LEDd);
    IfxPort_setPinLow(LEDe);
    IfxPort_setPinLow(LEDf);
    IfxPort_setPinHigh(LEDg);

}

void LED8(void)
{
    IfxPort_setPinHigh(LEDa);
    IfxPort_setPinLow(LEDb);
    IfxPort_setPinLow(LEDc);
    IfxPort_setPinHigh(LEDd);
    IfxPort_setPinHigh(LEDe);
    IfxPort_setPinHigh(LEDf);
    IfxPort_setPinHigh(LEDg);

}

void LED7(void)
{
    IfxPort_setPinLow(LEDa);
    IfxPort_setPinLow(LEDb);
    IfxPort_setPinHigh(LEDc);
    IfxPort_setPinLow(LEDd);
    IfxPort_setPinLow(LEDe);
    IfxPort_setPinHigh(LEDf);
    IfxPort_setPinLow(LEDg);

}

void LED6(void)
{
    IfxPort_setPinLow(LEDa);
    IfxPort_setPinLow(LEDb);
    IfxPort_setPinLow(LEDc);
    IfxPort_setPinLow(LEDd);
    IfxPort_setPinHigh(LEDe);
    IfxPort_setPinHigh(LEDf);
    IfxPort_setPinLow(LEDg);

}

void LED5(void)
{
    IfxPort_setPinHigh(LEDa);
    IfxPort_setPinLow(LEDb);
    IfxPort_setPinLow(LEDc);
    IfxPort_setPinHigh(LEDd);
    IfxPort_setPinHigh(LEDe);
    IfxPort_setPinLow(LEDf);
    IfxPort_setPinLow(LEDg);

}

void LED4(void)
{
    IfxPort_setPinLow(LEDa);
    IfxPort_setPinHigh(LEDb);
    IfxPort_setPinLow(LEDc);
    IfxPort_setPinLow(LEDd);
    IfxPort_setPinHigh(LEDe);
    IfxPort_setPinLow(LEDf);
    IfxPort_setPinLow(LEDg);

}

void LED3(void)
{
    IfxPort_setPinLow(LEDa);
    IfxPort_setPinHigh(LEDb);
    IfxPort_setPinLow(LEDc);
    IfxPort_setPinLow(LEDd);
    IfxPort_setPinLow(LEDe);
    IfxPort_setPinLow(LEDf);
    IfxPort_setPinLow(LEDg);

}

void LED2(void)
{
    IfxPort_setPinLow(LEDa);
    IfxPort_setPinLow(LEDb);
    IfxPort_setPinLow(LEDc);
    IfxPort_setPinHigh(LEDd);
    IfxPort_setPinHigh(LEDe);
    IfxPort_setPinLow(LEDf);
    IfxPort_setPinHigh(LEDg);

}

void LED1(void)
{
    IfxPort_setPinLow(LEDa);
    IfxPort_setPinLow(LEDb);
    IfxPort_setPinLow(LEDc);
    IfxPort_setPinLow(LEDd);
    IfxPort_setPinLow(LEDe);
    IfxPort_setPinLow(LEDf);
    IfxPort_setPinLow(LEDg);

}

void LED0(void)
{
    IfxPort_setPinLow(LEDa);
    IfxPort_setPinLow(LEDb);
    IfxPort_setPinLow(LEDc);
    IfxPort_setPinLow(LEDd);
    IfxPort_setPinHigh(LEDe);
    IfxPort_setPinLow(LEDf);
    IfxPort_setPinLow(LEDg);

}

void num_turn1(int num)
{
    IfxPort_setPinLow(LED_C1);
    IfxPort_setPinLow(LED_C2);
    IfxPort_setPinLow(LED_C3);
    IfxPort_setPinHigh(LED_C4);

    switch (num)
    {
        case 0:
            LED0();
            break;
        case 1:
            LED1();
            break;
        case 2:
            LED2();
            break;
        case 3:
            LED3();
            break;
        case 4:
            LED4();
            break;
        case 5:
            LED5();
            break;
        case 6:
            LED6();
            break;
        case 7:
            LED7();
            break;
        case 8:
            LED8();
            break;
        case 9:
            LED9();
            break;
    // Add cases for LED1 to LED9
    default:
        break;
    }
}
void num_turn2(int num)
{
    IfxPort_setPinLow(LED_C1);
    IfxPort_setPinLow(LED_C2);
    IfxPort_setPinHigh(LED_C3);
    IfxPort_setPinLow(LED_C4);

    switch (num)
    {
        case 0:
            LED0();
            break;
        case 1:
            LED1();
            break;
        case 2:
            LED2();
            break;
        case 3:
            LED3();
            break;
        case 4:
            LED4();
            break;
        case 5:
            LED5();
            break;
        case 6:
            LED6();
            break;
        case 7:
            LED7();
            break;
        case 8:
            LED8();
            break;
        case 9:
            LED9();
            break;
    // Add cases for LED1 to LED9
    default:
        break;
    }
}
void num_turn3(int num)
{
    IfxPort_setPinLow(LED_C1);
    IfxPort_setPinHigh(LED_C2);
    IfxPort_setPinLow(LED_C3);
    IfxPort_setPinLow(LED_C4);

    switch (num)
    {
        case 0:
            LED0();
            break;
        case 1:
            LED1();
            break;
        case 2:
            LED2();
            break;
        case 3:
            LED3();
            break;
        case 4:
            LED4();
            break;
        case 5:
            LED5();
            break;
        case 6:
            LED6();
            break;
        case 7:
            LED7();
            break;
        case 8:
            LED8();
            break;
        case 9:
            LED9();
            break;
    // Add cases for LED1 to LED9
    default:
        break;
    }
}
void num_turn4(int num)
{
    IfxPort_setPinHigh(LED_C1);
    IfxPort_setPinLow(LED_C2);
    IfxPort_setPinLow(LED_C3);
    IfxPort_setPinLow(LED_C4);

    switch (num)
    {
        case 0:
            LED0();
            break;
        case 1:
            LED1();
            break;
        case 2:
            LED2();
            break;
        case 3:
            LED3();
            break;
        case 4:
            LED4();
            break;
        case 5:
            LED5();
            break;
        case 6:
            LED6();
            break;
        case 7:
            LED7();
            break;
        case 8:
            LED8();
            break;
        case 9:
            LED9();
            break;
    // Add cases for LED1 to LED9
    default:
        break;
    }
}


void misson1(){
    button_data();
    if(button_data1 == 1 && button_data2 == 0){
        cnt++;
        for(int i=0; i<25; i++){
            button_data();
            num_turn4(((cnt) - (cnt%1000))/1000);
            waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 1));
            num_turn3(((cnt%1000) - (cnt%100))/100);
            waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 1));
            num_turn2(((cnt%100) - (cnt%10))/10);
            waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 1));
            num_turn1(cnt%10);
            waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 1));
        }
    }

    if(button_data2 == 1){
        button_data1 = 0;
        num_turn4(((cnt) - (cnt%1000))/1000);
        waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 1));
        num_turn3(((cnt%1000) - (cnt%100))/100);
        waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 1));
        num_turn2(((cnt%100) - (cnt%10))/10);
        waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 1));
        num_turn1(cnt%10);
        waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 1));
    }

    if(button_data2 == 2){
        cnt = 0;
        button_data2 = 0;
        num_turn4(((cnt) - (cnt%1000))/1000);
        waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 1));
        num_turn3(((cnt%1000) - (cnt%100))/100);
        waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 1));
        num_turn2(((cnt%100) - (cnt%10))/10);
        waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 1));
        num_turn1(cnt%10);
        waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 1));
    }
}

void blinkLED(void)
{
    for(int i = 9; i >= 0; i--) {
        for(int j = 9; j >= 0; j--) {
            for(int k = 9; k >= 0; k--) {
                for(int e = 9; e >= 0; e--) {
                    button_data();
                    num_turn1(i);
                    waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 1));
                    num_turn2(j);
                    waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 1));
                    num_turn3(k);
                    waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 1));
                    num_turn4(e);
                    waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 1));
                    if(button_data1 != 1) break;
                }
                if(button_data1 != 1) break;
            }
            if(button_data1 != 1) break;
        }
        if(button_data1 != 1) break;
    }
    //IfxPort_togglePin(LEDb);
    //IfxPort_togglePin(LED_C2);
    //IfxPort_togglePin(LED_C3);
    //IfxPort_togglePin(LED_C4);
   // waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, WAIT_TIME));
}
