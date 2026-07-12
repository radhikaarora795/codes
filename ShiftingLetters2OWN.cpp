#include <iostream>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> diff(n,0);

        for(auto &v:shifts){
            int l=v[0];
            int r=v[1];
            int val;

            if(v[2] == 1){
                val=1;
            }
            else{
                val=-1;
            }

            for(int i=l;i<=r;i++){
                diff[i]=diff[i]+val;
            }

        }

        int shift=0;

        for(int i=0;i<n;i++){
            // shift+=diff[i];
            shift=diff[i];

            int pos=s[i]-'a';

            pos=(pos+shift)%26;

            if(pos<0){
                pos+=26;
            }

            s[i]='a'+pos;
        }

        return s;
    }
};

class Solution2 {
public:
    // do it using prefix sum
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> diff(n+1,0);    // number of shifts to perform for each element

        for(auto &v:shifts){
            int l=v[0];
            int r=v[1];
            int val;

            if(v[2] == 1){
                val=1;
            }
            else{
                val=-1;
            }

            diff[l]+=val;

            if(r+1<n){
                diff[r+1]-=val;
            }

        }

        int shift=0;

        for(int i=0;i<n;i++){
            shift+=diff[i];

            int pos=s[i]-'a';

            pos=(pos+shift)%26;

            if(pos<0){
                pos+=26;
            }

            s[i]='a'+pos;
        }

        return s;
    }
};

int main() {
    
    return 0;
}

/*

### Code Explanation (Short Summary)

```cpp
vector<int> diff(n + 1, 0);
```

Creates a difference array to store range updates efficiently.

---

### Step 1: Mark Range Updates

```cpp
for(auto &v : shifts) {
    int l = v[0];
    int r = v[1];
    int val = (v[2] == 1) ? 1 : -1;

    diff[l] += val;

    if(r + 1 < n)
        diff[r + 1] -= val;
}
```

* Forward shift (`direction = 1`) → `+1`
* Backward shift (`direction = 0`) → `-1`
* Instead of updating every index from `l` to `r`, we:

  * Start the effect at `l`
  * Stop the effect after `r`

This makes each operation **O(1)**.

---

### Step 2: Compute Net Shift for Each Position

```cpp
int shift = 0;

for(int i = 0; i < n; i++) {
    shift += diff[i];
```

Taking the prefix sum gives the total shift that should be applied to index `i`.

---

### Step 3: Convert Character to Position

```cpp
int pos = s[i] - 'a';
```

Examples:

```text
a → 0
b → 1
z → 25
```

---

### Step 4: Apply Shift with Wrap Around

```cpp
pos = (pos + shift) % 26;

if(pos < 0)
    pos += 26;
```

Examples:

```text
y + 3 = b
a - 2 = y
```

Modulo handles circular movement in the alphabet.

---

### Step 5: Convert Back to Character

```cpp
s[i] = 'a' + pos;
```

Examples:

```text
0 → a
1 → b
25 → z
```

---

### Overall Idea

Instead of shifting every character for every operation (**O(n × m)**),

1. Store range effects in `diff`.
2. Use prefix sums to get the final shift at each index.
3. Apply the shift once per character.

### Complexity

* Building difference array: **O(m)**
* Prefix sum + string update: **O(n)**
* Total: **O(n + m)** ✅

This is why the solution passes LeetCode 2381.


*/


/*

### Why `diff` size is `n + 1`?

For a range update `[l, r]`, we use:

```cpp
diff[l] += val;      // start effect
diff[r + 1] -= val;  // stop effect
```

If the range ends at the last index (`r = n - 1`), then:

```cpp
r + 1 = n
```

which is outside a size-`n` array.

Therefore we create:

```cpp
vector<int> diff(n + 1, 0);
```

so index `n` exists and `diff[r + 1]` is always valid.

### Example

For:

```cpp
n = 5
range = [1,4]
```

we do:

```cpp
diff[1] += 1;
diff[5] -= 1;
```

Thus `diff[5]` requires an extra position.

### Key Point

The extra element is a **sentinel** used to mark where a range's effect stops. It simplifies the code and avoids boundary checks.


*/