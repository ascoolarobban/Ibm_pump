from time import sleep, strftime, time
import random
import pymongo
import datetime
from pymongo import MongoClient
import RPi.GPIO as GPIO
import pigpio

now = datetime.datetime.now()


waterFlow = 0
flow  = 4

pi = pigpio.pi()
pi.set_mode(flow, pigpio.INPUT)
pi.set_pull_up_down(flow, pigpio.PUD_DOWN)
while True:
	try:
		print(f"{flow} \n")
		print(now)
		sleep(1)


	except Exception as e:
		print(e)









