
if __name__=="__main__":
	n=int(input())
	arr=[int(x) for x in input().split(' ')]
	if max(arr)>=11:
		print("Big Inputs")
	elif min(arr)<=0:
		print("Small Inputs")
	else:
		print(longestHeapableSubsequence(arr,max(arr))
