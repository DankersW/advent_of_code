from collections import defaultdict
from pathlib import Path


def read_input(file: str) -> list:
    with open(Path(file)) as file:
        return [line.strip() for line in file]


def parse_data(input_data) -> dict:
    bags = defaultdict(list)
    for line in input_data:
        words = line.split()
        container = f'{words[0]} {words[1]}'
        if words[4] != 'no':
            idx = 4
            while idx < len(words):
                bag = f'{words[idx+1]} {words[idx+2]}'
                quantity = words[idx]
                bags[container].append((quantity, bag))
                idx += 4
    return bags


def count_child_bags(bags: dict, bag: str) -> int:
    count = 1
    for (quantity, child_bag) in bags[bag]:
        count += int(quantity) * count_child_bags(bags=bags, bag=child_bag)
    return count


if __name__ == '__main__':
    _raw_data = read_input(file='input_test.txt')
    _bags = parse_data(input_data=_raw_data)
    print(f'Count: {count_child_bags(bags=_bags, bag="shiny gold")-1}')
