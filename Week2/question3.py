def difference_pair(array , key , length):

    count = 0
    for i in range(length):
        for j in range(i+1 , length):
            if abs(array[i] - array[j]) == key:
                count += 1
        
    print(count)


def read():
    n = int(input())  #number of test cases

    for i in range(n):
        length = int(input()) #length of array
        array = list(map(int , input().split()))
        key = int(input())

        difference_pair(array , key , length)


if __name__ == '__main__':
    read()
