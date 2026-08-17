# Matrix as Linear Transformation

A matrix can be understood as a **linear transformation of space**.

For example, in 2D, a `2x2` matrix can transform vectors by:

- Stretching / squeezing.
- Rotating.
- Reflecting.
- Shearing.
- Or combining several of these effects.

But to understand why a matrix can do this, first we need to understand vectors as **linear combinations of basis vectors**.


## 1. Vectors as linear combinations of the basis vectors

In 2D, the standard basis is formed by the two unit vectors:

```text
    ⎡1⎤        ⎡0⎤
î = ⎣0⎦    ĵ = ⎣1⎦
```

Any 2D vector:

```text
    ⎡x⎤
v = ⎣y⎦
```

can be expressed as a linear combination of these two vectors:

```text
v = xî + yĵ

⎡x⎤     ⎡1⎤     ⎡0⎤
⎣y⎦ = x ⎣0⎦ + y ⎣1⎦
```

So the coordinates `(x, y)` can be interpreted as:

```text
x → how much of î we have
y → how much of ĵ we have
```

For example:

```text
⎡3⎤     ⎡1⎤     ⎡0⎤
⎣2⎦ = 3 ⎣0⎦ + 2 ⎣1⎦

     = 3î + 2ĵ
```

So `(3,2)` means:

> 3 times the first basis vector + 2 times the second basis vector.


## 2. Where matrices come into this

Now imagine that we want to transform the entire 2D space.

Instead of thinking directly about what happens to every possible vector, we can define what happens to the **basis vectors**.

For example, suppose we want:

```text
    ⎡1⎤       ⎡2⎤
î = ⎣0⎦   →   ⎣1⎦

    ⎡0⎤       ⎡1⎤
ĵ = ⎣1⎦   →   ⎣3⎦
```

So after the transformation:

```text
     ⎡2⎤
î' = ⎣1⎦

     ⎡1⎤
ĵ' = ⎣3⎦
```

A matrix simply stores these transformed basis vectors as its **columns**:

```text
      î'  ĵ'
       ↓   ↓

    ⎡ 2   1 ⎤
A = ⎣ 1   3 ⎦
```

So an important way of understanding a matrix is:

> **The columns of a transformation matrix tell us where the basis vectors end up after applying the transformation.**


## 3. Why Matrix * Vector works

Suppose we have:

```text
    ⎡3⎤
v = ⎣2⎦
```

We already know that this means:

```text
v = 3î + 2ĵ
```

If our matrix transforms the basis into:

```text
     ⎡2⎤
î' = ⎣1⎦

     ⎡1⎤
ĵ' = ⎣3⎦
```

then the transformed vector becomes:

```text
v' = 3î' + 2ĵ'
```

Therefore:

```text
     ⎡2⎤     ⎡1⎤
v' = 3⎣1⎦ + 2⎣3⎦

     ⎡6⎤   ⎡2⎤
   = ⎣3⎦ + ⎣6⎦

     ⎡8⎤
   = ⎣9⎦
```

And matrix multiplication does EXACTLY this:

```text
⎡2 1⎤ ⎡3⎤   ⎡8⎤
⎣1 3⎦ ⎣2⎦ = ⎣9⎦
```

So:

```text
          ⎡2⎤     ⎡1⎤
A * v = 3 ⎣1⎦ + 2 ⎣3⎦
          ↑         ↑
       column 0  column 1
```

The components of the vector `(3,2)` are used as the coefficients of the
linear combination of the matrix columns.

This is why the columns of a matrix can be interpreted as vectors.


## 4. The identity matrix

The identity matrix is:

```text
    ⎡1 0⎤
I = ⎣0 1⎦
```

Its columns are exactly the original basis vectors:

```text
column 0 = î = (1,0)
column 1 = ĵ = (0,1)
```

So it says:

```text
î → î
ĵ → ĵ
```

Nothing happens to the basis.

Therefore nothing happens to any vector:

```text
⎡1 0⎤ ⎡x⎤   ⎡x⎤
⎣0 1⎦ ⎣y⎦ = ⎣y⎦
```

This makes sense because:

```text
v = xî + yĵ
```

and if neither `î` nor `ĵ` changes, neither does `v`.


## 5. Determinant: what happens to the space?

Now the determinant becomes easier to interpret.

Take a matrix:

```text
    ⎡a b⎤
A = ⎣c d⎦
```

Its columns are the transformed basis vectors:

```text
     ⎡a⎤
î' = ⎣c⎦

     ⎡b⎤
ĵ' = ⎣d⎦
```

Before the transformation, the standard basis vectors:

```text
î = (1,0)
ĵ = (0,1)
```

form a square of area `1`.

After the transformation, `î'` and `ĵ'` generally form a parallelogram:

```text
          ĵ'
         /
        /────────•
       /        /
      /        /
     •────────•
    0    î'
```

The determinant is:

```text
det(A) = ad - bc
```

and:

```text
|det(A)|
```

is the area of this parallelogram.

Therefore the determinant tells us the **area scaling factor of the
transformation**.

Examples:

```text
|det(A)| = 1   → areas keep the same size
|det(A)| = 2   → areas become twice as large
|det(A)| = 0.5 → areas become half as large
|det(A)| = 0   → areas collapse to zero
```


## 6. The sign of the determinant

The absolute value tells us the area scaling, but the sign gives us
information about the **orientation**.

```text
det(A) > 0 → orientation is preserved
det(A) < 0 → orientation is reversed
```

For example:

```text
    ⎡-1 0⎤
A = ⎣ 0 1⎦
```

Its columns tell us:

```text
î → (-1,0)
ĵ → ( 0,1)
```

So the X direction has been reflected:

```text
Before:             After:

0 ───────→ î        î' ←─────── 0
```

Its determinant is:

```text
det(A) = (-1)(1) - (0)(0)
       = -1
```

Therefore:

```text
|det(A)| = 1 → area size is unchanged
det(A) < 0   → orientation has been reversed
```


## 7. What if determinant = 0?

If:

```text
det(A) = 0
```

the two transformed basis vectors no longer form a parallelogram with area.

For example:

```text
    ⎡1 2⎤
A = ⎣2 4⎦
```

Its columns are:

```text
î' = (1,2)
ĵ' = (2,4)
```

But:

```text
ĵ' = 2î'
```

so both transformed basis vectors lie on the same line.

Instead of spanning a 2D area, they collapse into one direction:

```text
2D space
   ↓ transformation
──────────────→
1D line
```

Therefore:

```text
det(A) = 0
```

means that the transformation has **collapsed at least one dimension**.

Information has been lost, which is why the transformation cannot be
completely undone and the matrix has no inverse.


## Core intuition

The whole idea can be summarized as:

```text
VECTOR
    ↓
(x,y) means:
xî + yĵ


MATRIX
    ↓
stores where î and ĵ are transformed:

      new î   new ĵ
        ↓       ↓
      ⎡ a       b ⎤
      ⎣ c       d ⎦


MATRIX * VECTOR
    ↓
uses x and y to combine those new basis vectors:

A*v = x(new î) + y(new ĵ)


DETERMINANT
    ↓
tells us what happened to the area formed by
those transformed basis vectors.
```

So a useful mental model is:

> **A vector stores how much of each basis direction we have.**
>
> **A matrix stores where those basis directions are sent by a linear transformation.**
>
> **Matrix × vector reconstructs the vector using those transformed basis directions.**
>
> **The determinant tells us how that transformation changes oriented area.**