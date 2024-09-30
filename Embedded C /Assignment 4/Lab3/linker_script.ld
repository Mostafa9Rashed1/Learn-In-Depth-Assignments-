/* linker_scrip
Eng. Mostafa 
*/


MEMORY
{
flash(RX) : ORIGIN = 0x00000000, LENGTH = 512M
sram(RWX) : ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{
	.text : {
			*(.vector*)
			*(.text*)
			*(.redata)
			_E_text = .;
	}> flash
	
	.data : {
	_S_DATA = . ;
	*(.data*)
	_E_DATA = . ;
	
	}> sram AT> flash
	
	.bss : {
	_S_bss = . ;
	*(.bss*)
	_E_bss = . ;
	}>sram
}
