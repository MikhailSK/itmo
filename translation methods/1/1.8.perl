while (<>) {
    print if /\([^()]*\w+[^()]*\)/
}