void __kernel TestKernel(
	global uchar	*picture_in, 
	global uchar	*picture_out, 
	int				width,
	int				height)
{
	int 
		k = 8,
		x = get_global_id(0) * k,
		y = get_global_id(1);

	uchar8 row8 = vload8((x + y * width) / k, picture_in);
	vstore8(row8, (x + y * width) / k, picture_out);

	return;
}