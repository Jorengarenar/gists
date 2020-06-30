#!/bin/sh

# Create link in `/lib/systemd/system-sleep` directory

# Installing `tlp` should resolve problem with fans after reboot if system was
# previously suspended (remember to check if services are enabled)
#       $ sudo tlp-stat -s

case "$1" in
    post)
        echo 'auto' > '/sys/bus/pci/devices/0000:01:00.0/power/control' # check device number with `lspci | grep -i nvidia`
        ;;
esac