# Selection Sort

Suppose you have a bunch of music on your computer.
For each artist, you have a play count.

You want to sort this list from most to least played, so that you can rank
your favorite artists. How can you do it?

One way is to use a sorting algorithm called selection sort.

Selection sort works by repeatedly finding the maximum element from the unsorted

part of the list and moving it to the start of the sorted part of the list.

Here's how you can use selection sort to sort your list of artists by play count:

1. Find the artist with the highest play count.

2. Swap that artist with the artist at the start of the list.

3. Move the boundary between the sorted and unsorted parts of the list one element to the right.

4. Repeat steps 1-3 until the entire list is sorted.

Here's an example of how selection sort works:

Suppose you have the following list of artists and play counts:

```cpp

std::vector<std::pair<std::string, int>> artists = {
    {"Taylor Swift", 100},
    {"Ed Sheeran", 50},
    {"Ariana Grande", 75},
    {"Drake", 200},
    {"Beyonce", 150}
};

```

After the first iteration of selection sort, the list will look like this:

```cpp

std::vector<std::pair<std::string, int>> artists = {
    {"Drake", 200},
    {"Ed Sheeran", 50},
    {"Ariana Grande", 75},
    {"Taylor Swift", 100},
    {"Beyonce", 150}
};

```

After the second iteration, the list will look like this:

```cpp

std::vector<std::pair<std::string, int>> artists = {
    {"Drake", 200},
    {"Beyonce", 150},
    {"Ariana Grande", 75},
    {"Taylor Swift", 100},
    {"Ed Sheeran", 50}
};

```

Etc

Selection sort is not the most efficient sorting algorithm, but it is easy to
understand and implement. It is a good choice for small lists or when you need
a simple sorting algorithm.

## Implementation


```cpp


