cmd_block/built-in.o :=  arm-linux-ld -EL    -r -o block/built-in.o block/elevator.o block/blk-core.o block/blk-tag.o block/blk-sysfs.o block/blk-barrier.o block/blk-settings.o block/blk-ioc.o block/blk-map.o block/blk-exec.o block/blk-merge.o block/blk-softirq.o block/blk-timeout.o block/ioctl.o block/genhd.o block/scsi_ioctl.o block/cmd-filter.o block/noop-iosched.o block/as-iosched.o 
