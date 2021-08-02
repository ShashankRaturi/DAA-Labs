def find_trio(array):
    
    found = False
    for i in range(len(array)):
        for j in range(i+1 , len(array) - 1):
            for k in range(j+1 , len(array)):
                if array[i] + array[j] == array[k]:
                    found = True
                    break
            
            if found == True:
                break

        
        if found == True:
                break

    if found == True:
        print( (i+1), "," , (j+1) , "," , (k+1))
    else:
        print("No sequence found")

    
def read():
    n = int(input())  #number of test cases
    for i in range(n):
        length = int(input()) #length of array
        array = list(map(int , input().split()))

        find_trio(array)


if __name__ == '__main__':
    read()
