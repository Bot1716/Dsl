A=[
    [1,2,3],
    [4,5,6],
    [7,8,9]
]
print("Matrix A is:")
for i in range(len(A)):
    print(A[i])
B=[
    [1,1,1],
    [1,1,1],
    [1,1,1]
]
print("Matrix B is:")
for i in range(len(B)):
    print(B[i])
C=[
    [0,0,0],
    [0,0,0],
    [0,0,0]
]
for i in range(len(A)):
    for j in range(len(A[1])):
        C[i][j]=A[i][j]+B[i][j]


print("The addition of matrix A and B is:")
for i in range(3):
    print(C[i])

for i in range(len(A)):
    for j in range(len(A[1])):
        C[i][j]=A[i][j]-B[i][j]


print("The Subtraction of matrix A and B is:")
for i in range(len(A)):
    print(C[i])
new=[]
for i in range(len(A)):
    list=[]
    for j in range(len(A[0])):
        sum=0
        for k in range(len(B)):
            sum+=A[i][k]*B[k][j]
        list.append(sum)
    new.append(list)

print("Multiplication of matrices is:")
for i in range(len(list)):
    print(new[i])
def transpose(X,Y):
    for i in range(len(A[0])):
        for j in range(len(A)):
            X[i][j]=Y[j][i]


    for i in range(len(Y)):
        print(X[i])

print("Transpose of matrix A :")
transpose(C,A)
print("Transpose of matrix B :")
transpose(C,B)
