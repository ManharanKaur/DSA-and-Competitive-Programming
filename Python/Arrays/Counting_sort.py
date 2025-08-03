arr = [1, 2, 1, 1, 3, 4, 0, 5, 6, 1, 0, 1]
n = len(arr)

# find max val
max_val = 0
for i in arr:
    max_val = max(max_val, i)

# count array
count_arr = [0] * (max_val + 1) # initialize with 0
for i in arr:
    count_arr[i] += 1

# make cumulative array
for i in range(1, max_val + 1):
    count_arr[i] += count_arr[i - 1]

output_arr = [0] * n
for i in arr:
    output_arr[count_arr[i] - 1] = i
    count_arr[i] -= 1

for i in output_arr:
    print(i, end = ' ')