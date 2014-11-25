void __kernel TestKernel(
	global uchar	*picture_in, 
	global uchar	*picture_out, 
	int				width,
	int				height)
{
	int 
		k = 8,
		x = get_global_id(0) * k,
		y = get_global_id(1) * k;

	for(int i=0; i<k; i++)
		for(int j=0; j<k; j++)
			picture_out[(x+j) + (y+i)*width] = picture_in[(x+j) + (y+i)*width];

	return;
}