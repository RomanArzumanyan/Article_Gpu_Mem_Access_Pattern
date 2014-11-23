void __kernel TestKernel(
	global uchar	*picture_in, 
	global uchar	*picture_out, 
	int				width,
	int				height)
{
	int 
		k = 2,
		x = get_global_id(0) * k,
		y = get_global_id(1);

	uchar2 row2 = vload2((x + y * width) / k, picture_in);
	vstore2(row2, (x + y * width) / k, picture_out);

	return;
}