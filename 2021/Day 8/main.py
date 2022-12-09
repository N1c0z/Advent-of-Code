def main():
    fileContent = open(r"Inputs/08.txt", 'r').readlines()
    num = 0
    b = True
    for x in fileContent:
        y = x.split(' ')
        for a in y:
            if a == '|':
                b = False
            
            if b:
                continue  
            a = a.replace('\n','')
            if  (len(a) == 2):
                num += 1
                
            if  (len(a) == 4):
                num += 1
                
            if  (len(a) == 3):
                num += 1
                
            if  (len(a) == 7):
                num += 1
        b = True
                
    print(num)
    return

if __name__ == "__main__":
    main()