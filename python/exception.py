#! /usr/bin/python3

import logging

try:
    x = 5 / 0
except:
    logging.error("Catch an exception.", exc_info=True, stack_info=True)


print("done")
