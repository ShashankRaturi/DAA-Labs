
def binSearch(array , key):
    
    lo = 0
    hi = len(array) - 1
    count = 0    #tells us about the comparisons made so far
    found = False

    while(lo <= hi):
        mid = lo + ((hi - lo) // 2)
        count += 1

        if key == array[mid]:
            found = True
            break
        elif key > array[mid] :
            lo = mid + 1
        else :
            hi = mid - 1

    if found == True:
        print("Present" , count)
    else:
        print("Not present" , count)



def read():
    n = int(input())  # number of test cases

    for i in range(n):
        length = int(input())  #length of array
        array = list(map(int , input().split()))
        key = int(input())  #key element to be searched

        binSearch(array , key) #calling the binary search function


if __name__ == '__main__':
    read()