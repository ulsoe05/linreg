void linreg(float* slope /*output*/, float* offset/*output*/, const float* x/*input*/, const float* y/*input*/, unsigned int n/*input*/) {
	// Bemærk: xTx er den symmetriserede designmatrix
	float xTx11 = 0.0f;
	float xTx01 = 0.0f; 
	float xTx00 = (float)n;
	float xTy0 = 0.0f;
	float xTy1 = 0.0f;
	for (unsigned int k = 0; k < n; ++k) {
		xTx11 += x[k] * x[k];
		xTx01 += x[k];
		xTy1 += x[k] * y[k];
		xTy0 += y[k];
	}
	*slope = (xTx01 * xTy0 - xTx00 * xTy1) / (xTx01 * xTx01 - xTx00 * xTx11);
	*offset = (xTy0 - xTx01 * (*slope)) / xTx00;
};