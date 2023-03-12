float b[1000001]; // khai báo một mảng lưu trữ

void MergeSort(float *a, int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    //gọi đệ quy 2 mảng con [l, mid] và [mid + 1, r]
    MergeSort(a, l, mid);
    MergeSort(a, mid + 1, r);
    int pl = l, pr = mid + 1, cur = l - 1;
    while (pl <= mid || pr <= r) {
        ++cur;
        //nếu một trong 2 mảng rỗng thì bỏ dãy còn lại vào mảng
        if (pl > mid) b[cur] = a[pr++];
        else if (pr > r) b[cur] = a[pl++];
        else {
            //thực hiện so sánh 2 phần tử đầu tiên của 2 dãy
            if (a[pl] > a[pr]) b[cur] = a[pr++];
            else b[cur] = a[pl++];
        }
    }
    //gán lại vào mảng đang thực hiện sắp xếp
    for (int i = l; i <= r; i++) a[i] = b[i];
}