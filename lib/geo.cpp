int len2(int x1, int y1, int x2, int y2){
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); 
}

bool sameLine(int ai, int bi, int ci) {
	return (x[ai] - x[bi]) * (y[ci] - y[bi]) == (y[ai] - y[bi]) * (x[ci] - x[bi]);
}

