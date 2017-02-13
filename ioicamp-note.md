# MISC
## Wifi
- SSID: CSIE_Guest
- id: ioicamp
- password: AY7G51N8

## Team
Username / Password: bh56soydwJeffrey


# DAY 1
## Introduction
### judge
- CF
- POI
- AtCoder

### common bug
- initialization
    - init function (static)
- array size
    - memset too much -> TLE
- input end condition
- output format
- no return (frequently wrong on -O2)
- typo, shadowing
- buffer overflow
    - assert

### undefined behaviour
- a[i] = ++i;
- f(++a, a);
- overflow
- access out of bound
- uninitialized scalar
- do NOT use while(1) or for(;;)
  => use while(flag) instead

## DP optimization
- simple queue
- convex hull
- convex/concave

# DAY 2
## Math
### extend Euclid's algorithm
want: \`ax + by = 1\`
known: \`bx' + cy' = 1\`

\`a mod b\`
\`=> a = kb + c\` \`(k = |\_\_a/b\_\_|)\`
\`=> c = a - kb\`

\`bx' + cy' = 1\`
\`=> bx' + (a-kb)y' = 1\`
\`=> ay' + b(x'-k) = 1\`
\`=>\`
$$
\left\\{
\begin{array}{l}
x = y' \\\\
y = x' - \left\lfloor\dfrac{a}{b}\right\rfloor
\end{array}
\right.
$$

## Competition 2
- A: DFS
- B: Centroid Split / Tree D&C
- C:
    \`gcd(N, C) = D\`
    \`=> gcd(N/D, C/D) = 1\`
    \`=>\` we know \`D|C\` and then count how many match the requirement
- D:
- E: two solution
    - toposort
    - find inverse adjacency matrix
- F:
    - dp(n, k): for first n objects, put k cards, the max power
    - dp(n, k) = max(dp(n-1, k-1)+a[n-1]+3, dp(n, k-1)+a[n-1])
- G: Centroid Split / Tree D&C
    - record on vertex: in distance 'd' will be coloured
    - if one is coloured, some around will be covered
    - decreasing queue
    - like pB

# DAY 3
## Competition 3
- A: no comment
- B: count nodes on suffix Tree
    - suffix array
    - LCP array
- C: AC automaton
- D: LCA
    - two path cross \`<=>\` one's LCA is on the other path
- E: longest common palindrome substring
    - binary search length of substring
    - hash
    - check if substring is palindrome
    - do for odd and even
- F: dp(k, n): n people, k part
- G: WTF
- H: dp(n):
- I: connect leaves so that there's no bridge
    - let \`n = \"number of leaves\"\`
    - \`ans = (n + (n mod 2)) / 2\`

# DAY 5
## Competition 5
...
