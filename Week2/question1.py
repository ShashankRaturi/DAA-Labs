def index_through_binary_search(array , key , first_index):
    """
    This is a modified version of normal binary search.
    it returns the required index(either first or last) of the key element.
    """
    lo = 0
    hi = len(array) - 1
    result = -1

    while(lo <= hi):
        mid = lo + ((hi - lo) // 2)

        if key == array[mid]:
            result = mid
            if first_index == True:
                hi = mid - 1
            else:
                lo = mid + 1
            
        
        elif key < array[mid]:
            hi = mid - 1
        
        else :
            lo = mid + 1
    

    return result 



def read():
    n = int(input())  # number of test cases

    for i in range(n):
        length = int(input())  #length of array
        array = list(map(int , input().split()))
        key = int(input())  #key element to be searched

        first = index_through_binary_search(array , key , True) # True implies that first index is searched
        last = index_through_binary_search(array , key , False) # False implies that first index is not searched i.e., we are looking for last index

        print("{a} - {b}".format(a = key , b = (last - first + 1)))


if __name__ == '__main__':
    read()