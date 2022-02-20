row, col=[int(x) for x  in input().split(' ')]
arr=[]
for i in range(row):
	v=[int(x) for x in input().split(' ')]
	arr.append(v)
x,y=[int(x) for x in input().split(' ')]

ans=set()
for i in range(row):
	for j in range(col):
		if arr[i][j]>=x and arr[i][j]<=y:
			ans.add(arr[i][j])
# ans.sort()
# ans=set(ans)
X=[]
for item in ans:
	X.append(item)
X.sort()
for item in X:
	print(item,end=' ')
