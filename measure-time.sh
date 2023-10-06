#!/bin/bash
set -e

for test_file in tests/TEST*.txt
do
    echo "Testing $test_file"
    cat $test_file | time -f "Time: %U sec" --quiet $1>/dev/null
done