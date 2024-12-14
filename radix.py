def count_sort(arr,exp):
    n = len(arr)
    output = [0]*n
    count = [0]*10
    for i in range(n):
        index = int(arr[i]/exp)
        count[index % 10] +=1
    for i in range(1,10):
        count[i]+=count[i-1]
    i = n-1
    while i >=0:
        index = int(arr[i]/exp)
        output[count[index % 10 ]-1] = arr[i]
        count[index%10]-=1
        i-=1
    for i in range (n):
        arr[i]=output[i]

def radixSort(arr):
    maxval=max(arr)
    exp = 1
    while maxval//exp > 0:
        count_sort(arr,exp)
        exp*=10
    print("Sorted Array of marks : ")
    print(arr)

def top_five(arr):
    print("The top five marks are : ")
    for i in range(-1,-6,-1):
        print(f"Rank No.:{i} : ",arr[i])

A=[]
n=int(input("Enter the number of students who attempted the exam : "))
for i in range(n):
    x=float(input(f"Enter marks of student {i+1} : "))
    A.append(x)

radixSort(A)
top_five(A)
