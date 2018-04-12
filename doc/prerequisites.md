# ARM Learning preparation

- Copyright (C) 2018  Frank Curie(邱日)

Prerequisites
-------------

- install arm-gcc
```sh
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

"Hello World" in Assembly
-------------

- [Tutorial](https://community.arm.com/processors/b/blog/posts/hello-world-in-assembly) (assembly for ARM architect)
```shell
qemu-system-arm -machine lm3s811evb -kernel firmware.elf
```




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
----------------------
- Does GRUB2 support ARM?

[Yes.](https://en.wikipedia.org/wiki/Comparison_of_boot_loaders)

-----------------------
- qemu-user-static is already installed,but "qemu-user-static: Command not found".
```shell
sudo apt-get purge remove qemu-user-static
sudo rm /var/cache/apt/archives/qemu-user-static_1%3a2.11+dfsg-1ubuntu6_amd64.deb

```
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