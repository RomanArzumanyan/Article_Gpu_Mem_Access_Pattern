void __kernel TestKernel(
	global uchar	*picture_in, 
	global uchar	*picture_out, 
	int				width,
	int				height)
{
	int 
		x = get_global_id(0),
		y = get_global_id(1);

	picture_out[x + y * width] = picture_in[x + y * width];

	return;
}