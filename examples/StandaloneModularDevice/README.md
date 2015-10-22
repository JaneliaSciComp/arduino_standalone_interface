#StandaloneModularDevice

Authors:

    Peter Polidoro <polidorop@janelia.hhmi.org>

License:

    BSD

##More Detailed Help on Installation and Usage

[modular-devices](https://github.com/janelia-modular-devices/modular-devices)

##Device Information

```json
{
  "method":"?",
  "device_info":{
    "name":"standalone_modular_device",
    "model_number":1003,
    "serial_number":0,
    "firmware_version":{
      "major":0,
      "minor":1,
      "patch":0
    }
  },
  "methods":[
    "getMemoryFree",
    "resetDefaults",
    "setSerialNumber",
    "executeStandaloneCallback",
    "getDspVar1",
    "setDspVar1",
    "getIntVar1",
    "setIntVar1",
    "getIntVar2",
    "setIntVar2"
  ],
  "status":success
}
```

##Verbose Device Information

```json
{
  "method":"??",
  "device_info":{
    "name":"standalone_modular_device",
    "model_number":1003,
    "serial_number":0,
    "firmware_version":{
      "major":0,
      "minor":1,
      "patch":0
    }
  },
  "methods":{
    "getMemoryFree":{
      "parameters":{}
    },
    "resetDefaults":{
      "parameters":{}
    },
    "setSerialNumber":{
      "parameters":{
        "serial_number":{
          "type":"long",
          "min":0,
          "max":65535
        }
      }
    },
    "executeStandaloneCallback":{
      "parameters":{}
    },
    "getDspVar1":{
      "parameters":{}
    },
    "setDspVar1":{
      "parameters":{
        "dsp_var1":{
          "type":"long",
          "min":-32768,
          "max":32767
        }
      }
    },
    "getIntVar1":{
      "parameters":{}
    },
    "setIntVar1":{
      "parameters":{
        "int_var1":{
          "type":"long",
          "min":-10,
          "max":10
        }
      }
    },
    "getIntVar2":{
      "parameters":{}
    },
    "setIntVar2":{
      "parameters":{
        "int_var2":{
          "type":"long",
          "min":-9999,
          "max":12345
        }
      }
    }
  },
  "status":success
}
```
