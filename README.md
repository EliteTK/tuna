TUnA
====

TUnA (Tom's Unix-like Abomination) is a first attempt at writing something
resembling a really simple operating system.

To see how I'm doing, install qemu and execute `make qemu` to compile the
project and run the resulting elf executable with `qemu-system-i386 -kernel
tuna.bin`.
You will need a cross compiler for the i686-elf target.

Don't expect anything amazing. At least not yet.

The system should be multiboot compatible... if you plan on running it on an
actual machine.
