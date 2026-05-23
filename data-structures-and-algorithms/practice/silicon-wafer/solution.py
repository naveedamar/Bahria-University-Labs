# reads wafer input from wafer_input.txt and prints largest defect-free rectangle per test case

import sys
from collections import deque

def largest_rectangle_in_histogram(heights):
    stack = []
    max_area = 0
    n = len(heights)

    for i in range(n + 1):
        current_height = 0 if i == n else heights[i]

        while stack and current_height < heights[stack[-1]]:
            height = heights[stack.pop()]
            width = i if not stack else i - stack[-1] - 1
            max_area = max(max_area, height * width)

        stack.append(i)

    return max_area


def largest_defect_free_rectangle(wafer, n):
    heights = [0] * n
    max_area = 0

    for row in range(n):
        for col in range(n):
            if wafer[row][col] == 1:
                heights[col] += 1
            else:
                heights[col] = 0

        current_area = largest_rectangle_in_histogram(heights)
        max_area = max(max_area, current_area)

    return max_area


def main():
    with open("wafer_input.txt") as f:
        data = f.read().split()
    idx = 0

    while idx < len(data):
        n = int(data[idx])
        idx += 1
        wafer = []

        for i in range(n):
            row = [int(data[idx + j]) for j in range(n)]
            wafer.append(row)
            idx += n

        print(largest_defect_free_rectangle(wafer, n))

if __name__ == "__main__":
    main()