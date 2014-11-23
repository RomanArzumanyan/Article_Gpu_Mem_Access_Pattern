void __kernel TestKernel(
	global uchar	*picture_in, 
	global uchar	*picture_out, 
	int				width,
	int				height)
{
	int 
		x = get_global_id(0) - 1,
		y = get_global_id(1) - 1;

	ushort pixel = 0;
	ushort ker[3][3] = {
		{1, 2, 1},
		{2, 4, 2},
		{1, 2, 1}
	};

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(x>0 && y>0 && x<width && y<height){
				pixel += picture_in[(x+j) + (y+i) * width] * ker[i][j];
			}
		}
	}

	x++;
	y++;

	picture_out[x + y * width] = convert_uchar_sat(pixel >> 4);

	return;
}