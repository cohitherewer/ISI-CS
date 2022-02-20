#include<sys/time.h>
#include<stdio.h>
#define N 18
#define GAP(start, end) ((end.tv_usec-start.tv_usec)+(end.tv_sec-start.tv_sec)*1000000)
int main(){
    int i, j,n, numDIGIT, leftSUM, rightSUM, count;
    struct timeval start_time, end_time;
    scanf("%d", &n);
    gettimeofday(&start_time, NULL);
    /* START OF BLOCK */
    count = 0;
    for(i = 1; i < n; ++i){
        j = i;
        numDIGIT = 0;
        leftSUM = 0;
        rightSUM = 0;
        int arr[N]={0};
        while(j > 0){
			int r=j;
			//j/=10;
            arr[numDIGIT]=r-(r/10)*10;j/=10;
            //if(numDigit>0)arr[numDigit]+=arr[numDigit-1];
            ++numDIGIT;
        }int left=0,right=numDIGIT-1;
        while(left<=right){
			leftSUM+=arr[left++],rightSUM+=arr[right--];
		}
        //j = i;
        //k = numDIGIT;
        //while(j > 0){
            //r = j%10;
            //if(k <= numDIGIT/2 + 1)
                //leftSUM = leftSUM + r;
            //if(k >= numDIGIT/2 + 1)
                //rightSUM = rightSUM + r;
            //j = j/10;
            //k--;
        //}
        if(leftSUM == rightSUM)
            count++;
    }
    /* END OF BLOCK */
    gettimeofday(&end_time, NULL);
    printf("Count of special numbers less than %d: %d", n, count);
    printf("\nTime taken: %ld microseconds", (long int) GAP(start_time, end_time));
}
