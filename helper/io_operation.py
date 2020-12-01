from pathlib import Path


def file_to_list(file_path: Path) -> list:
    with open(file_path) as file:
        lines = [int(line.strip()) for line in file]
    return lines
