from pathlib import Path
from itertools import islice

from helper.python.io_operationlib.io_operation import file_to_list


def find_three_sum(total_sum: int, numbers: list) -> int:
    for index_base, base_number in enumerate(islice(numbers, len(numbers)-1)):
        base_helper_sum = total_sum - base_number
        hash_table = dict()
        for index, number in enumerate(numbers, start=index_base):
            helper_sum = base_helper_sum - number
            if helper_sum in hash_table.keys():
                return base_number * number * helper_sum
            hash_table[number] = index
    else:
        return -1


path = Path('input_part2.txt')
input_data = file_to_list(file_path=path)
triplet_sum = find_three_sum(total_sum=2020, numbers=input_data)
print(f'triplet sum: {triplet_sum}')


