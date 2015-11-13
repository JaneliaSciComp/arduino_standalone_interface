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
  "status":"success"
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
  "methods":[
    {
      "name":"getMemoryFree",
      "parameters":[],
      "return":"long"
    },
    {
      "name":"resetDefaults",
      "parameters":[],
      "return":null
    },
    {
      "name":"setSerialNumber",
      "parameters":[
        {
          "name":"serial_number",
          "type":"long",
          "min":0,
          "max":65535
        }
      ],
      "return":null
    },
    {
      "name":"executeStandaloneCallback",
      "parameters":[],
      "return":null
    },
    {
      "name":"getDspVar1",
      "parameters":[],
      "return":null
    },
    {
      "name":"setDspVar1",
      "parameters":[
        {
          "name":"dsp_var1",
          "type":"long",
          "min":-32768,
          "max":32767
        }
      ],
      "return":null
    },
    {
      "name":"getIntVar1",
      "parameters":[],
      "return":null
    },
    {
      "name":"setIntVar1",
      "parameters":[
        {
          "name":"int_var1",
          "type":"long",
          "min":-10,
          "max":10
        }
      ],
      "return":null
    },
    {
      "name":"getIntVar2",
      "parameters":[],
      "return":null
    },
    {
      "name":"setIntVar2",
      "parameters":[
        {
          "name":"int_var2",
          "type":"long",
          "min":-9999,
          "max":12345
        }
      ],
      "return":null
    }
  ],
  "status":"success"
}
```
