/*
** Turk sorting algorithm. 
**It manages the complete sorting flow:
**
** 1. Pushes initial elements from A to B (keeps at least 3 in A)
** 2. Iteratively pushes remaining elements using cost analysis
** 3. Sorts the final 3 elements in A using optimized rotations
** 4. Returns all elements from B to A in sorted order
** 5. Performs final rotation to place minimum at the top
**
** The algorithm minimizes operations by choosing the cheapest moves at each
** step, making it efficient for medium to large datasets.
*/