# C Lab 3: Structs

This lab practiced using structs in C to group related data together, and working with them both on the stack and on the heap.

## What I Did

**Video games**

- Made a `video_game` struct with a name, release year, and price.
- Created one on the stack and one on the heap with `malloc`, and set the heap one's values using both the `(*pointer).` and `->` notations.
- Wrote `halfOff`, which takes a video game by reference and cuts its price in half.

**Books**

- Made a `book` struct with a title, author, current page, and total pages.
- Wrote `make_book`, which builds a book on the heap with `malloc` from the values passed in and returns a pointer to it.
- Wrote functions to work with a book:
  - `print_book` prints every property.
  - `turn_a_page` moves forward one page without going past the last page.
  - `flip_pages` moves forward or back by a given number of pages, staying between zero and the last page.
  - `get_pages_remaining` returns how many pages are left.
  - `start_over` resets the book to page zero.
- Created *Dune* on the heap and *House of Leaves* on the stack, then called every function on both. I flipped forward and backward by large amounts to check that the page count stays within its limits, and printed the results along the way.
