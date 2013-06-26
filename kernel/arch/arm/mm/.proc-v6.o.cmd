cmd_arch/arm/mm/proc-v6.o := arm-linux-gcc -Wp,-MD,arch/arm/mm/.proc-v6.o.d  -nostdinc -isystem /work/toolschain/4.3.2/bin/../lib/gcc/arm-none-linux-gnueabi/4.3.2/include -Iinclude  -I/media/06adc1f9-c237-4424-94a2-aa1a09436aad_/kernel-2.6.29-U82x0-Ecalir/kernel/arch/arm/include -include include/linux/autoconf.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-msm/include -D__ASSEMBLY__ -mabi=aapcs-linux -mno-thumb-interwork -D__LINUX_ARM_ARCH__=6 -march=armv6 -mtune=arm1136j-s -msoft-float -gdwarf-2     -c -o arch/arm/mm/proc-v6.o arch/arm/mm/proc-v6.S

deps_arch/arm/mm/proc-v6.o := \
  arch/arm/mm/proc-v6.S \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/mmu.h) \
  include/linux/linkage.h \
  include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  /media/06adc1f9-c237-4424-94a2-aa1a09436aad_/kernel-2.6.29-U82x0-Ecalir/kernel/arch/arm/include/asm/linkage.h \
  /media/06adc1f9-c237-4424-94a2-aa1a09436aad_/kernel-2.6.29-U82x0-Ecalir/kernel/arch/arm/include/asm/assembler.h \
    $(wildcard include/config/cpu/feroceon.h) \
  /media/06adc1f9-c237-4424-94a2-aa1a09436aad_/kernel-2.6.29-U82x0-Ecalir/kernel/arch/arm/include/asm/ptrace.h \
    $(wildcard include/config/arm/thumb.h) \
  /media/06adc1f9-c237-4424-94a2-aa1a09436aad_/kernel-2.6.29-U82x0-Ecalir/kernel/arch/arm/include/asm/hwcap.h \
  include/asm/asm-offsets.h \
  /media/06adc1f9-c237-4424-94a2-aa1a09436aad_/kernel-2.6.29-U82x0-Ecalir/kernel/arch/arm/include/asm/pgtable-hwdef.h \
  /media/06adc1f9-c237-4424-94a2-aa1a09436aad_/kernel-2.6.29-U82x0-Ecalir/kernel/arch/arm/include/asm/pgtable.h \
  include/asm-generic/4level-fixup.h \
  /media/06adc1f9-c237-4424-94a2-aa1a09436aad_/kernel-2.6.29-U82x0-Ecalir/kernel/arch/arm/include/asm/proc-fns.h \
    $(wildcard include/config/cpu/32.h) \
    $(wildcard include/config/cpu/arm610.h) \
    $(wildcard include/config/cpu/arm7tdmi.h) \
    $(wildcard include/config/cpu/arm710.h) \
    $(wildcard include/config/cpu/arm720t.h) \
    $(wildcard include/config/cpu/arm740t.h) \
    $(wildcard include/config/cpu/arm9tdmi.h) \
    $(wildcard include/config/cpu/arm920t.h) \
    $(wildcard include/config/cpu/arm922t.h) \
    $(wildcard include/config/cpu/arm925t.h) \
    $(wildcard include/config/cpu/arm926t.h) \
    $(wildcard include/config/cpu/arm940t.h) \
    $(wildcard include/config/cpu/arm946e.h) \
    $(wildcard include/config/cpu/sa110.h) \
    $(wildcard include/config/cpu/sa1100.h) \
    $(wildcard include/config/cpu/arm1020.h) \
    $(wildcard include/config/cpu/arm1020e.h) \
    $(wildcard include/config/cpu/arm1022.h) \
    $(wildcard include/config/cpu/arm1026.h) \
    $(wildcard include/config/cpu/xscale.h) \
    $(wildcard include/config/cpu/xsc3.h) \
    $(wildcard include/config/cpu/v6.h) \
    $(wildcard include/config/cpu/v7.h) \
  /media/06adc1f9-c237-4424-94a2-aa1a09436aad_/kernel-2.6.29-U82x0-Ecalir/kernel/arch/arm/include/asm/memory.h \
    $(wildcard include/config/page/offset.h) \
    $(wildcard include/config/dram/size.h) \
    $(wildcard include/config/dram/base.h) \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem.h) \
  include/linux/const.h \
  arch/arm/mach-msm/include/mach/memory.h \
    $(wildcard include/config/msm/stacked/memory.h) \
    $(wildcard include/config/arch/msm/scorpion.h) \
    $(wildcard include/config/arch/msm/arm11.h) \
    $(wildcard include/config/cache/l2x0.h) \
  /media/06adc1f9-c237-4424-94a2-aa1a09436aad_/kernel-2.6.29-U82x0-Ecalir/kernel/arch/arm/include/asm/sizes.h \
  include/asm-generic/memory_model.h \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
  arch/arm/mach-msm/include/mach/vmalloc.h \
    $(wildcard include/config/vmsplit/2g.h) \
  arch/arm/mm/proc-macros.S \
    $(wildcard include/config/cpu/dcache/writethrough.h) \
  /media/06adc1f9-c237-4424-94a2-aa1a09436aad_/kernel-2.6.29-U82x0-Ecalir/kernel/arch/arm/include/asm/thread_info.h \
    $(wildcard include/config/arm/thumbee.h) \
  /media/06adc1f9-c237-4424-94a2-aa1a09436aad_/kernel-2.6.29-U82x0-Ecalir/kernel/arch/arm/include/asm/fpstate.h \
    $(wildcard include/config/vfpv3.h) \
    $(wildcard include/config/iwmmxt.h) \

arch/arm/mm/proc-v6.o: $(deps_arch/arm/mm/proc-v6.o)

$(deps_arch/arm/mm/proc-v6.o):
