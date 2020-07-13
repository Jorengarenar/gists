#!/usr/bin/env sh

cat /sys/devices/system/cpu/cpu*/cpufreq/scaling_cur_freq
echo
cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq
cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq
