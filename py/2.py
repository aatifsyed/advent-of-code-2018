#! /usr/bin/env python3

# %%
# Part One

import pandas
import collections

double_letters = 0
triple_letters = 0

with open("../input/2.input") as f:
    for line in f.readlines():

        # This dict tracks how many occurences of each character there is
        # (the int function passed to defaultdict initialises every
        # missing key with its return value)
        counted_characters = collections.defaultdict(int)

        for character in line:
            counted_characters[character] += 1

        already_incremented_double = False
        already_incremented_triple = False

        for character, count in counted_characters.items():
            if count == 2 and not already_incremented_double:
                double_letters += 1
                already_incremented_double = True
            if count == 3 and not already_incremented_triple:
                triple_letters += 1
                already_incremented_triple = True

checksum = double_letters * triple_letters
print(checksum)

# %%
# Part two


def differs_by_one(a: str, b: str) -> bool:
    differing_columns: int = 0
    for n in range(26):
        if a[n] != b[n]:
            differing_columns += 1

    if differing_columns == 1:
        for n in range(26):
            if a[n] == b[n]:
                print(a[n], end='')
        print()
        return True
    else:
        return False


with open("../input/2.input") as f:
    lines = f.readlines()

for a in lines:
    for b in lines:
        differs_by_one(a, b)


# %%
