order = []

turn = ""
dest = ""

while dest != "SCHOOL":
    turn = input()

    turn = "LEFT" if turn == "R" else "RIGHT"
    if len(order):
        order.insert(0, f"Turn {turn} onto {dest} street.")

    dest = input()


    if not len(order):
        order.insert(0, f"Turn {turn} into your HOME.")

for i in order:
    print(i)