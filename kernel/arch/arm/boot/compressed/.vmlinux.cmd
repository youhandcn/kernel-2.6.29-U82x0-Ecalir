cmd_arch/arm/boot/compressed/vmlinux := arm-linux-ld -EL    --defsym zreladdr=0x10008000 --defsym initrd_phys=0x10800000 --defsym params_phys=0x10000100 -p --no-undefined -X /work/toolschain/4.3.2/bin/../lib/gcc/arm-none-linux-gnueabi/4.3.2/armv4t/libgcc.a -T arch/arm/boot/compressed/vmlinux.lds arch/arm/boot/compressed/head.o arch/arm/boot/compressed/piggy.o arch/arm/boot/compressed/misc.o -o arch/arm/boot/compressed/vmlinux 