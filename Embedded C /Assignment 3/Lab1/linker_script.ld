ENTRY(reset)

MEMORY
{
	Mem(rwx):ORIGIN = 0x00000000 , LENGTH = 64M
}

SECTIONS
{
	. = 0x10000 ;
	.startup . :
	{
		startup.o(.text)
	}> Mem
	.text :
	{
		*(.text) 
	}> Mem
	.bss :
	{
		*(.bss) *(.comment)
	}> Mem
	. = . + 0x1000 ;
	top_stack = .;
}
