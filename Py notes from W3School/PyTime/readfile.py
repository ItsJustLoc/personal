try:
    with open('test.txt') as file:
        print(file.read())
except Exception as e:
    print(e)
    print("error opening file.")