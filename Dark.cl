void __kernel Dark(global uchar* picture, uint linesize)
{
	uint 
		x = get_global_id(0),
		y = get_global_id(1);

	picture[x + y * linesize] /= 2;
	return;
}