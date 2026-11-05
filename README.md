# Video Catalog Manager (C++ Console App)

A console program written in C++ for an Object-Oriented Programming course (Tec de Monterrey, 2025). It loads a catalog of 50 movies and series episodes from a text file and lets the user rate titles and filter the catalog.

## Features

1. Show the full catalog with each title's average rating (`SC` = no rating yet).
2. Rate a title (1–5) by its ID; the average is updated incrementally.
3. List movies, episodes, or both with a minimum average rating.
4. List movies, episodes, or both from a given genre.

## OOP design

- `VideoMedia` — abstract base class (pure virtual `print()`), holds shared data (id, name, length, genre, ratings) with `protected` attributes.
- `Movie` and `Serie` — subclasses that override `print()`; `Serie` adds the series name and chapter number.
- The catalog is a `vector<VideoMedia*>` of heap-allocated objects, so calls to `print()` resolve polymorphically; objects are freed with `delete` on exit.
- `operator<<` is overloaded to print any `VideoMedia`.
- See [`UML Class Diagram.pdf`](UML%20Class%20Diagram.pdf).

## Data format (`videos.txt`)

One title per line, comma-separated:

```
p,<id>,<name>,<length>,<genre>                          # movie
c,<id>,<name>,<length>,<genre>,<series name>,<chapter>  # series episode
```

`videos.txt` is opened with a relative path, so run the program from the folder that contains it.

## Build and run

```bash
g++ -std=c++11 *.cpp -o escine
./escine
```

## Known limitations

- Non-numeric input at the menu is not validated.
- A malformed line in `videos.txt` is not handled (`stoi` can throw).
- Rating an ID that doesn't exist fails silently.
- Ratings are kept in memory only and reset on every run.
