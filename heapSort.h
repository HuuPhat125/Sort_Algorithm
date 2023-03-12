void heapify(float *a, int n, int i) {
    // khởi tạo gốc Heap và con trái, con phải của gốc
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    // tìm kiếm con lớn hơn nhiều so với gốc
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    // nếu giá trị lớn nhất không phải là gốc
    if (largest != i) {
        swap(a[i], a[largest]);
        // đệ quy xây dựng lại Heap
        heapify(a, n, largest);
    }
}

void HeapSort(float *a, int l, int r) {
    int n = r - l + 1;
    // xây dựng cây heap
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
    // sắp xếp lại dãy
    for (int i= n - 1; i > 0; i--) {
        // gán phần tử lớn nhất theo vị trí giảm dần
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}