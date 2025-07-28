Here is a professional and complete `README.md` file for your **Catalog Placements Assignment** submission:

---

````markdown
# 📌 Catalog Placements Assignment - Shamir's Secret Sharing (Simplified)

## 🧠 Problem Statement

This assignment involves a simplified implementation of **Shamir's Secret Sharing**. We are given multiple `(x, y)` points of an unknown polynomial of degree `m`, and the task is to **reconstruct the constant term `c`** (i.e., `f(0)`) using **Lagrange interpolation**.

The points are encoded in different bases and provided via a JSON file. Some entries might be corrupted, so we compute the result from **all valid combinations of `k` points**, and return the value of `c` that appears most frequently.

---

## 📂 Files

- `main.cpp` – Core C++ program to read the JSON input and compute the secret.
- `json.hpp` – [nlohmann JSON](https://github.com/nlohmann/json) library used for parsing the JSON input.
- `testcase1.json` – First sample input JSON.
- `testcase2.json` – Second sample input JSON.
- `README.md` – This documentation.

---

## 📥 Input Format

Each JSON file contains:
```json
{
  "keys": {
    "n": 4,
    "k": 3
  },
  "1": {
    "base": "10",
    "value": "4"
  },
  "2": {
    "base": "2",
    "value": "111"
  },
  ...
}
````

* `n`: Number of total encoded points.
* `k`: Minimum number of points required (i.e., degree `m = k - 1`).
* Other keys represent the `x` values.

  * Each `value` is encoded in a specific base.
  * We convert `value` from its `base` to get `y`.

---

## ⚙️ How It Works

1. **Read JSON** input using `nlohmann/json`.
2. **Decode** each `value` using its `base` into a decimal integer.
3. **Generate all combinations** of `k` points.
4. For each combination, use **Lagrange interpolation** to compute `f(0)`:

   $$
   f(0) = \sum_{i=0}^{k-1} y_i \cdot \prod_{\substack{j=0 \\ j \ne i}}^{k-1} \frac{-x_j}{x_i - x_j}
   $$
5. **Track frequency** of each result. The most frequent value is returned as the **correct secret**.

---

## 🖥️ How to Compile and Run

Make sure you have a C++17 compatible compiler.

### 🔧 Compile

```bash
g++ -std=c++17 main.cpp -o secret_solver
```

### ▶️ Run

```bash
./secret_solver
```

Make sure `testcase1.json` and `testcase2.json` are in the same directory.

---

## 🧪 Sample Output

```bash
Secret (c): 3
Secret (c): 987654321
```

---

## 📚 Dependencies

* [nlohmann/json.hpp](https://github.com/nlohmann/json) – Single-header JSON parser.

---

## 📌 Notes

* If some points are corrupted, the correct value of `c` is recovered using **majority voting** over all valid `k`-combinations.
* The solution avoids solving the full polynomial and directly computes the **constant term** using **f(0)**.

---

## 🧑‍💻 Author

* **Name:** Bittu Gupta
* **Submission:** [Catalog Placements Assignment - Online](https://forms.office.com/r/gqG5rL6rLN)

---

```

---

Let me know if you’d like me to:
- Add an example test case content for `testcase1.json` and `testcase2.json`
- Help package the repo for GitHub
- Include screenshots or CLI output logs

Good luck with your submission! ✅
```
