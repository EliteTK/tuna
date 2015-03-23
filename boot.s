# # http://wiki.osdev.org/Bare_Bones - loosely based on this
# http://www.gnu.org/software/grub/manual/multiboot/multiboot.html
.set align, 1 << 0
.set meminfo, 1 << 1

.set flags, align | meminfo
.set magic, 0x1BADB002
.set checksum, -(magic + flags)

# http://www.gnu.org/software/grub/manual/multiboot/multiboot.html#Header-layout
.section .multiboot
.align 4
.long magic
.long flags
.long checksum

# prepare a whole 16 KiB of stack
.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 16384
stack_top:

.section .text
.global _start
.type _start, @function
_start:
# we should call _init one day
	movl $stack_top, %esp
	call kernel_main

	cli
	hlt
.hang:
	jmp .hang

.size _start, . - _start
