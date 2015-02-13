StandaloneModularDevice
=======================

Authors:

    Peter Polidoro <polidorop@janelia.hhmi.org>

License:

    BSD

###Host Computer Interface

####Arduino Serial Monitor

Open the Serial Monitor in the Arduino IDE.

Set the baudrate to match the value in the Arduino sketch (9600).

Set the line ending to 'Newline'.

To get help information about the Arduino device, type a single
question mark ? into the input field and press the 'Send' button or
press the 'Enter' key.

```shell
?
```

Example Response:

```json
{
  "method":"?",
  "device_info":{
    "name":"standalone_modular_device",
    "model_number":1003,
    "serial_number":0,
    "firmware_number":1
  },
  "methods":[
    "getMemoryFree",
    "resetDefaults",
    "setSerialNumber",
    "getDisplayVariable1",
    "setDisplayVariable1",
    "getInteractiveVariable1",
    "setInteractiveVariable1",
    "getInteractiveVariable2",
    "setInteractiveVariable2"
  ],
  "status":success
}
```

####Python

Example Python session:

```python
from modular_device import ModularDevice
dev = ModularDevice() # Automatically finds device if one available
dev.get_device_info()
```

For more details on the Python interface:

<https://github.com/JaneliaSciComp/modular_device_python>

####Matlab

Example Matlab session:

```matlab
% Linux and Mac OS X
ls /dev/tty*
serial_port = '/dev/ttyACM0'     % example Linux serial port
serial_port = '/dev/tty.usbmodem262471' % example Mac OS X serial port
% Windows
getAvailableComPorts()
serial_port = 'COM4'             % example Windows serial port
dev = ModularDevice(serial_port) % creates a device object
dev.open()                       % opens a serial connection to the device
device_info = dev.getDeviceInfo()
```

For more details on the Matlab interface:

<https://github.com/JaneliaSciComp/modular_device_matlab>

##Installation

###Install This Library and its Dependencies Together

<https://github.com/JaneliaSciComp/arduino-libraries>
