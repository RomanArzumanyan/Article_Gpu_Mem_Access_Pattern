void __kernel TestKernel(
	global uchar	*picture_in, 
	global uchar	*picture_out, 
	int				width,
	int				height)
{
	int 
		k = 2,
		x = get_global_id(0),
		y = get_global_id(1) * k;

	for(int i=0; i<k; i++){
		picture_out[x + y*width] = picture_in[x + y*width];
		y++;
	}

	return;
}