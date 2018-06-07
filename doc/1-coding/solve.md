### 1.解压rar压缩文件乱码问题

```sh
file -i 要查看其编码的文件.txt
```

```shell
sudo apt-get install enca
enca -L zh_CN -x utf-8 *
```

https://stackoverflow.com/questions/231229/how-to-generate-a-makefile-with-source-in-sub-directories-using-just-one-makefil

https://blog.csdn.net/HMSIWTV/article/details/20905177

https://stackoverflow.com/questions/13897945/wildcard-to-obtain-list-of-all-directories

https://wiki.osdev.org/Makefile

https://github.com/sczh01/lnx_drv/blob/d90bd6730423988c7586e5423bacd9cb15f3fa19/Makefile.bak

https://www.cnblogs.com/catgatp/p/6534249.html

### wildcard-to-obtain-list-of-all-directories

Use `sort` and `dir` functions together with `wildcard`:

```
DIRECTORY = $(sort $(dir $(wildcard ../Test/*/)))

```

From GNU make manual:

> $(dir names...) Extracts the directory-part of each file name in names. The directory-part of the file name is everything up through (and including) the last slash in it. If the file name contains no slash, the directory part is the string ‘./’.
>
> $(sort list) Sorts the words of list in lexical order, removing duplicate words. The output is a list of words separated by single spaces.

http://people.ece.cornell.edu/land/courses/ece4760/

https://stackoverflow.com/questions/1932904/make-wildcard-subdirectory-targets

### ST-link用法

https://steward-fu.github.io/website/mcu/stm32f103/n900_stlink-v2_flash.htm

https://github.com/steward-fu

## Undefined references with Newlib

newlib/libc/reent/writer.c:58: undefined reference to `_write'

The Code Sourcery Lite tool chain is provided with the [newlib](http://sourceware.org/newlib/) C Library from Redhat. Because this is an embedded toolchain some stub functions known as System Functions must be provided by the embedded system that would normally be provided by a host operating system.

The is shown by the fact that if you try to compile a C program that uses printf you will see the following error message:

 n function `_write_r':writer.c:(.text+0x16): undefined reference to `_write'

解决办法就是在main函数中删去printf

  // printf("\r\n");
  // printf("nes emulator for stm32f103tb\r\n");

删去printf

https://blog.csdn.net/zhengyangliu123/article/details/54966402

这里需要大家明白的是，GNU C 与 KEIL C 下的标准库函数实际上都是各个不同的机构组织编写的，虽然他们符合不同时期的C标准，如C89、C99等，那也只是用户层的API相同（同时要明白他们这些标准库是属于编译器的一部分的，就储存在编译器路径下的lib文件夹中）。虽然上层被调用的标准C函数相同，但是他们各有各的实现方式，他们在底层实现是可能完全不同的样子。所以在我们更换工具链后，一定要注意自己工程中的代码不一定会适应新的工具链开发环境。

我之前使用的是Keil环境的usart而GNU对usart实现并不一样，需要用GNU的方法实现usart

http://www.openstm32.org/forumthread1055

https://electronics.stackexchange.com/questions/206113/how-do-i-use-the-printf-function-on-stm32

http://www.exodusamps.com/Exodusamps/Embedded_Stuff/Entries/2012/2/8_Use_printf()_on_STM32_in_CoIDE.html

keyword: stm32 gnu remap printf

> The way I got printf (and all other console-oriented stdio functions) to work was by creating custom implementations of the low-level I/O functions like `_read()` and `_write()`.
>
> The GCC C library makes calls to the following functions to perform low-level I/O :
>
> ```
> int _read(int file, char *data, int len)
> int _write(int file, char *data, int len)
> int _close(int file)
> int _lseek(int file, int ptr, int dir)
> int _fstat(int file, struct stat *st)
> int _isatty(int file)
>
> ```
>
> These functions are implemented witihin the GCC C library as stub routines with "weak" linkage. If a declaration of any of the above functions appears in your own code, your substitute routine will override the declaration in the library and be used instead of the default (non-functional) routine.

I used STM32CubeMX to setup USART1 (`huart1`) as a serial port. Since I only wanted `printf()`, I only needed to populate the `_write()` function, which I did as follows. This is conventionally contained in `syscalls.c`.