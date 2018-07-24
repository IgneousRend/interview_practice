def calc_largest_num(numbers: list):
    sorted_nums = sorted(numbers, key=cmp_to_key(mycmp), reverse=True)
    return ''.join(sorted_nums)

def mycmp(x, y):
    if int(x + y) > int(y + x):
        return 1
    elif int(x + y) == int(y + x):
        return 0
    else:
        return -1

def cmp_to_key(mycmp):

    class K(object):
        def __init__(self, obj, *args):
            self.obj = obj

        def __lt__(self, other):
            return mycmp(self.obj, other.obj) < 0

        def __gt__(self, other):
            return mycmp(self.obj, other.obj) > 0

        def __eq__(self, other):
            return mycmp(self.obj, other.obj) == 0

        def __le__(self, other):
            return mycmp(self.obj, other.obj) <= 0

        def __ge__(self, other):
            return mycmp(self.obj, other.obj) >= 0

        def __ne__(self, other):
            return mycmp(self.obj, other.obj) != 0

    return K


# main
if __name__ == "__main__":
    numbers = input().split()
    largest_num = calc_largest_num(numbers)

    print("Largest number possible")
print(largest_num)