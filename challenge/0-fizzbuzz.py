def fizzbuzz(n):
    for i in range(1, n + 1):
        if i % 3 == 0 and i % 5 == 0:
            text = "FizzBuzz"
        elif i % 3 == 0:
            text = "Fizz"
        elif i % 5 == 0:
            text = "Buzz"
        else:
            text = str(i)

        # Only print a space if it's NOT the last number
        if i < n:
            print(text, end=" ")
        else:
            print(text)
