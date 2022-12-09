
def main():
    amount = 0
    a = readfile(r"Inputs/01.txt")
    arrayb = list(map(int, a.split("\n")))

    for x in range(len(arrayb)-1):
        if arrayb[x] < arrayb[x+1]:
            amount += 1

    print("Number: "+ str(amount))

    
def readfile(path):
    return open(path, 'r').read()


if __name__ == "__main__":
    main()