#Linear search (unsorted)
L = [1,5,7,3,4,7,2,6,7,1,5]
key = 7
for i in range(len(L)):
    if L[i] == key:
        print(key, "at index", i)
    elif i == len(L) - 1 and L[i] == key:
        print("Element not present")
print()

#_______________________________________________
#Binary Search (sorted)
L = [1,3,4,7,9,13,43,56,79,80]
key = 4
left = 0
right = len(L) - 1
while(left <= right):
    mid = left + (right - left)//2
    if L[mid] == key:
        print(key, "at index",mid)
        break
    elif L[mid] < key:
        left = mid+1
    elif L[mid] > key:
        right = mid - 1