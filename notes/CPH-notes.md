Competitive Programmer's Handbook Note's
===

* [Introduction](#introduction)
  * [Mathematics](#mathematics)
* [Time Complexity](#time-complexity) 
* [Sorting](#sorting) 
* [Data Structures](#data-structures) 

Introduction
---

### Mathematics
Important knowledge to knew/review when solving programming problems.

#### Sum Formulas

$\sum^n_{x = 1} x^k = 1^k + 2^k + 3^k + ... + n^k$

**Arithmetic progressions**

**Geometric progressions**

**Harmonic sum**

#### Set Theory

**Intersection:**
Items in both A and B.

$A = \{1, 2, 5\} $ \
$B = \{2, 4\} $ \
$A \cap B = \{2\} $ 

**Union:**
Items in A and B or both.

$A = \{3, 7\}$ \
$B = \{2, 3, 8\}$ \
$A \cup B = \{2, 3, 4, 8\}$

**Complement:** 
Elements that are not in A.

$U = \{1, ... , 10\}$ \
$A = \{1, 2, 3, 7\}$ \
$\overline{A} = \{4, 5, 6, 8, 9, 10\}$ 

**Difference:**
Elements that are in A but not in B.

$A = \{2, 3, 7, 8\}$ \
$B = \{2, 5, 8\}$ \
$A \backslash D = A \cap \overline{B} = \{2, 7\}$

**Subset:**
If each element of A belongs to S, we say that A is a subset of S. Denoted $A \subset S$.

#### Logic 

#### Functions

#### Logarithms

## Time Complexity 

## Sorting

## Data Structures

### Dynamic Arrays

### Set Structures
A set is a data structure that maintains a collection of elements. Basic operations include insertion, search, and removal.

#### Implementations

The structure `set` is based on a balanced binary tree and its operations work in `O(log n)` time.

The structure `unordered_set` uses hashing, and its operations work in `O(1)` time on average.

| Differences | set | unordered_set | 
|-------------|-----|---------------|
Ordering | increasing  order (by default) | no ordering
Implementation  | Self balancing BST (Like Red-Black Tree)  | Hash Table
search time     | log(n)              | O(1) -> Average O(n) -> Worst Case
Insertion time  | log(n) + Rebalance  | Same as search
Deletion time   | log(n) + Rebalance  | Same as search

[Reference](https://www.geeksforgeeks.org/set-vs-unordered_set-c-stl/)

#### Methods
```cpp
// initialize empty set
set<int> s;
set<int> t = {1, 2, 3};

// append element
s.insert(1); 
s.insert(2);
s.insert(3);
cout << s.count(3) << '\n'; // 1 
cout << s.count(4) << '\n'; // 0

// remove element
s.erase(3);
cout << s.count(3) << '\n'; // 0
```
Unlike vectors elements of sets cannot be accessed using [] notation. The

```cpp
set<int> s = {1, 2, 3, 4};

// size() method returns the length of the set
cout << s.size() << '\n'; // 4

// prints each element in the set
for(auto x : s){
  cout << x << '\n';
}
```

All elements of a set are *distinct*, meaning they only occur once. Therefore, the method `count` always returns either 0 or 1. The method `insert` never adds a duplicate element to the set.

```cpp
set<int> s;
s.insert(5);
s.insert(5);
s.insert(5);
cout << s.count(5) << '\n'; // 1
```

### Maps Structures

