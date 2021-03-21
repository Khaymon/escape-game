#!/bin/bash

for file_name in $(find . -name "*.cpp" -o -name "*.c" -o -name "*.hpp" -o -name "*.h")
do
	echo $file_name
	clang-format -style='Google' -i $file_name
done

echo "Lint completed"
