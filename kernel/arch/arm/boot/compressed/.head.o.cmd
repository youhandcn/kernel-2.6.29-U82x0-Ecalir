cmd_arch/arm/boot/compressed/head.o := arm-linux-gcc -Wp,-MD,arch/arm/boot/compressed/.head.o.d  -nostdinc -isystem /work/toolschain/4.3.2/bin/../lib/gcc/arm-none-linux-gnueabi/4.3.2/include -Iinclude  -I/media/06adc1f9-c237-4424-94a2-aa1a09436aad_/kernel-2.6.29-U82x0-Ecalir/kernel/arch/arm/include -include include/linux/autoconf.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-msm/include -D__ASSEMBLY__ -mabi=aapcs-linux -mno-thumb-interwork -D__LINUX_ARM_ARCH__=6 -march=armv6 -mtune=arm1136j-s -msoft-float -gdwarf-2  -Wa,-march=all   -c -o arch/arm/boot/compressed/head.o arch/arm/boot/compressed/head.S

deps_arch/arm/boot/compressed/head.o := \
  arch/arm/boot/compressed/head.S \
    $(wildcard include/config/debug/icedcc.h) \
    $(wildcard include/config/cpu/v6.h) \
    $(wildcard include/config/arch/sa1100.h) \
    $(wildcard include/config/debug/ll/ser3.h) \
    $(wildcard include/config/arch/s3c2410.h) \
    $(wildcard include/config/s3c/lowlevel/uart/port.h) \
    $(wildcard include/config/cpu/cp15.h) \
    $(wildcard include/config/zboot/rom.h) \
    $(wildcard include/config/arch/rpc.h) \
    $(wildcard include/config/processor/id.h) \
    $(wildcard include/config/arch/msm/scorpion.h) \
  include/linux/linkage.h \
  include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  /media/06adc1f9-c237-4424-94a2-aa1a09436aad_/kernel-2.6.29-U82x0-Ecalir/kernel/arch/arm/include/asm/linkage.h \

arch/arm/boot/compressed/head.o: $(deps_arch/arm/boot/compressed/head.o)

$(deps_arch/arm/boot/compressed/head.o):
