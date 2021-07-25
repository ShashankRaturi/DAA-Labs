def linSearch(array , key):

    numOfComparisons  = 0
    found = False

    for i in range(len(array)):
        numOfComparisons += 1
        if key == array[i]:
            found = True
            break
    
    if found == True:
        print("Present",numOfComparisons)
    else:
        print("Not present" , numOfComparisons)


def read():
    n = int(input())

    for i in range(n):
        length = int(input())
        array = list(map(int , input().split()))
        key = int(input())

        linSearch(array , key)


if __name__ == '__main__':
    read()