
app.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	e92d4800 	push	{fp, lr}
   4:	e28db004 	add	fp, sp, #4
   8:	e59f000c 	ldr	r0, [pc, #12]	; 1c <main+0x1c>
   c:	ebfffffe 	bl	0 <Uart_Send_string>
  10:	e24bd004 	sub	sp, fp, #4
  14:	e8bd4800 	pop	{fp, lr}
  18:	e12fff1e 	bx	lr
  1c:	00000000 	andeq	r0, r0, r0

Disassembly of section .data:

00000000 <str_buff>:
   0:	7261654c 	rsbvc	r6, r1, #76, 10	; 0x13000000
   4:	6e49206e 	cdpvs	0, 4, cr2, cr9, cr14, {3}
   8:	70654420 	rsbvc	r4, r5, r0, lsr #8
   c:	41206874 	teqmi	r0, r4, ror r8
  10:	4b20696c 	blmi	81a5c8 <main+0x81a5c8>
  14:	656c6168 	strbvs	r6, [ip, #-360]!	; 0x168
  18:	00000064 	andeq	r0, r0, r4, rrx
	...

Disassembly of section .rodata:

00000000 <x>:
   0:	00000005 	andeq	r0, r0, r5

Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	4728203a 			; <UNDEFINED> instruction: 0x4728203a
   8:	2029554e 	eorcs	r5, r9, lr, asr #10
   c:	2e372e34 	mrccs	14, 1, r2, cr7, cr4, {1}
  10:	Address 0x00000010 is out of bounds.


Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00002f41 	andeq	r2, r0, r1, asr #30
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000025 	andeq	r0, r0, r5, lsr #32
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	4d445437 	cfstrdmi	mvd5, [r4, #-220]	; 0xffffff24
  18:	02060049 	andeq	r0, r6, #73	; 0x49
  1c:	01090108 	tsteq	r9, r8, lsl #2
  20:	01140412 	tsteq	r4, r2, lsl r4
  24:	03170115 	tsteq	r7, #1073741829	; 0x40000005
  28:	01190118 	tsteq	r9, r8, lsl r1
  2c:	061e011a 			; <UNDEFINED> instruction: 0x061e011a
