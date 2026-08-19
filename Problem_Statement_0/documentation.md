# 📝 Solution Documentation

## Problem Understanding

**What the problem is asking:**
I needed to build a console-based Shipment/Cargo Management system in C++. The program has to take in a port's capacity, the number of containers, and the weight of each container — either typed in manually or read from an `input.txt` file (no external libraries allowed). Once the data is loaded, it generates a shipment report (total weight, average weight, heaviest/lightest container, a heavy/light classification, and whether the shipment fits the port's capacity), and then lets me interactively explore the data through a menu: sorting the containers, drawing a bar chart of their weights, saving the report to a file, searching for a container by weight, and finding the Kth heaviest container.

**Key concepts involved:**
- File I/O (`ifstream`/`ofstream`) for reading input and writing reports
- Recursion and divide-and-conquer (merge sort)
- Vectors and vector manipulation (slicing, pushing, indexing)
- Control flow with loops and `switch` statements for a menu-driven interface
- Basic aggregation (sum, min, max, average) done manually while reading input

**My approach:**
I split the program into small helper functions, each responsible for one job: `reportPrint` handles reading input and printing the initial report (and returns the key stats as a vector so I can reuse them later without recalculating), `mergeSort`/`mergeThem` handle sorting, `barChart`/`starPrinter` handle the visual bar chart, and `main` runs the menu loop that lets me repeatedly pick a feature (sort, chart, save, search, Kth heaviest, or start a new shipment) until I choose to quit.

---

## Conceptual Learning

### New Concepts I Discovered
- **Merge Sort:** A divide-and-conquer sorting algorithm — I split the vector in half recursively until I get down to pieces of size 0 or 1, then merge the sorted halves back together in order. I implemented this myself with `mergeSort` (the recursive splitting) and `mergeThem` (the merging step that compares elements from the left and right halves one at a time).
- **File I/O with `ifstream`/`ofstream`:** I learned how to read structured input from a file (`input.txt`) the same way I read from `cin`, just by swapping the stream object, and how to append output to a file (`report.txt`) using `ios::app` so previous reports aren't overwritten.
- **Returning multiple values via a vector:** Since C++ functions can only return one value directly, I packed several results (sum, max, min, and two status flags) into a single `vector<int>` returned from `reportPrint`, so I could reuse those stats later (e.g., when saving the report) without re-reading or recomputing them.
- **Menu-driven program structure with `switch`:** I used a `switch` statement inside a `while` loop keyed on the user's menu choice, which let me build an interactive, repeatable interface instead of a program that just runs once top to bottom.

### How I Applied These Concepts
I used merge sort whenever I needed an ordered view of the cargo weights — both for the "Sort" menu option and for finding the Kth heaviest container (where sorting first makes it easy to just index from the end of the sorted list). For input flexibility, I used an `if/else` on a mode flag (`p`) inside `reportPrint` so the exact same function handles both manual (`cin`) and file-based (`ifstream`) input without duplicating the reading and aggregation logic. The bar chart feature builds on simple loops: `starPrinter` prints a row of asterisks proportional to a container's weight (divided by 5 to keep the chart a reasonable width), and `barChart` calls it once per container.

### Real-World Connections
This mirrors real logistics and warehouse management software, where a system needs to ingest shipment data (from manual entry or an uploaded file/EDI feed), validate it against capacity constraints, and give operators quick summary stats and rankings. Merge sort itself shows up constantly in real systems — anywhere you need a stable, reliable O(n log n) sort, like ranking shipments by weight/priority or ordering records before a binary search. The pattern of separating "read and compute" from "display" (as I did with `reportPrint` returning stats to reuse later) is also a small-scale version of how real applications separate data processing from the UI layer.
