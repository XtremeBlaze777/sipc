foo(x) {
    var y, z;
    z = x + 1;
    y = x + 2;
    return y + z;
}

main() {
    var x;
    input x;
    return foo(x);
}