# Rush01 Backtracking Skeleton

Your project defines the clue structure as `t_clues` (plural), so the intended
function signatures are:

```c
bool	is_valid_placement(t_board *board, int row, int col, int value);
bool	are_all_clues_satisfied(t_board *board, t_clues *clues);
bool	backtrack(t_board *board, t_clues *clues, int position);
```

The examples below are pseudocode. They describe the logic, but they are not
intended to compile until you translate them into C.

## 1. Validate one placement

Responsibility: make sure `value` does not already appear elsewhere in the
selected row or column.

```text
bool is_valid_placement(board, row, col, value)
{
    index = 0

    while (index < SIZE)
    {
        if (index is not col
            AND board[row][index] equals value)
            return false

        if (index is not row
            AND board[index][col] equals value)
            return false

        index++
    }

    return true
}
```

Ignoring the current `row, col` position lets this function validate both:

- A new candidate for an empty cell.
- A number previously placed by the prefill logic.

## 2. Count visible towers

Responsibility: count how many towers can be seen from one direction.

```text
highest = 0
visible = 0

for each tower, starting from the viewing direction
{
    if (tower > highest)
    {
        highest = tower
        visible++
    }
}

return visible
```

For example, looking from the left at:

```text
2 1 4 3
```

The visible towers are `2` and `4`, so the count is `2`.

## 3. Validate all clues

Responsibility: compare the completed board against all 16 clues.

```text
bool are_all_clues_satisfied(board, clues)
{
    index = 0

    while (index < SIZE)
    {
        top_count = count column[index] from top
        bottom_count = count column[index] from bottom
        left_count = count row[index] from left
        right_count = count row[index] from right

        if (top_count does not equal clues->top[index])
            return false

        if (bottom_count does not equal clues->bottom[index])
            return false

        if (left_count does not equal clues->left[index])
            return false

        if (right_count does not equal clues->right[index])
            return false

        index++
    }

    return true
}
```

This function should only inspect the board. It should not place numbers,
erase numbers, print the board, or print an error.

## 4. Backtracking

Responsibility: try possible values, move forward recursively, and undo choices
that lead to a dead end.

```text
bool backtrack(board, clues, position)
{
    if (position equals SIZE * SIZE)
        return are_all_clues_satisfied(board, clues)

    row = position / SIZE
    col = position % SIZE

    if (board[row][col] is not zero)
    {
        if (is_valid_placement(
                board, row, col, board[row][col]) is false)
            return false

        return backtrack(board, clues, position + 1)
    }

    value = 1

    while (value <= SIZE)
    {
        if (is_valid_placement(board, row, col, value))
        {
            board[row][col] = value

            if (backtrack(board, clues, position + 1))
                return true

            board[row][col] = 0
        }

        value++
    }

    return false
}
```

The prefilled cells are protected because a nonzero cell immediately moves to
the next position. Only cells that were empty enter the try-and-undo section.

## 5. Connect the solver to `main`

Once the three functions are implemented, the intended control flow is:

```text
validate input
populate clues
initialize board
apply prefill deductions

if prefill deductions fail
    print Error

if backtracking fails
    print Error
else
    print the solved board
```

In C, the final backtracking decision will have this shape:

```c
if (!backtrack(&board, &clues, 0))
	return (error_return_one());
print_board(&board);
```

## Suggested implementation order

1. Implement and test `is_valid_placement`.
2. Implement one visibility-counting helper.
3. Test that helper in both forward and reverse directions.
4. Implement `are_all_clues_satisfied`.
5. Implement `backtrack`.
6. Connect `backtrack` to `main`.

First exercise: for `position == 11` and `SIZE == 4`, calculate the `row` and
`col` values before writing the recursive function.
