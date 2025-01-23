def Merge(left,right):
    merged = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            j += 1
    
    merged.extend(left[i:])
    merged.extend(right[j:])
    return merged
        

def MergeSort(L):
    if len(L) <= 1: # Base case for recurssion
        return L
    
    mid = len(L)//2 # divide into two parts
    LeftHalf = MergeSort(L[0:mid])
    RightHalf = MergeSort(L[mid:])
    
    return Merge(LeftHalf, RightHalf) #merge subarrays


L = [9,1,8,2,7,3,6,4,5]
print(L)
L = MergeSort(L)
print(L)