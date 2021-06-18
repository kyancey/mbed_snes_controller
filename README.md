
# mbed_snes_controller

Functions that allow an mbed compatible microcontroller to emulate an SNES controller.


## Authors

- [@kyancey](https://www.github.com/kyancey)

  
## Documentation

The code is pretty much self-explanatory. Remember that this program emulates
an SNES controller. It does not read the signal from a controller. It sends
data to the SNES.

#### Physically Connecting to the SNES
From experience, forcing jumper wires with female head adapters
onto the pins on the SNES controller input slots **does not work**. The easiest way
to interface with the SNES is to cut the cord of a genuine or knock-off controller to
get to the individual wires. This will leave you with an SNES compatible connnector that
can simply be plugged into the SNES. These wires will use a very thin braided wire that
is not stiff enough to use in a breadboard. Do not attempt it. The wires will tear.
You can either straighten these wires and dip them in solder to make ad-hoc jumper wires,
or you can use other attachment methods to connect them to jumper wires in order to
bridge them to the breadboard.

#### Pin Assignment and Data Wires
You will have to alter the pin assignments at the top of program
to match with how your wires are configured. The SNES controller
wire pinout is available [here](https://pinoutguide.com/Game/snescontroller_pinout.shtml).
Only three wires actually carry data so only three pins are needed.
The other two relevant wires are VCC and GND.

#### Voltage Requirements
**Note**: Remember that the microcontroller is acting
as the controller, which is a _receiver of power_. You can power your device from the 5V supply
provided by the SNES or provide external power. The SNES in turn will expect a signal voltage of 5V.
So if your microcontroller is a 3.3V device, you will need to either rely on any available 5V pins
or shift the pin output voltage. However, it's possible 3.3V would still be high enough to trigger
a high state. This hasn't been tested.

#### Calling the Code
The function definition is:

    // The SNES expects unpressed buttons to have a high state.
    // 1 = unpressed, 0 = pressed
    void sendButtonsPressed(int b, int y, int select, int start,
                            int up, int down, int left, int right,
                            int a, int x, int l1, int r1)

Invoking it is simple:

        sendButtonsPressed(unpress, unpress, unpress, unpress, //b,y,select,start
                           unpress, unpress, unpress, unpress, //up,down,left,right
                           press, unpress, unpress, unpress);  //a,x,l1,r1

Note that the SNES perceives the button to be held down if the signal stays the same
between polling cycles. So sending the signal to double tap a button would require
invoking sendButtonsPressed three times:

1. Button pressed
2. Button unpressed
3. Button pressed again

## Installation 

If you're using the mbed online compiler,
you can simply import the code
[here](https://os.mbed.com/users/kyancey/code/SNES_Controller/).
Otherwise, simply include the main.cpp file in your project and
rename it to whatever you desire.

## License

[MIT](https://choosealicense.com/licenses/mit/)

  
## Support

The code is provided as-is. However, if you have any questions, you
can contact me at kyancey@outlook.com. The code can easily be adapted
to work on non-mbed microcontroller such as the arduino or the raspberry pi.
