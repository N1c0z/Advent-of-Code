def Parser(fileContent):
    listOrSomething = []
    
    for x in fileContent:
        x = x.split(' -> ')
        point1 = str(x[0]).split(',')
        point2 = str(x[1]).split(',')
        c = ((int(point1[0]),int(point1[1])),(int(point2[0]),int(point2[1])))
        listOrSomething.append(c)

    return listOrSomething

def main():
    fileContent = open(r"Inputs/05.txt", 'r').readlines()
    listOfObj = Parser(fileContent)
    HighestX, HighestY = 0,0
    for x in listOfObj:
        for y in x:
            if HighestX < y[0]:
                HighestX = y[0]

            if HighestY < y[1]:
                HighestY = y[1]
    HighestY += 1
    HighestX += 1
    ArrayA = [[0]*HighestY for i in range(HighestX)]
    g, h = 0, 0
    for x in listOfObj:
        if x[0][0] == x[1][0]:
            if x[0][1] < x[1][1]:
                for a in range(x[0][1], x[1][1]+1):
                    ArrayA[a][x[0][0]] += 1
            else:
                for a in range(x[1][1], x[0][1]+1):
                    ArrayA[a][x[0][0]] += 1
            continue
        
        if x[0][1] == x[1][1]:
            if x[0][0] < x[1][0]:
                for b in range(x[0][0], x[1][0]+1):
                    ArrayA[x[0][1]][b] += 1
            else:
                for b in range(x[1][0], x[0][0]+1):
                    ArrayA[x[0][1]][b] += 1
    print(ArrayA)
    totalNum = 0
    for x in range(HighestX):
        for y in range(HighestY):
            if ArrayA[x][y] >= 2:
                totalNum += 1
    print(totalNum)
        
 

if __name__ == "__main__":  
    main()