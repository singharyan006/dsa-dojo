# Arrays
Arrays are the data structures used to store multiple elements and used by several algorithms which is to be learnt... lessgooo🥳
--- 

## Algorithms

### 1. Bubble Sort
- Bubble Sort is an algorithm that sorts an array from the lowest value to the highest value.
- takes one value at a time and then compares it throughout the array putting the bigger one on the right ( reason for using nested loops ). 
- if n is the number of elements in an array then loop runs n-1 times. 
- refer : [Bubble Sort](https://www.w3schools.com/dsa/dsa_algo_bubblesort.php) for better understanding. 
- disadvantage - if the array becomes sorted after before n-1 interations then also as per the conventional alogirthm flow the loop will run for n-1 times. So that needs to be fixed.

---

### 2. Improved Bubble Sort
- The problem with this sorting is what if the arrays get sorted in the first run, then why waste time running all the rest iterations. So better keep a track if there's no swapping in one complete iteration break the damn loop and enjoy your coding...
- Refer [Code](dsa-dojo/practice/arrays/improved_bubble_sort.c) for the proper understanding.