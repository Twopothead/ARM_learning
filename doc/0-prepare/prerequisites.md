# ARM Learning preparation

- Copyright (C) 2018  Frank Curie(邱日)

Prerequisites
-------------

- install arm-gcc
```sh
# gcc-arm-none-eabi (without an OS)
sudo apt-get install gcc-arm-none-eabi
# apt search "gcc-5-arm"
# gcc-5-arm-linux-gnueabi/bionic,bionic 5.5.0-10ubuntu1cross1 amd64 GNU C compiler
sudo apt-get install  gcc-5-arm-linux-gnueabihf
sudo apt-get install  gcc-arm-linux-gnueabihf
```
- install openocd
```sh
# http://fun-tech.se/stm32/OpenOCD/index.php
sudo apt-get install openocd
# wget http://openocd.berlios.de/doc/pdf/openocd.pdf
```

- install qemu for ARM

```shell
sudo apt-get install qemu-system-arm
sudo apt-get install qemu-user-static 
```
- install gdb for ARM
```shell
 sudo apt install gdb-multiarch
```
- install u-boot (optional)
```shell
sudo apt-get install u-boot-tools 
```

- install IDA for Linux
[IDA Freeware for Linux](https://www.hex-rays.com/products/ida/support/download_freeware.shtml)
(Installation Directory [/opt/idafree-7.0])
```shell
# https://out7.hex-rays.com/files/idafree70_linux.run
sudo chmod 777 idafree70_linux.run
sudo ./idafree70_linux.run
cd /opt/idafree-7.0
./ida64
```
- install J-Link for Linux

    - [J-Link Software and Documentation pack for Linux, DEB installer, 64-bit](https://www.segger.com/downloads/jlink#J-LinkSoftwareAndDocumentationPack)
```shell
# https://www.segger.com/downloads/jlink/JLink_Linux_x86_64.deb
sudo chmod 777 JLink_Linux_V630k_x86_64.deb
sudo dpkg -i JLink_Linux_V630k_x86_64.deb 
# /opt/SEGGER/JLink /opt/SEGGER/JLink_V630k
# J-Link has a dependency on libusb
sudo apt-get install libusb-dev
sudo apt-get install libusb-1.0-0-dev
```
- install qemu-stm32
```
# download from address:https://beckus.github.io/qemu_stm32/

```

[QEMU with an STM32 microcontroller implementation](http://beckus.github.io/qemu_stm32/)

- install qemu-system-gnuarmeclipse 
```
https://github.com/gnu-mcu-eclipse/qemu
```


"Hello World" in Assembly
-------------

- [Tutorial](https://community.arm.com/processors/b/blog/posts/hello-world-in-assembly) (assembly for ARM architect)
```shell
qemu-system-arm -machine lm3s811evb -kernel firmware.elf
```
http://www.bravegnu.org/gnu-eprog/hello-arm.html

https://github.com/Twopothead/vscode_template_stm32f103


FAQ
-------------
- Why machine "lm3s811evb" for Cortex-M3?

As well as the more common "A-profile" CPUs (which have MMUs and will run Linux) we also support the **Cortex-M3** and Cortex-M4 "M-profile" CPUs (which are microcontrollers used in very embedded boards. We only have two boards which use the M-profile CPU at the moment: **"lm3s811evb"** and "lm3s6965evb" (which are both TI Stellaris evaluation boards).[[1]](https://wiki.qemu.org/Documentation/Platforms/ARM)
```shell
 qemu-system-arm -machine help
 # Supported machines in qemu-system-arm
```
More infomation about machine  [**"lm3s811evb"**](http://www.ti.com.cn/cn/lit/ml/spmt196b/spmt196b.pdf),(which is a  Cortex™-M3-based microcontroller):

- [**lm3s6965evb** Stellaris LM3S6965EVB ](http://www.ti.com.cn/cn/lit/ml/spmt196b/spmt196b.pdf)
- [Qemu for Cortex M3](https://blog.csdn.net/zoomdy/article/details/50582557)

-----------------------------

- How to access IDA through the Dash
    - ```sh
       cd  ~/.local/share/applications
       # pwd /home/curie/.local/share/applications
       sudo vim IDA\ Free.desktop
       sudo chmod x+ IDA\ Free.desktop
      ``` 
    - contents of the file "IDA Free.desktop":
```
[Desktop Entry]
Type=Application
Version=0.9.4
Name=IDA Free
Comment=Interactive Disassembler Free
Icon=/opt/idafree-7.0/appico64.png
Exec=/opt/idafree-7.0/ida64
Terminal=false

```

- IDE 
```
stm32f103zet6
platformio (VScode extension) for stm32
http://docs.platformio.org/en/latest/tutorials/ststm32/stm32cube_debugging_unit_testing.html
```
- Where to download STM32F10x standard libarary?
    - **recommended**: *[rtenv](https://github.com/embedded2013/rtenv)*
    ```shell
    git clone https://github.com/embedded2013/rtenv
    cd /libraries/STM32F10x_StdPeriph_Driver
    ```
    - [stm32](https://github.com/ShawnHuang/stm32)
    - [STM32F10x_StdPeriph_Lib_V3.5.0](https://github.com/shenyiqun/STM32F10x_StdPeriph_Lib_V3.5.0/)

- Differences between "none-eabi","gnueabihf","linux-gnueabi",etc.
    - [ARM交叉编译器GNUEABI、NONE-EABI、ARM-EABI、GNUEABIHF等的区别](https://www.cnblogs.com/deng-tao/p/6432578.html)
    - [交叉编译工具链命名规则](http://www.veryarm.com/296.html)
    ```
    arch [-vendor] [-os] [-(gnu)eabi]
    "eabi" is short for Embedded Application Binary Interface
    - arm-none-eabi-gcc *裸机* (not target an OS,complies with the ARM EABI,using Newlib)
    - arm-none-linux-eabi     ( Application ,for Linux, using Glibc)
    - armcc (the compiler in Keil MDK)
    ```
 - Assembler Directives 
 http://web.mit.edu/gnu/doc/html/as_7.html
    
 - 
 ```shell
 arm-none-eabi-gcc -v
 # Configured with: ../src/configure --build=x86_64-linux-gnu
 ```   
 we should use 32bits gcc


stm32 vscode
https://blog.csdn.net/zhengyangliu123/article/details/54799908
https://blog.csdn.net/zhengyangliu123/article/details/79090601


References
-------------
- [1]https://wiki.qemu.org/Documentation/Platforms/ARM
- [2]https://blog.csdn.net/zoomdy/article/details/50582557
- [3][Cross Compile](https://bbs.pediy.com/thread-220907.htm)
- [4]https://stackoverflow.com/questions/38443734/how-to-compile-stm32f103-program-on-ubuntu
- [5]http://fun-tech.se/stm32/gcc/compile_blinky.php
- [6]https://github.com/jserv/armv8-hello
- [7]https://wiki.osdev.org/ARM_Overview
- [8]https://dev.to/rulyrudel/how-to-execute-u-boot-on-qemu-system-arm-2b22
- [9]https://www.linuxidc.com/Linux/2011-03/33231.htm
- [10]https://github.com/beckus/qemu_stm32
- [11]https://blog.csdn.net/zhengyangliu123/article/details/54799908
- [12][STM32高级开发系列教程](https://blog.csdn.net/zhengyangliu123/article/details/79090601）