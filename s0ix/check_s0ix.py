#! /usr/bin/python3

import time

def if_s0ix_supported_soc():
    # Low Power S0 Idle Capable Flag in the Fixed ACPI Description Table (FADT)
    pass


# Check if S0ix is supported on an Intel® SoC.
# Perform basic debug if S0ix is not running properly.
# Report issues if the user’s platform has a failure for the S0ix state.


RESIDENCY_FILE_PATH = "/sys/devices/system/cpu/cpuidle/"

RESIDENCY_US_CPU = "low_power_idle_cpu_residency_us"
RESIDENCY_US_SYSTEM = "low_power_idle_system_residency_us"

RESIDENCY_US_CPU_FULL = RESIDENCY_FILE_PATH + RESIDENCY_US_CPU
RESIDENCY_US_SYSTEM_FULL = RESIDENCY_FILE_PATH + RESIDENCY_US_SYSTEM


def read_residency():
    with open(RESIDENCY_US_CPU_FULL) as fcpu:
        cpu_str = fcpu.read()
        cpu = int(cpu_str)

    with open(RESIDENCY_US_SYSTEM_FULL) as fsystem:
        system_str = fsystem.read()
        system = int(system_str)

    return cpu, system

title = "(cpu, system): low power residency in us"

while True:
    print(title)
    for i in range(10):
        print(read_residency())
        time.sleep(1)

