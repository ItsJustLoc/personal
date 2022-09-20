drinks = ["coffee", "soda", "tea"]
dinner = ["pizza", "sushi", "noddle"]
dessert = ["cake", "pudding", "ice cream"]

food = [drinks, dinner, dessert]

print(food[0][0])

for x in food:
    for y in x:
        print(y+" ", end="")
    print()