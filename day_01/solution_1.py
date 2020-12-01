from pathlib import Path

from lib.io_operation import file_to_list


def find_two_sum(total_sum: int, numbers: list) -> int:
    hash_table = dict()
    for index, number in enumerate(numbers):
        helper = total_sum - number
        if helper in hash_table.keys():
            return number * helper
        hash_table[number] = index
    else:
        return -1


path = Path('input_part1.txt')
input_data = file_to_list(file_path=path)
pair_sum = find_two_sum(total_sum=2020, numbers=input_data)
print(f'pair sum: {pair_sum}')


