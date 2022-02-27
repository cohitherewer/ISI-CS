#include "add.h"
mat* add_1_svc(mat *m ,struct svc_req *rqstp)
{
	static int *c;
	static mat out;
    int x=0;
    int a[2][2], b[2][2],d[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            a[i][j] = m->arr[x++];
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            b[i][j] = m->arr[x++];
        }
    }
    x=0;
    //static int res[4];
    for(int i=0;i<2;i++)
    {
    for(int j=0;j<2;j++)
    {
    	d[i][j] = 0;
    }
    }
    	
    
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
            	d[i][j]+= a[i][k]*b[k][j];
            }
        }
    }
    
    for(int i=0;i<2;i++)
    {
    for(int j=0;j<2;j++)
    {
    out.arr[x] = d[i][j];
    x++;
    }
    }
   // c = res;
    return &out;

}
