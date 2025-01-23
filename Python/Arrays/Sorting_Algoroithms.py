import array
#BBUBBLE SORT
Arr1 = array.array('i',[4, 7, 2, 9, 3, 9, 0, 3, 7, 1, 7, 8, 5, 6])
for i in range(len(Arr1)):
    swapped = False
    for j in range(len(Arr1) - 1- i):
        if Arr1[j] > Arr1[j + 1]:
            Arr1[j], Arr1[j + 1] = Arr1[j + 1], Arr1[j]
            swapped =True
    if swapped == False:
        break
for i in range(len(Arr1)):
    print(Arr1[i], end= " ")
print()

#____________________________________________________________________________
#INSERTION SORT
Arr2 = array.array('i',[4, 7, 2, 9, 3, 9, 0, 3, 7, 1, 7, 8, 5, 6])
for i in range(1,len(Arr2)):
    key = Arr2[i]
    j = i - 1
    while j >= 0 and Arr2[j] > key:
        Arr2[j + 1] = Arr2[j]
        j -= 1
    Arr2[j + 1] = key
for i in range(len(Arr2)):
    print(Arr2[i], end= " ")
print()

#____________________________________________________________________________
#SELECTION SORT
Arr3 = array.array('i',[4, 7, 2, 9, 3, 9, 0, 3, 7, 1, 7, 8, 5, 6])
for i in range(len(Arr3) - 1):
    min_index = i
    for j in range(i +1, len(Arr3)):
        if Arr3[j] < Arr3[min_index]:
            min_index = j
    if min_index != 1:
        Arr3[i],Arr3[min_index] = Arr3[min_index],Arr3[i]
for i in range(len(Arr3)):
    print(Arr3[i], end= " ")
print()
#____________________________________________________________________________