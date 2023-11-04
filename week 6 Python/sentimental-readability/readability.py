# TODO
import string

# 0.0588 * L - 0.296 * S - 15.8
# L is average number of letters per 100 words
# S is average number of sentences per 100 words

text = input('Text: ')
# text = "Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard."
words = 1
sentences = 0
characters = 0

for char in text:
    if char == ' ':
        words += 1
    if char == '?' or char == '!' or char == '.':
        sentences += 1
    if char in string.ascii_uppercase or char in string.ascii_lowercase:
        characters += 1

L = characters / words * 100
S = sentences / words * 100
# print(L, S)
grade = round(0.0588 * L - 0.296 * S - 15.8)
# print(f"character: {characters}")
# print(f"words: {words}")
# print(f"sentences: {sentences}")
# print(grade)

if(grade > 16):
    print("Grade 16+")
elif(grade < 1):
    print("Before Grade 1")
else:
    print(f"Grade {grade}")


