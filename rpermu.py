#!/usr/bin/python 
import os 
import random 
msg =' '
xs = range(1,201)
random.shuffle(xs)
xs = [str(i) for i in xs]
with open("txt", "w") as f:
	f.write(msg.join(xs))
