OUTPUT_FORMAT(elf32-i386)
ENTRY(RiOS_start)
SECTIONS
{
	. = 0x100000;	
	/* the first 1M reserves for CPU */
	.boot : { *(.multiboot_header) } 
	/*ensure grub2 can detect multiboot header*/
	.text : { *(.text) } /*.text section from all code*/
	.data : { *(.data) } /* data section */
	.bss  : { *(.bss)  } /*.bss means "Block Started by Symbol Segment"*/
       	/* global variables that have not been initialized */
	
}
