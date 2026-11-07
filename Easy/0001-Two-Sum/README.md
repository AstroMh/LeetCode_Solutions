# 1. Two Sum

- **Difficulty:** Easy
- **Problem:** [LeetCode — Two Sum](https://leetcode.com/problems/two-sum/)
- **Topics:** Arrays, Hash Maps
- **Language:** C++

## Problem summary

Given an integer array `nums` and an integer `target`, find the **indices** of two different elements whose values add up to `target`.

The problem guarantees exactly one valid pair. The same array element cannot be used twice.

Example:

```text
Input:  nums = [2, 7, 11, 15], target = 9
Output: [0, 1]
```

We return indices `0` and `1` because `2 + 7 = 9`.

## Approach 1 — Brute force

**File:** [`brute_force.cpp`](brute_force.cpp)

My first approach was to use two nested loops to check pairs of elements:

1. Use `i` to select the first element.
2. Start `j` at `i + 1` to avoid reusing an element or checking the same pair twice.
3. If `nums[i] + nums[j] == target`, return `{i, j}`.

**Time complexity:** `O(n²)` — in the worst case, the loops examine `n(n - 1) / 2` pairs.

**Auxiliary space complexity:** `O(1)` — no data structure grows with the input size (excluding the returned indices).

## Approach 2 — Hash map

**File:** [`solution.cpp`](solution.cpp)

The optimized approach uses an `unordered_map<int, int>` to store numbers already visited and their indices.

For each element:

1. Calculate the complement: `needed_number = target - nums[i]`.
2. Check whether the complement is already a key in the map.
3. If it is, return the stored index and the current index.
4. Otherwise, store the current number as the key and its index as the value.

The lookup must happen **before insertion**, so an element cannot match itself. This also works for duplicate values such as `[3, 3]` with target `6`.

**Average time complexity:** `O(n)` — one pass, with average `O(1)` hash-map lookup and insertion. Pathological hash collisions can degrade worst-case time.

**Auxiliary space complexity:** `O(n)` — the map can store up to `n` entries.

## Comparison

| Approach | Time | Auxiliary space | Idea |
|---|---|---|---|
| Brute force | `O(n²)` | `O(1)` | Check each pair |
| Hash map | `O(n)` average | `O(n)` | Look up the complement |

## What I learned

- `nums[i]` gives the **number**, while `i` is its **index**.
- A hash map has no automatic connection to the array. `myMap[nums[i]] = i` explicitly records the relationship **number → index**.
- `myMap.find(key) != myMap.end()` checks whether a key exists.
- `myMap[needed_number]` retrieves the index stored for the complement.
- Checking before insertion prevents the algorithm from using the same element twice.
- The optimized version trades additional memory for faster average lookup time.
- A function returning `vector<int>` must return a vector of indices, such as `{firstIndex, secondIndex}`, not a single integer.

## Test cases to review

| `nums` | `target` | Expected output |
|---|---:|---|
| `[2, 7, 11, 15]` | `9` | `[0, 1]` |
| `[3, 2, 4]` | `6` | `[1, 2]` |
| `[3, 3]` | `6` | `[0, 1]` |
| `[-3, 4, 3, 90]` | `0` | `[0, 2]` |
| `[0, 4, 3, 0]` | `0` | `[0, 3]` |

These are illustrative test cases, not a record of a LeetCode submission.
