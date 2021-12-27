n=int(input())
sum=0 


for i in range (1, n + 1):
    if i<100 :
        sum+=1
    else :
        d = list(map(int, str(i)))
        if d[0] - d[1] == d[1] - d[2] :
            sum+=1

print(sum)