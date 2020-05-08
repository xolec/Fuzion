#!/usr/bin/env bash
# Starts a GDB session on CSGO,
# Sets a couple of things up and then you can use GDB normally

function echo_red {
	echo -e "\e[31m$*\e[0m"
}

csgo_pid=$(pidof csgo_linux64)
if [ -z "$csgo_pid" ]; then
    echo_red "CS:GO needs to be open..."
    exit 1
fi

# pBypass for crash dumps being sent
# You may also want to consider using -nobreakpad in your launch options.
sudo rm -rf /tmp/dumps # Remove if it exists
sudo mkdir --mode=000 /tmp/dumps # Make it as root with no permissions

#https://www.kernel.org/doc/Documentation/security/Yama.txt
echo "2" | sudo tee /proc/sys/kernel/yama/ptrace_scope # Only allows root to inject code. This is temp until reboot.

sudo gdb -p "$csgo_pid" -x ./gdb_debug_attach.txt