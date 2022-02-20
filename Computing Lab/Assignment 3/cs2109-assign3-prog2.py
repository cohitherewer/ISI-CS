def search(X,y):
	left=0;right=len(X)-1
	while(left<=right):
		mid=(right-left)//2+left
		if X[mid]==y:
			print(mid);return
		elif X[mid]>y:
			right=mid-1
		else:
			left=mid+1
	print("ABSENT");

val=int(input())
A=[int(x) for x in input().split(' ')]

search(A,val)
