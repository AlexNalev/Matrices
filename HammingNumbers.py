'''
* Tell if a number is a Hamming number or not
* Hamming numbers are formed like this:
* 2^i x 3^j x 5^k ---- i,j,k > 0
'''


class Hamming:
    def __init__(self, number):
        self.number = number
        self.prime_numbers = []

    def get_prime_numbers(self):
        self.prime_numbers.clear()
        copy_number = self.number
        prime_number = 2

        while copy_number != 1:
            if copy_number % prime_number == 0:
                self.prime_numbers.append(prime_number)
                copy_number /= prime_number
                prime_number = 2
            else:
                prime_number += 1

    def is_hamming(self):
        if (2 in self.prime_numbers) or (3 in self.prime_numbers) or (5 in self.prime_numbers):
            i = self.prime_numbers.count(2)
            j = self.prime_numbers.count(3)
            k = self.prime_numbers.count(5)

            print(f"{self.number} is a Hamming Number and it has this form:")
            print(f"2^{i} x 3^{j} x 5^{k}")

        else:
            print(f"{self.number} is not a Hamming Number")


h = Hamming(27)
h.get_prime_numbers()
h.is_hamming()
