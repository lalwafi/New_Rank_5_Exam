#!/bin/bash

cd /Users/lalwafi/Desktop/exam_practice_git/new_examRank5/level_1/bsq || exit

mkdir -p test_maps

echo "========================================"
echo "COMPILING"
echo "========================================"

gcc -Wall -Wextra -Werror bsqme.c -o bsq1
if [ $? -ne 0 ]; then
    echo "Failed to compile bsq1"
    exit 1
fi

gcc -Wall -Wextra -Werror short_bsq.c -o bsq2
if [ $? -ne 0 ]; then
    echo "Failed to compile bsq2"
    exit 1
fi

echo ""
echo "Compilation successful"
echo ""

run_test()
{
    local title="$1"
    local cmd="$2"

    echo "========================================"
    echo "$title"
    echo "========================================"

    echo "---------- bsq1 ----------"
    eval "$cmd" | ./bsq1 2>&1

    echo ""
    echo "---------- bsq2 ----------"
    eval "$cmd" | ./bsq2 2>&1

    echo ""
}

run_file_test()
{
    local title="$1"
    local args="$2"

    echo "========================================"
    echo "$title"
    echo "========================================"

    echo "---------- bsq1 ----------"
    ./bsq1 $args 2>&1

    echo ""
    echo "---------- bsq2 ----------"
    ./bsq2 $args 2>&1

    echo ""
}

cat > test_maps/minimal.txt << 'EOF'
1 . o x
.
EOF

cat > test_maps/full_empty.txt << 'EOF'
3 . o x
...
...
...
EOF

cat > test_maps/all_obstacles.txt << 'EOF'
3 . o x
ooo
ooo
ooo
EOF

cat > test_maps/priority.txt << 'EOF'
4 . o x
....
....
....
....
EOF

cat > test_maps/tiebreak.txt << 'EOF'
5 . o x
.o...
ooooo
.....
..o..
.....
EOF

cat > test_maps/single_row.txt << 'EOF'
1 . o x
.....
EOF

cat > test_maps/single_col.txt << 'EOF'
5 . o x
.
.
.
.
.
EOF

cat > test_maps/bad_len.txt << 'EOF'
3 . o x
...
....
...
EOF

cat > test_maps/bad_count.txt << 'EOF'
3 . o x
...
...
EOF

cat > test_maps/bad_chars.txt << 'EOF'
3 . o x
...
.x.
...
EOF

cat > test_maps/dup_chars.txt << 'EOF'
3 . . x
...
...
...
EOF

printf "3 . o x\n...\n...\n..." > test_maps/no_final_newline.txt

cat > test_maps/zero_rows.txt << 'EOF'
0 . o x
EOF

cat > test_maps/file1.txt << 'EOF'
2 . o x
..
..
EOF

cat > test_maps/file2.txt << 'EOF'
2 . o x
o.
.o
EOF

run_file_test "TEST 1: Subject Example - Valid Map" "test_maps/valid_example.txt"

run_file_test "TEST 2: Minimal Valid Map (1x1)" "test_maps/minimal.txt"

run_file_test "TEST 3: Empty Full Map" "test_maps/full_empty.txt"

run_file_test "TEST 4: Entire Map is Obstacles" "test_maps/all_obstacles.txt"

run_file_test "TEST 5: Rectangle with obstacles - topmost/leftmost" "test_maps/priority.txt"

run_file_test "TEST 6: Two same-size squares - prefer topmost then leftmost" "test_maps/tiebreak.txt"

run_file_test "TEST 7: Single row" "test_maps/single_row.txt"

run_file_test "TEST 8: Single column" "test_maps/single_col.txt"

run_file_test "TEST 9: INVALID - Inconsistent line lengths" "test_maps/bad_len.txt"

run_file_test "TEST 10: INVALID - Too few lines" "test_maps/bad_count.txt"

run_file_test "TEST 11: INVALID - Wrong characters in map" "test_maps/bad_chars.txt"

run_file_test "TEST 12: INVALID - Duplicate characters in header" "test_maps/dup_chars.txt"

run_file_test "TEST 13: INVALID - Missing newline at end" "test_maps/no_final_newline.txt"

run_file_test "TEST 14: INVALID - Zero rows in header" "test_maps/zero_rows.txt"

echo "========================================"
echo "TEST 15: Multiple files"
echo "========================================"

echo "---------- bsq1 ----------"
./bsq1 test_maps/file1.txt test_maps/file2.txt 2>&1

echo ""
echo "---------- bsq2 ----------"
./bsq2 test_maps/file1.txt test_maps/file2.txt 2>&1

echo ""

echo "========================================"
echo "TEST 16: stdin input"
echo "========================================"

echo "---------- bsq1 ----------"
echo "3 . o x
...
...
..." | ./bsq1 2>&1

echo ""
echo "---------- bsq2 ----------"
echo "3 . o x
...
...
..." | ./bsq2 2>&1

echo ""

rm -rf bsq1
rm -rf bsq2