def accept_array(A):
    n = int(input("Enter number of elements "))
    for i in range(n):
        a=float(input(f"Enter second year percentage of student {i+1} : "))
        A.append(a)
    print("Accepted marks successfully ")

def display_array(A):
    n=len(A)
    if n==0:
        print("No record in database")
    else:
        print("SE marks of students ", end = ' ')
        for i in range(n):
            print(f"{A[i]:.2f}",end = ' ')
        
    
def  insertionSort(A):
    n = len(A)
    for i in range(1,n):
        key = A[i]
        j = i - 1
        while j>=0 and A[j]>key:
            A[j+1] = A[j]
            j-=1
        A[j+1]=key
    
def shellSort(A):
    n = len(A)
    gap = n//2
    for i in range(gap,n):
        temp = A[i]
        j=i
        while j>=0 and A[j-gap]>temp:
            A[j]=A[j-gap]
            j-=gap
        A[j]=temp
    gap//=2
    
def top_five(A):
    A.sort(reverse=True)
    print("Top five scores : ")
    top_scores = A[:5] if len(A)>=5 else A
    for i in top_scores:
        print(f"\t{i:.2f}")
    
        

def main():
    A=[]
    while True:
        print("\t 1. Accept and display array ")
        print("\t 2. Sort array using insertion sort and display array ")
        print("\t 3. Sort array using Shell sort and display top 5 ")
        print("\t 4. EXIT")
        ch = int(input("Enter your choice : "))
        if ch==4:
            print("Prog ended successfully ")
            break
        elif ch==1:
            accept_array(A)
            display_array(A)
        elif ch==2:
            print("Array before Sorting")
            display_array(A)
            print("Array after Sorting : ")
            insertionSort(A)
            display_array(A)
        elif ch==3:
            print("Array before Sorting")
            display_array(A)
            print("Array after Sorting : ")
            insertionSort(A)
            display_array(A)
            print("The top five scores are : ")
            top_five(A)
        else:
            print("Invalid choice , try again")
            
main()
