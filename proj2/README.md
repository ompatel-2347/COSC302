# Volsort Sorting Utility Benchmarks

This README contains benchmarks for the `volsort` sorting utility, comparing four different sorting modes across various input sizes.

## Benchmark Results

| Mode    | Size     | Elapsed Time (s) | Memory Usage (MB) |
|---------|----------|-------------------|-------------------|
| STL     | 10       | 0.00s             | 0.001             |
| STL     | 100      | 0.00s             | 0.002             |
| STL     | 1000     | 0.00s             | 0.002             |
| STL     | 10000    | 0.01s             | 0.002             |
| STL     | 100000   | 0.07s             | 0.117             |
| STL     | 1000000  | 0.72s             | 2.148             |
| STL     | 10000000 | 7.08              | 19.706            |
| QSORT   | 10       | 0.00s             | 0.009             |
| QSORT   | 100      | 0.00s             | 0.005             |
| QSORT   | 1000     | 0.00s             | 0.005             |
| QSORT   | 10000    | 0.01s             | 0.014             |
| QSORT   | 100000   | 0.07s             | 0.120             |
| QSORT   | 1000000  | 0.68              | 1.78              |
| QSORT   | 10000000 | 7.18s             | 18.11             |
| MERGE   | 10       | 0.00s             | 0.086             |
| MERGE   | 100      | 0.00s             | 0.004             |
| MERGE   | 1000     | 0.00s             | 0.004             |
| MERGE   | 10000    | 0.01s             | 0.014             |
| MERGE   | 100000   | 0.07s             | 0.115             |
| MERGE   | 1000000  | 0.71s             | 1.647             |
| MERGE   | 10000000 | 7.11s             | 19.346            |
| QUICK   | 10       | 0.00s             | 0.007             |
| QUICK   | 100      | 0.00s             | 0.003             |
| QUICK   | 1000     | 0.00s             | 0.005             |
| QUICK   | 10000    | 0.01s             | 0.01              |
| QUICK   | 100000   | 0.07s             | 0.118             |
| QUICK   | 1000000  | 0.69s             | 1.702             |
| QUICK   | 10000000 | 7.11s             | 17.740            |


## Key Findings

1. Performance Comparison:
   - All four methods (STL, Qsort, Merge, Quick) show similar time performance.
   - STL and Qsort are slightly more memory-efficient for smaller inputs.
   - Custom implementations (Merge, Quick) show comparable memory usage for larger inputs.

2. Theoretical vs. Actual Performance:
   - Results align with expected O(n log n) average-case time complexity.
   - Small variations likely due to implementation details and hardware factors.

3. Best Sorting Mode:
   - STL sort is recommended for its balance of performance, efficiency, and ease of use.
   - The other programs don't offer significant advantages over STL for most cases.

4. Trade-offs:
   - While Qsort shows slightly better memory usage for larger inputs, the difference is minimal and doesn't outweigh STL's other advantages.
   - The other programs (Merge and Quick) don't offer significant performance benefits over the standard library version, making the additional              implementation effort unnecessary for most use cases.  
