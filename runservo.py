import RPi.GPIO as GPIO
import os
GPIO.setmode(GPIO.BOARD)
GPIO.setup(12, GPIO.OUT)
pwm=GPIO.PWM(12,50)
pwm.start(5)
while True:
	if("0.bin" in os.listdir("/home/pi")):
		pwm.ChangeDutyCycle(10)
	else:
		pwm.ChangeDutyCycle(5)
