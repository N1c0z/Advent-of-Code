def main():
    arrayXSize = 0
    arrayYSize = 0
    array = [[]]
    folds = []
    fileContent = open(r"Inputs/13.txt", 'r').readlines()
    for x in fileContent:
        x = x.replace('\n','')
        if x == '':
            continue
        if "fold along " in x:
            x = x.replace("fold along ", '')
            y = x.split('=')
            folds.append((y[0], int(y[1])))
            continue
        
        y = x.split(',')
        if arrayXSize < y[1]:
            arrayXSize = int(y[1])
        if arrayYSize < y[0]:
            arrayYSize = int(y[0])
            
        array[y[1]][y[0]] = 1
    for i in range(arrayXSize):
        for k in range(arrayYSize):
            if array[i][k] != 0:
                array[i][k] == 0
                
    for x in folds:
        if x[0] == 'y':
            for i in range()

if __name__ == "__main__":
    main()