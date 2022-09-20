import os
import shutil

path = "folder"

try:
    shutil.rmtree(path)
except Exception as e:
    print(e)
    print("Error")