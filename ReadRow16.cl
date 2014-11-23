void __kernel TestKernel(
	global uchar	*picture_in, 
	global uchar	*picture_out, 
	int				width,
	int				height)
{
	int 
		k = 16,
		x = get_global_id(0) * k,
		y = get_global_id(1);

	uchar16 row16 = vload16((x + y * width) / k, picture_in);
	vstore16(row16, (x + y * width) / k, picture_out);

	return;
}