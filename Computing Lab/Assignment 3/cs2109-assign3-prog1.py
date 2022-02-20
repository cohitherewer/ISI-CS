strings=[len(x) for x in input().split(' ')]
strings.sort(reverse=True)
if len(strings)<=1:
	print(strings[0])
elif len(strings)==2:
	print(2*(strings[0]+strings[1]))
else:
	ans=strings[0]*(2**(len(strings)-1))
	index=len(strings)-1
	for i in range(1,len(strings)):
		ans+=strings[i]*(2**index)
		index-=1
	print(ans)
