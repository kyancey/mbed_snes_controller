#include "mbed.h"


DigitalOut Data(D2);
DigitalIn Latch(D3);
DigitalIn Clock(D4);

int unpress = 1;
int press = 0;

void waitUntilHigh(DigitalIn x)
{
    while(x != 1) {};
}

void waitUntilLow(DigitalIn x)
{
    while(x == 1) {};
}

void sendButton(int button)
{
    Data = button;
    waitUntilLow(Clock);
    waitUntilHigh(Clock);
}

// The SNES expects unpressed buttons to have a high state.
// 1 = unpressed, 0 = pressed
void sendButtonsPressed(int b, int y, int select, int start,
                        int up, int down, int left, int right,
                        int a, int x, int l1, int r1)
{
    Data = 1; // Seems sensible to start with data being high
    waitUntilHigh(Latch);
    waitUntilLow(Latch);

    sendButton(b);
    sendButton(y);
    sendButton(select);
    sendButton(start);
    sendButton(up);
    sendButton(down);
    sendButton(left);
    sendButton(right);
    sendButton(a);
    sendButton(x);
    sendButton(l1);
    sendButton(r1);
}

int main()
{
    while(1) {
        // Repeatedly press A
        sendButtonsPressed(unpress, unpress, unpress, unpress, //b,y,select,start
                           unpress, unpress, unpress, unpress, //up,down,left,right
                           press, unpress, unpress, unpress);  //a,x,l1,r1
        // We send a pulse with A unpressed so the SNES doesn't see
        // the button as being held down
        sendButtonsPressed(unpress, unpress, unpress, unpress, //b,y,select,start
                           unpress, unpress, unpress, unpress, //up,down,left,right
                           unpress, unpress, unpress, unpress); //a,x,l1,r1
    }
}
