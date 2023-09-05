int is_major(int n) {
    if (n < 0) {
        return 0;
    } else if (n < 18) {
        return 1;
    } else if (n < 100) {
        return 2;
    }
    return 3;
}