def arraySum(arr, n):
    if n == 0:
        return 0
    return arr[n-1] + arraySum(arr, n-1)

def reverseString(s):
    if s == "":
        return s
    return reverseString(s[1:]) + s[0]

def isPalindrome(s):
    s = ''.join(c.lower() for c in s if c.isalnum())
    def helper(left, right):
        if left >= right:
            return True
        if s[left] != s[right]:
            return False
        return helper(left+1, right-1)
    return helper(0, len(s)-1)

def power(base, exponent):
    if exponent == 0:
        return 1
    if exponent == 1:
        return base
    return base * power(base, exponent-1)

def towerOfHanoi(n, source, target, auxiliary):
    if n == 1:
        print(f"Move disk 1 from {source} to {target}")
        return
    towerOfHanoi(n-1, source, auxiliary, target)
    print(f"Move disk {n} from {source} to {target}")
    towerOfHanoi(n-1, auxiliary, target, source)

def permutations(s, answer=""):
    if len(s) == 0:
        print(answer)
        return
    for i in range(len(s)):
        ch = s[i]
        left = s[:i]
        right = s[i+1:]
        permutations(left + right, answer + ch)


arr = [1, 2, 3, 4, 5]
print("Array Sum:", arraySum(arr, len(arr)))

user_str = input("Enter a string to reverse: ")
print("Reversed String:", reverseString(user_str))

user_palindrome = input("Enter a string to check if it's a palindrome: ")
print("Is Palindrome:", isPalindrome(user_palindrome))

base = int(input("Enter base for power function: "))
exponent = int(input("Enter exponent for power function: "))
print(f"{base} raised to the power {exponent} is:", power(base, exponent))

n_disks = int(input("Enter number of disks for Tower of Hanoi: "))
towerOfHanoi(n_disks, 'A', 'C', 'B')

perm_str = input("Enter a string to generate permutations: ")
print("Permutations:")
permutations(perm_str)

