#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMenu();
int generateRandomNumber(int min, int max);
void playGuessingGame();
void bubbleSort(int arr[], int n);
void printArray(int arr[], int n);
int binarySearch(int arr[], int low, int high, int key);

int main() {
    int choice;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playGuessingGame();
                break;
            case 2:
                {
                    int n;
                    printf("Enter the number of elements in the array: ");
                    scanf("%d", &n);

                    int arr[n];
                    srand(time(NULL));

                    for (int i = 0; i < n; i++) {
                        arr[i] = generateRandomNumber(1, 100);
                    }

                    printf("Original array: ");
                    printArray(arr, n);

                    bubbleSort(arr, n);

                    printf("Sorted array: ");
                    printArray(arr, n);

                    int key;
                    printf("Enter the number to search: ");
                    scanf("%d", &key);

                    int index = binarySearch(arr, 0, n - 1, key);

                    if (index != -1) {
                        printf("Element found at index %d.\n", index);
                    } else {
                        printf("Element not found.\n");
                    }
                }
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 3);

    return 0;
}

void printMenu() {
    printf("\n*** Simple Game Menu ***\n");
    printf("1. Guessing Game\n");
    printf("2. Sorting and Searching\n");
    printf("3. Exit\n");
}

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void playGuessingGame() {
    srand(time(NULL));
    int numberToGuess = generateRandomNumber(1, 100);
    int guess, attempts = 0;

    printf("Welcome to the Guessing Game!\n");
    printf("Try to guess the number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess == numberToGuess) {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        } else if (guess < numberToGuess) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }

    } while (guess != numberToGuess);

}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            return binarySearch(arr, low, mid - 1, key);
        } else {
            return binarySearch(arr, mid + 1, high, key);
        }
    }

    return -1; 
}

