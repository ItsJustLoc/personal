blocks = int(input("How many blocks?: "))
rows = int(input("How many rows?: "))
columns = int(input("How many colums?: "))
symbols = input("What symbol?: ")

for i in range(blocks):
    for j in range(rows):
        for k in range(columns):
            print(symbols, end="")
        print()
    print()