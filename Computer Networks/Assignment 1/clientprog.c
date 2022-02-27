#include "add.h"
#include <rpc/rpc.h>
int main(int argc, char **argv) {
	CLIENT *cl;
	cl = clnt_create(argv[1], ADD_PROG, ADD_VERS, "tcp");
	mat m;
	mat *out;
	for(int i=0;i<4;i++)
	{
		m.arr[i] = atoi(argv[i+2]);
	}
	out = add_1(&m, cl);
	for(int i=0;i<2;i++)
	{
		if(i%2==0)
		{
			printf("\n");
			
		}
		printf("%d ", out->arr[i]);
	}

}
