from pathlib import Path

from lib.io_operation import file_to_list


def find_two_sum(pair_sum: int, numbers: list) -> list:
    hast_table = dict()
    for index, number in enumerate(numbers):
        helper = pair_sum - number
        if helper in hast_table.keys():
            return [number, helper]
        hast_table[number] = index
    else:
        return []


path = Path('input.txt')
input_data = file_to_list(file_path=path)
pair = find_two_sum(pair_sum=2020, numbers=input_data)
print(f'pair: {pair}')
sum_of_pairs = pair[0] * pair[1]
print(f'sum: {sum_of_pairs}')


