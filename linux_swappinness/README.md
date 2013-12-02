
Linux system have a flag call swappiness (for the whole system or individual cgroup).

Sometime we hope no swap at all for any process inside certain cgroup. Make
swappiness 0 inside a cgroup make it less possible to swap but not stop it from
doing any swap.

The patch is a try to stop kernel from doing swap for a cgroup with swappiness
value 0.
