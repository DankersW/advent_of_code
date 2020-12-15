from collections import defaultdict, deque
from pathlib import Path


def read_input(file: str) -> list:
    with open(Path(file)) as file:
        return [line.strip() for line in file]


def parse_data(input_data) -> dict:
    parents = defaultdict(list)
    for line in input_data:
        words = line.split()
        container = f'{words[0]} {words[1]}'
        if words[4] != 'no':
            idx = 4
            while idx < len(words):
                bag = f'{words[idx+1]} {words[idx+2]}'
                parents[bag].append(container)
                idx += 4
    return parents


def count_parent_bags(bags: dict) -> int:
    seen = set()
    interesting_colors = deque(['shiny gold'])
    while interesting_colors:
        color = interesting_colors.popleft()
        if color in seen:
            continue
        seen.add(color)
        for y in bags[color]:
            interesting_colors.append(y)
    return len(seen) - 1


if __name__ == '__main__':
    _raw_data = read_input(file='input_example.txt')
    _bags = parse_data(input_data=_raw_data)
    print(f'Count: {count_parent_bags(bags=_bags)}')
