k=int(input())
f=dict()
# B=[]
def func(T):
	return T[1]
while True:
	inp=input()
	if inp=="":
		break
	else:
		T=inp.split(' ')
		for item in T:
			x=f.get(item,0)
			f[item]=x+1
ans=[]
for x,y in f.items():
	ans.append((x,y))
ans.sort(key=func,reverse=True)
if len(ans)<k:
	print(-1)
else:
	for i in range(k):
		print(ans[i][0],end=' ')
