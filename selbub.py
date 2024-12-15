def acceptArray(A):
    n=int(input("Enter number of students : "))
    for i in range(n):
        x=float(input(f"Enter marks of student {i+1} : "))
        A.append(x)
    print("Marks accepted successfully!")
    
def displayArray(A):
    n=len(A)
    if len==0:
        print("No records to display")
    else:
        for i in range(n):
            print(f"{A[i]:.2f}",end = ' ')
            
def selectionSort(A):
    n=len(A)
    for i in range(n-1):
        min_idx=i
        for j in range(i+1,n):
            if A[j]<A[i]:
                min_idx=j
                
        A[min_idx],A[i]=A[i],A[min_idx]

def bubbleSort(A):
    n=len(A)
    for i in range(n-1):
        for j in range(i+1,n):
            if A[j]<A[i]:
                A[i],A[j]=A[j],A[i]
                
def top_five(A):
    print("Top 5 scores : ")
    for i in range(-1,-6,-1):
        print(f"Rank :{i} -> ",A[i])

def Main():
    A=[]
    while True:
        print("\n1.Accept & display array \n2.Selection sort \n3.Bubble sort \n4.EXIT")
        ch=int(input("Enter your choice : "))
        if ch==4:
            print("Exited successfully ")
            exit(0)
        elif ch==1:
            acceptArray(A)
            displayArray(A)
        elif ch==2:
            print("Array before sorting : ")
            displayArray(A)
            print("Array after sorting : ")
            selectionSort(A)
            displayArray(A)
        elif ch==3:
            print("Array before sorting : ")
            displayArray(A)
            print("Array after sorting : ")
            bubbleSort(A)
            displayArray(A)
            top_five(A)
        else:
            print("Invalid choice, please try again.")
        
Main()
