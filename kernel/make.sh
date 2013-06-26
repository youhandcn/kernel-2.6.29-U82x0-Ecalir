export PATH=/work/toolschain/4.3.2/bin:$PATH
export CROSS_COMPILE=arm-linux-
make ARCH=arm msm7201a-perf_defconfig
#make ARCH=arm menuconfig
make ARCH=arm

