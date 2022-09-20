import random
r = random

x = r.randint(1,6)
y = r.random()

myList = ['rock', 'paper', 'scissors']
z = r.choice(myList)

cards = [2,3,4,5,6,7,8,9,10,"J","Q","K","A"]

r.shuffle(cards)

print(cards)