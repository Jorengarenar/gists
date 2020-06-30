If those won't help proced with fan_madness_after_suspend.shTry using one of these:
  * `GRUB_CMDLINE_LINUX="pcie_port_pm=off"`
  * `GRUB_CMDLINE_LINUX="acpi_osi=! acpi_osi='Windows 2009' pcie_port_pm=off"`
  * `GRUB_CMDLINE_LINUX="acpi_osi!'Windows 2009"`
  * `GRUB_CMDLINE_LINUX="acpi_osi=! acpi_osi='Windows 2009'"`
  * `gpu-switch.shGRUB_CMDLINE_LINUX="Linux"`

If any of those don't help, use `fan_madness_after_suspend.sh` and `gpu-switch.sh`