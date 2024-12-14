from collections import Counter

def avg_score(marks,n):
    total = 0
    for i in range(n):
        total+=marks[i]
    average = total/n
    return average

def max_score(marks,n):
    max_marks = marks[0]
    for i in range(n):
        if max_marks<marks[i]:
            max_marks=marks[i]    
    return max_marks
    
def min_score(marks,n):
    min_marks = marks[0]
    for i in range(n):
        if min_marks>marks[i] and marks[i]>=0:
            min_marks=marks[i]    
    return min_marks
    
def absent(marks,n):
    count = 0
    for i in range(n):
        if marks[i]==-1:
            count+=1
    return count

def high_freq(marks,n):
    counts = Counter(marks)
    mfreq=counts.most_common(1)
    if mfreq:
        return mfreq[0]

marks=[]
n = int(input("Enter the number of students in the class : "))
for i in range(n):
    x=int(input("Enter marks of students (Enter -1 if absent) : "))
    marks.append(x)
    
while True:
    print("\n")
    print("1. Average score of the class")
    print("2. Max score of the class")
    print("3. Min score of the class")
    print("4. Number of students that were absent")
    print("5. Marks with highest frequency")
    print("6. EXIT")
    ch=int(input("Enter your choice : "))
    if ch==6:
        break
    elif ch==1:
        avg = avg_score(marks,n)
        print("The average score of class is : ",avg)
    elif ch==2:
        maxi=max_score(marks,n)
        print("The max score of class is : ",maxi)
    elif ch==3:
        mini=min_score(marks,n)
        print("The min score of class is : ",mini)
    elif ch==4:
        ab=absent(marks,n)
        print("The number of absent students : ",ab)
    elif ch==5:
        hf= high_freq(marks,n)
        print("Marks with highest frequency : ",hf)
    else:
        print("Enter a valid choice")
        
