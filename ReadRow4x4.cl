void __kernel TestKernel(
	global uchar	*picture_in, 
	global uchar	*picture_out, 
	int				width,
	int				height)
{
	int 
		k = 4,
		x = get_global_id(0) * k,
		y = get_global_id(1) * k;

	for(int i=0; i<k; i++){
		uchar4 row4 = vload4((x + y * width) / k, picture_in);
		vstore4(row4, (x + y * width) / k, picture_out);
		y++;
	}

	return;
}