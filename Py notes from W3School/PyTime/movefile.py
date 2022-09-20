import os

source = "/Users/loc/Desktop/PyLearning/PyTime/test.txt"
dest = "/Users/loc/Desktop/test.txt"

#try:
if os.path.exists(dest):
    print("There is already a file there")
else:
    os.replace(source,dest)
    print(source+ "was moved")
#except Exception as e:
#    print(e)
#    print("Error handing file")