import os

o = os

path  = "/Users/loc/Desktop/PyLearning/PyTime"

if o.path.exists(path):
    print("That location exists!")
    if o.path.isfile(path):
        print("That is a file")
    elif o.path.isdir(path):
        print("That is a folder")
else:
    print("That location doesn't exist")