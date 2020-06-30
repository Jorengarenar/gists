gpu-switch() {
    if [ ! -z $(command -v optimus-manager) ]; then
        if [[ "$(glxinfo | grep "OpenGL vendor")" =~ .*Intel.* ]] && \
                [[ "$(cat '/sys/bus/pci/devices/0000:01:00.0/power/control')" == "auto" ]]
        then
            read -p "Are you sure? System will reboot! [Y/n] " -r
            if [[ ! $REPLY =~ ^[Nn]$ ]]; then
                optimus-manager --set-startup nvidia_once
                reboot
            fi
        else
            optimus-manager --switch auto
            i3-msg exit
        fi
    fi
}