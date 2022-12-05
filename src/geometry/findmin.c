float	findmin(float r1, float r2)
{
	if (r1 > 0.001 && (r1 < r2 || r2 < 0.001))
		return (r1);
	if (r2 > 0.001 && (r2 < r1 || r1 < 0.001))
		return (r2);
	return (0);
}
