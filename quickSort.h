void QuickSort(float *a, int l, int r) {
	int pleft = l, pright = r;
	// chọn khóa random bất kỳ trong đoạn từ [l, r - 1]
	float pivot = a[l + rand() % (r - l)];
	while (pleft <= pright) { // thực hiện vòng lặp
		while (a[pleft] < pivot) ++pleft; // tìm vị trí phần tử lớn hơn hoặc bằng vị trí pleft lớn hơn pivot
		while (a[pright] > pivot) --pright; // tìm vị trí phần tử nhỏ hơn hoặc bằng vị trí pright nhỏ hơn pivot
		if (pleft <= pright) {
			swap(a[pleft], a[pright]); // hoán đổi giá trị tại hai vị trí đó
			++pleft;
			--pright;
		}
	}
	// gọi đệ quy thực hiện sắp xếp 2 dãy con [l, pright] và [pleft, r]
	if (l < pright) QuickSort(a, l, pright);
	if (pleft < r) QuickSort(a, pleft, r);
}
