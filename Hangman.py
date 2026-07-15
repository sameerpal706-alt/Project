import random

# List of 5 predefined words
words = ["python", "apple", "computer", "student", "school"]

# Select a random word
word = random.choice(words)

# Create blanks for the word
guessed_word = ["_"] * len(word)

# Store guessed letters
guessed_letters = []

# Maximum incorrect guesses
attempts = 6

print("Welcome to Hangman Game!")
print("You have", attempts, "incorrect guesses.\n")

# Game loop
while attempts > 0 and "_" in guessed_word:
    print("Word:", " ".join(guessed_word))
    guess = input("Enter a letter: ").lower()

    # Check if letter already guessed
    if guess in guessed_letters:
        print("You already guessed that letter.\n")
        continue

    guessed_letters.append(guess)

    # Check if guess is correct
    if guess in word:
        for i in range(len(word)):
            if word[i] == guess:
                guessed_word[i] = guess
        print("Correct!\n")
    else:
        attempts -= 1
        print("Wrong guess!")
        print("Remaining attempts:", attempts, "\n")

# Result
if "_" not in guessed_word:
    print("Congratulations! You guessed the word:", word)
else:
    print("Game Over!")
    print("The correct word was:", word)

