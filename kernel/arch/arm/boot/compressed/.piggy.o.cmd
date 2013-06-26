cmd_arch/arm/boot/compressed/piggy.o := arm-linux-gcc -Wp,-MD,arch/arm/boot/compressed/.piggy.o.d  -nostdinc -isystem /work/toolschain/4.3.2/bin/../lib/gcc/arm-none-linux-gnueabi/4.3.2/include -Iinclude  -I/media/06adc1f9-c237-4424-94a2-aa1a09436aad_/kernel-2.6.29-U82x0-Ecalir/kernel/arch/arm/include -include include/linux/autoconf.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-msm/include -D__ASSEMBLY__ -mabi=aapcs-linux -mno-thumb-interwork -D__LINUX_ARM_ARCH__=6 -march=armv6 -mtune=arm1136j-s -msoft-float -gdwarf-2  -Wa,-march=all   -c -o arch/arm/boot/compressed/piggy.o arch/arm/boot/compressed/piggy.S

deps_arch/arm/boot/compressed/piggy.o := \
  arch/arm/boot/compressed/piggy.S \

arch/arm/boot/compressed/piggy.o: $(deps_arch/arm/boot/compressed/piggy.o)

$(deps_arch/arm/boot/compressed/piggy.o):
