import array

#Transversal
A = array.array('i', [1, 2, 3, 4, 5])
for x in A:
    print(x, end=" ")
print()

#_____________________________________________
#Insertion
B = array.array('i', [1, 2, 3, 4, 5])
pos = 2
el = 8
B.append(0)

for x in range(len(B) - 1, pos , -1):
    B[x] = B[x - 1]
B[pos] = el
for x in B:
    print(x, end=" ")
print()

#________________________________________________
#Deletion
C = array.array('i', [1, 2, 3, 4, 5])
key = 3
pos = -1
for i in range(len(C)):
    if C[i] == key:
        pos = i
        break
if pos != -1:
    for i in range(pos,len(C)-1):
        C[i] = C[i+1]
else:
    print("Element Not Present")
for x in range(len(C)-1):
    print(C[x], end=" ")
print()

#________________________________________________
#Searching: LINEAR SEARCH
D = array.array('i', [1, 2, 3, 4, 5])
key = 4
for i in range(len(D)):
    if D[i] == key:
        print(key, "at", i)
        break
    elif i == len(D) - 1 and D[i] == key:
        print("Element Not Present")
        print()

#__________________________________________
#Array Reverse using extra array
E = array.array('i',[1,3,5,7,9]);
E_copy = array.array('i',[]);
for i in range(len(E)):
    E_copy.append(E[len(E) - 1 -i])
for x in range(len(E)):
    print(E[x], end=" ")
print()

#__________________________________________
#Array Reverse using loop in same array
F = array.array('i',[1,2,3,4,5])
start = 0
end = len(F) - 1
while start < end:
    temp = F[start]
    F[start] = F[end]
    F[end] = temp
    start += 1
    end -= 1
for x in range(len(F)):
    print(F[x], end=" ")
print()

#__________________________________________
#Array Rotation using temp array(LEFT ROTATION)
G = array.array('i',[1,2,3,4,5,6,7,8,9,10])
k = 3
temp = array.array('i',[])
for i in range(len(G)):
    temp.append(G[(i+k)%len(G)])
for i in range(len(G)):
    G[i] = temp[i]
for x in range(len(G)):
    print(G[x], end=" ")
print()

#__________________________________________
#Array Rotation using temp array(RIGHT ROTATION)
H = array.array('i',[1,2,3,4,5,6,7,8,9,10])
k = 3
temp = array.array('i',[])
for i in range(len(H)):
    temp.append(H[(len(H) + i - k)%len(H)])
for i in range(len(H)):
    H[i] = temp[i]
for x in range(len(H)):
    print(H[x], end=" ")
print()

#__________________________________________
#Array Rotation one by one (LEFT ROTATION)
I = array.array('i',[0,1,2,3,4,5,6,7,8,9])
k = 4
pos = 1
while(pos <= k):
    last = I[0]
    for i in range(len(I) - 1):
        I[i] = I[i + 1] #Shift elements to Left
    I[-1] = last #Assigh first element to last index
    pos += 1
for x in range(len(H)):
    print(I[x], end=" ")
print()

#__________________________________________________________
#Array Rotation one by one (LEFT ROTATION)
J = array.array('i',[0,1,2,3,4,5,6,7,8,9])
k = 4
pos = 1
while(pos <= k):
    start = J[-1]
    for i in range(len(J) - 1, 0, -1):
        J[i] = J[i - 1] #Shift elements to Right
    J[0] = start #Assigh last element to first index
    pos += 1
for x in range(len(J)):
    print(J[x], end=" ")
print()