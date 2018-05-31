class StdIO:
    def __init__(self, delimiter=" "):
        self.line = ""
        self.delimiter = delimiter
        return

    def next(self, input_type=str):
        if self.line == "":
            self.line = input().strip().split(self.delimiter)
        self.line.reverse()
        return input_type(self.line.pop())

def lowest_power(n):
    return 1

def highest_power(n):
    return 16

if __name__ == '__main__':
    pass
