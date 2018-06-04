Note: if your distribution already provides ready to run QEMU binaries, they currently cannot be used with the GNU MCU Eclipse plug-ins, because they lack the Cortex-M support; you need to install the GNU MCU Eclipse QEMU.

- https://github.com/gnu-mcu-eclipse/qemu
- [download](https://github.com/gnu-mcu-eclipse/qemu/releases/download/gae-2.8.0-20170301/gnuarmeclipse-qemu-debian64-2.8.0-201703022210-head.tgz)

```sh
cd /opt 
sudo cp /home/curie/Downloads/gnuarmeclipse-qemu-debian64-2.8.0-201703022210-head.tgz .
sudo tar xvf gnuarmeclipse-qemu-debian64-2.8.0-201703022210-head.tgz
sudo chmod -R -w /opt/gnuarmeclipse/qemu
chmod -R -w /opt/gnuarmeclipse/qemu/
# /opt/gnuarmeclipse/qemu/2.8.0-201703022210-head/bin/qemu-system-gnuarmeclipse
/opt/gnuarmeclipse/qemu/2.8.0-201703022210-head/bin/qemu-system-gnuarmeclipse  --board ?
```

```
Supported boards:
  Maple                LeafLab Arduino-style STM32 microcontroller board (r5)
  NUCLEO-F103RB        ST Nucleo Development Board for STM32 F1 series
  NUCLEO-F411RE        ST Nucleo Development Board for STM32 F4 series
  NetduinoGo           Netduino GoBus Development Board with STM32F4
  NetduinoPlus2        Netduino Development Board with STM32F4
  OLIMEXINO-STM32      Olimex Maple (Arduino-like) Development Board
  STM32-E407           Olimex Development Board for STM32F407ZGT6
  *** STM32-H103           Olimex Header Board for STM32F103RBT6 ***
  *** STM32-P103           Olimex Prototype Board for STM32F103RBT6 ***
  STM32-P107           Olimex Prototype Board for STM32F107VCT6
  STM32F0-Discovery    ST Discovery kit for STM32F051 line
  STM32F4-Discovery    ST Discovery kit for STM32F407/417 lines
  STM32F429I-Discovery ST Discovery kit for STM32F429/439 lines
  generic              Generic Cortex-M board; use -mcu to define the device

```