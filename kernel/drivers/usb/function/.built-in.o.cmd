cmd_drivers/usb/function/built-in.o :=  arm-linux-ld -EL    -r -o drivers/usb/function/built-in.o drivers/usb/function/msm_hsusb.o drivers/usb/function/adb.o drivers/usb/function/mass_storage.o drivers/usb/function/diag.o drivers/usb/function/serial.o drivers/usb/function/ether_cdc_ecm.o drivers/usb/function/pcui.o 