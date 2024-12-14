def accept_array(A):
    n=int(input("Enter number of students : "))
    for i in range(n):
        x=float(input(f"Enter FE marks of student {i+1}:"))
        A.append(x)
    print("Array accepted successfully ")
    
def display_array(A):
    n = len(A)
    if n==0:
        print("No records in database : ")
    else:
        print("Array of FE marks of student : ")
        for i in range(n):
            print(f"{A[i]:.2f}", end = ' ')
            
def selectionSort(A):
    n=len(A)
    for pos in range(n-1):
        min_idx = pos
        for i in range(pos + 1, n):
            if A[i] < A[min_idx]:
                min_idx = i
            A[pos], A[min_idx] = A[min_idx], A[pos]

def bubbleSort(A):
    n = len(A)
    for i in range(n-1):
        for j in range(i+1,n):
            if A[i]<A[j]:
                A[i],A[j]=A[j],A[i]
def Main():
    A=[]
    while True:
        print("\n")
        print("\t 1. Accept and display array elements ")
        print("\t 2. Sort elements in ascending order using Selection sort ")
        print("\t 3. Sort elements in ascending order using Bubble sort and display top 5 scores")
        print("\t 4. EXIT")
        ch = int(input("Enter your choice : "))
        if ch==4:
            print("Exited successfully")
            break
        elif ch == 1:
            accept_array(A)
            display_array(A)
        elif ch == 2:
            print("Array before Sorting : ")
            display_array(A)
            selectionSort(A)
            print("Array after Sorting : ")
            display_array(A)
        elif ch == 3:
            print("Array before Sorting : ")
            display_array(A)
            bubbleSort(A)
            print("Array after Sorting : ")
            display_array(A)
            print("Top five scores :")
            top_scores = A[:5] if len(A)>=5 else A
            for score in top_scores:
                print(f"\t{score:.2f}")
        else:
            print("Enter valid choice")
            
    
Main()
