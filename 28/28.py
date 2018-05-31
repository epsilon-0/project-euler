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


if __name__ == '__main__':
    io = StdIO
    tests = io.next(int)
    for _ in range(tests):
        n = int(input().strip())
        print((1 + (5 * ((n**2) - 1) // 2) +
               (2 * (n * (n - 1) * (n - 2)) // 3)) % 1000000007)
