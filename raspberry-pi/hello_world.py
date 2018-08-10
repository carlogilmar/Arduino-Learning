#!/usr/bin/python
# -*- coding: latin-1 -*-
import RPi.GPIO as GPIO
import time
print("Hola Raspberry Pi")
GPIO.setmode(GPIO.BCM)
control_pin = 18
GPIO.setup(control_pin, GPIO.OUT)
try:
    while True:
        GPIO.output(control_pin, False)
        print("Abajo")
        time.sleep(0.1)
        GPIO.output(control_pin, True)
        print("Arriba")
        time.sleep(0.1)
finally:
    print("Cleaning up")
    GPIO.cleanup()
