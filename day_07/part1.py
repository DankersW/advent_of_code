from collections import defaultdict, deque
from pathlib import Path


def read_input(file: str) -> list:
    with open(Path(file)) as file:
        return [line.strip() for line in file]

"""
def parse_rules(input_data) -> dict:
    rules = {}
    #amount = {}
    for line in input_data:
        rule = line.strip(".").split(" contain ")
        bag = rule[0][:-(4 if rule[0][-1]=="g" else 5)]
        if rule[1] == "no other bags":
            rules[bag] = []
            #amount[bag] = []
        else:
            contents = [r.split() for r in rule[1].split(", ")]
            rules[bag] = [" ".join(c[1:3]) for c in contents]
            #amount[bag] = [int(c[0]) for c in contents]
    #return rules_, amount
    return rules
"""

raw_data = read_input(file='input_test.txt')
parents = defaultdict(list)
content = defaultdict(list)

target = 'shinygoldbag'

for line in raw_data:
    words = line.split()
    container = words[0]+words[1]+words[2]
    container = container[:-1]
    if words[-3] == 'no':
        continue
    else:
        idx = 4
        while idx < len(words):
            bag = words[idx]+words[idx+1]+words[idx+2]+words[idx+3]
            if bag.endswith('.'):
                bag = bag[:-1]
            if bag.endswith(','):
                bag = bag[:-1]
            if bag.endswith('s'):
                bag = bag[:-1]
            n = int(bag[0])
            assert bag[1] not in '0123456789'
            while any([bag.startswith(d) for d in '0123456789']):
                bag = bag[1:]
            parents[bag].append(container)
            content[container].append((n, bag))
            idx += 4

print(parents)
print(content)

seen = set()
q = deque([target])
while q:
    x = q.popleft()
    if x in seen:
        continue
    seen.add(x)
    for y in parents[x]:
        q.append(y)
print(f"part1: {len(seen)-1}")



def size_b(bag):
    ans = 1
    for (n,y) in content[bag]:
        ans += n*size_b(y)
    return ans

print(f"part2: {size_b(target)-1}")
"""
if __name__ == '__main__':
    _raw_data = read_input(file='input_example.txt')
    for rd in _raw_data:
        print(rd)
    print("")

    _rules = parse_rules(input_data=_raw_data)
    bags = parse_rules(input_data=_raw_data)

    val = count_bags(rules=_rules, interesting_bags=['shiny gold'])
    print(f"result: {val}")
    print("")
    print(len(get_possible_container_colors(bags["shiny gold"])))
"""
pass
