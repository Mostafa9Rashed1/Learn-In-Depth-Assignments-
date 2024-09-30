/* startup_cortex_M3.c
Eng. Mostafa */

.section	.vector

.word 0x20001000		// Stack Top
.word  _reset			// 1 Reset
.word vector_handler	//2 NMI
.word vector_handler	//3 Hard fault	
.word vector_handler	//4 MM fault	
.word vector_handler	//5 Bus fault 
.word vector_handler	//6 Usage fault
.word vector_handler	//7 Reserved
.word vector_handler	//8 Reserved
.word vector_handler	//9 Reserved
.word vector_handler	//10 Reserved
.word vector_handler	//11 SR call


.section	.text
_reset:
	bl main

vector_handler:
	b _reset




